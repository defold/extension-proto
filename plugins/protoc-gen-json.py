#!/usr/bin/env python

import sys
import itertools
import json
import re

from google.protobuf.compiler import plugin_pb2 as plugin
from google.protobuf.descriptor_pb2 import DescriptorProto, EnumDescriptorProto, FieldDescriptorProto
from google.protobuf.type_pb2 import Field


CPP_KEYWORDS = [ "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "asm", "dynamic_cast", "namespace", "reinterpret_cast", "bool", "explicit", "new", "static_cast", "false", "catch", "operator", "template", "friend", "private", "class", "this", "inline", "public", "throw", "const_cast", "delete", "mutable", "protected", "true", "try", "typeid", "typename", "using", "virtual", "wchar_t" ]

def log(*args):
    print(*args, file=sys.stderr)

# https://github.com/protocolbuffers/protobuf/blob/main/src/google/protobuf/descriptor.proto
def parse_proto_file(proto_file):
    log("\nParsing file ",proto_file.name, " with package ", proto_file.package)
    out_items = []

    def _parse(package, items, parent = None):
        for item in items:
            if isinstance(item, DescriptorProto):
                log("  DescriptorProto", item.name)
                out_items.append({ "item": item, "package": package, "parent": parent })
                if item.enum_type:
                    _parse(package, item.enum_type, item)
                if item.nested_type:
                    _parse(package + "." + item.name, item.nested_type)

            elif isinstance(item, EnumDescriptorProto):
                log("  EnumDescriptorProto", item.name)
                out_items.append({ "item": item, "package": package, "parent": parent })

    _parse(proto_file.package, proto_file.enum_type)
    _parse(proto_file.package, proto_file.message_type)
    return out_items


def capitalize_first_letter_only(input):
  return re.sub('([a-zA-Z])', lambda x: x.groups()[0].upper(), input, 1)

def capitalize_first_letter_only(input):
  return re.sub('([a-zA-Z])', lambda x: x.groups()[0].upper(), input, 1)

def camel_to_snake(s):
    words = re.findall(r'[A-Z]*[a-z\d]*', s)
    while('' in words):
        words.remove('')
    return '_'.join(map(str.lower, words))

def name_to_cpp(name):
    return (name + "_") if name in CPP_KEYWORDS else name

def type_name_to_lua(type_name):
    if type_name.startswith("."):
        type_name = type_name[1:]

    type_name_parts = []
    for name in type_name.split("."):
        name = camel_to_snake(name)
        type_name_parts.append(name)
    return "__".join(type_name_parts)

def type_name_to_cpp(type_name, lower=False, upper=False):
    if type_name.startswith("."):
        type_name = type_name[1:]

    type_name_parts = []
    for name in type_name.split("."):
        if lower:
            name = camel_to_snake(name)
        elif upper:
            name = camel_to_snake(name).upper()
        else:
            # dmInputDDF GamepadModifier_t -> DmInputDDF__GamepadModifierT
            name_words = name.split('_')
            name = name_words[0] + ''.join(capitalize_first_letter_only(n) for n in name_words[1:])
            name = name[0].upper() + name[1:]
        type_name_parts.append(name)
    return "__".join(type_name_parts)

def parse_field(f):
    field_type = int(f.type)
    field =  {
        "name": f.name,
        "name_cpp": name_to_cpp(f.name),
        "name_cpp_lower": name_to_cpp(f.name.lower()),
        "name_cpp_upper": name_to_cpp(f.name.lower()).upper(),
        "type": field_type,
        "repeated": (f.label == FieldDescriptorProto.LABEL_REPEATED),
        "required": (f.label == FieldDescriptorProto.LABEL_REQUIRED),
        "optional": (f.label == FieldDescriptorProto.LABEL_OPTIONAL),
    }

    if f.HasField('oneof_index'):
        field["oneof_index"] = f.oneof_index

    # https://developers.google.com/protocol-buffers/docs/proto#scalar
    if field_type == Field.TYPE_DOUBLE:
        field["type_lua"] = "number"
        field["type_cpp"] = "double"
        field["type_cpp_lower"] = "double"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_FLOAT:
        field["type_lua"] = "number"
        field["type_cpp"] = "float"
        field["type_cpp_lower"] = "float"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_INT64 or field_type == Field.TYPE_SFIXED64 or field_type == Field.TYPE_SINT64:
        field["type_lua"] = "number"
        field["type_cpp"] = "int64_t"
        field["type_cpp_lower"] = "int64_t"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_INT32 or field_type == Field.TYPE_SFIXED32 or field_type == Field.TYPE_SINT32:
        field["type_lua"] = "number"
        field["type_cpp"] = "int32_t"
        field["type_cpp_lower"] = "int32_t"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_FIXED64 or field_type == Field.TYPE_UINT64:
        field["type_lua"] = "number"
        field["type_cpp"] = "uint64_t"
        field["type_cpp_lower"] = "uint64_t"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_FIXED32 or field_type == Field.TYPE_UINT32:
        field["type_lua"] = "number"
        field["type_cpp"] = "uint32_t"
        field["type_cpp_lower"] = "uint32_t"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_BOOL:
        field["type_lua"] = "boolean"
        field["type_cpp"] = "protobuf_c_boolean"
        field["type_cpp_lower"] = "protobuf_c_boolean"
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_ENUM:
        field["type_lua"] = "number"
        field["type_cpp"] = type_name_to_cpp(f.type_name)
        field["type_cpp_lower"] = type_name_to_cpp(f.type_name, lower=True)
        field["type_is_enum"] = True
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = True
    elif field_type == Field.TYPE_STRING:
        field["type_lua"] = "string"
        field["type_cpp"] = "char*"
        field["type_cpp_lower"] = "char*"
        field["type_is_string"] = True
        field["type_is_allocated"] = True
        field["type_is_primitive"] = False
    elif field_type == Field.TYPE_BYTES:
        field["type_lua"] = "ProtobufCBinaryData"
        field["type_cpp"] = "ProtobufCBinaryData"
        field["type_cpp_lower"] = "protobufcbinarydata"
        field["type_is_bytes"] = True
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = False
    elif field_type == Field.TYPE_MESSAGE:
        field["type_lua"] = type_name_to_lua(f.type_name)
        field["type_cpp"] = type_name_to_cpp(f.type_name) + "*"
        field["type_cpp_lower"] = type_name_to_cpp(f.type_name, lower=True)
        field["type_is_message"] = True
        field["type_is_allocated"] = field["repeated"]
        field["type_is_primitive"] = False
    elif field_type == Field.TYPE_GROUP:
        raise TypeError("Unsupported type 'group'")
    else:
        raise TypeError("Unknown field type!")

    return field


def generate_code(request, response):
    messages = []
    enums = []
    files = []
    output = {
        "messages": messages,
        "enums": enums,
        "files": files,
    }
    for proto_file in request.proto_file:
        file = {
            "filename": proto_file.name,
            "filename_h": proto_file.name.replace(".proto", ".pb-c.h")
        }
        files.append(file)

        for o in parse_proto_file(proto_file):
            item = o.get("item")
            package = o.get("package") or ''
            parent = o.get("parent")
            if package.startswith("google.protobuf"): continue

            item_name = item.name if hasattr(item, "name") else "?"
            parent_name = parent.name if parent else None
            item_type_name = package + "." + (parent_name + "." if parent_name else "") + item_name

            # proto_file.syntax will not be set if proto2
            is_proto2_syntax = proto_file.syntax != "proto3"
            
            data = {
                "is_proto2_syntax": is_proto2_syntax,
                "package": package,
                "package_lower": package.lower(),
                "nested": '.' in package,
                "filename": proto_file.name,
                "name": item_name,
                "name_cpp": name_to_cpp(item_name),
                "name_cpp_lower": name_to_cpp(item_name).lower(),
                "name_lower": item_name.lower(),
                "name_upper": item_name.upper(),
                "type_lua":  type_name_to_lua(item_type_name),
                "type_cpp":  type_name_to_cpp(item_type_name),
                "type_cpp_lower": type_name_to_cpp(item_type_name, lower=True),
                "type_cpp_upper":  type_name_to_cpp(item_type_name, upper=True),
                "parent": parent_name,
                "parent_lower": parent_name.lower() if parent_name else None,
                "parent_upper": parent_name.upper() if parent_name else None,
                "google": proto_file.name.startswith("google")
            }

            if isinstance(item, DescriptorProto):
                is_map_entry = item.options.map_entry
                fields = []
                data.update({ "fields": fields })
                data["is_map_entry"] = is_map_entry
                messages.append(data)

                if is_map_entry:
                    for f in item.field:
                        if f.name == "key":
                            data["key"] = parse_field(f)
                        elif f.name == "value":
                            data["value"] = parse_field(f)
                else:
                    for f in item.field:
                        field = parse_field(f)
                        if field.get("oneof_index") is not None:
                            oneof_decl = item.oneof_decl
                            oneof_index = field["oneof_index"]
                            oneof_name = oneof_decl[oneof_index].name
                            field["oneof"] = oneof_name.lower()
                            field["oneof_enum"] = data["type_cpp_upper"] + "__" + oneof_name.upper() + "_" + camel_to_snake(field["name_cpp"]).upper()
                        fields.append(field)

            elif isinstance(item, EnumDescriptorProto):
                values = []
                data.update({ "values": values })
                enums.append(data)
                for v in item.value:
                    value = {
                        "name": v.name,
                        "value": v.number
                    }
                    values.append(value)

    # find message fields of type map
    # we do this by first searching for any map entry messages and
    # then by searching for fields which use the map entry as field type
    for message in messages:
        if not message.get("is_map_entry"):
            continue
        for m in messages:
            for f in m.get("fields"):
                if f.get("type_cpp").replace("*", "") == message.get("type_cpp"):
                    f["type_is_map"] = True


    f = response.file.add()
    f.name = "proto.json"
    f.content = json.dumps(output, indent=4)


if __name__ == '__main__':
    # Read request message from stdin
    data = sys.stdin.buffer.read()

    # Parse request
    request = plugin.CodeGeneratorRequest()
    request.ParseFromString(data)

    # Create response
    response = plugin.CodeGeneratorResponse()

    # Generate code
    generate_code(request, response)

    # Serialise response message
    output = response.SerializeToString()

    # Write to stdout
    sys.stdout.buffer.write(output)