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


def traverse(proto_file):

    def _traverse(package, items):
        for item in items:
            yield item, package, None

            if isinstance(item, DescriptorProto):
                for enum in item.enum_type:
                    yield enum, package, item

                if item.nested_type:
                    nested_package = package + "." + item.name
                    for nested_item in item.nested_type:
                        yield nested_item, nested_package, None

    return itertools.chain(
        _traverse(proto_file.package, proto_file.enum_type),
        _traverse(proto_file.package, proto_file.message_type),
    )

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
            name = name_words[0] + ''.join(n.title() for n in name_words[1:])
            name = name[0].upper() + name[1:]
        type_name_parts.append(name)
    return "__".join(type_name_parts)


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
        # log(proto_file.name)
        file = {
            "filename": proto_file.name,
            "filename_h": proto_file.name.replace(".proto", ".pb-c.h")
        }
        files.append(file)

        for item, package, parent in traverse(proto_file):
            package = package or ''
            if package.startswith("google.protobuf"): continue

            item_name = item.name if hasattr(item, "name") else "?"
            parent_name = parent.name if parent else None
            item_type_name = package + "." + (parent_name + "." if parent_name else "") + item_name
            data = {
                "package": package,
                "package_lower": package.lower(),
                "nested": '.' in package,
                "filename": proto_file.name,
                "name": item_name,
                "name_cpp": name_to_cpp(item_name),
                "name_cpp_lower": name_to_cpp(item_name).lower(),
                "name_lower": item_name.lower(),
                "name_upper": item_name.upper(),
                "type_cpp":  type_name_to_cpp(item_type_name),
                "type_cpp_lower": type_name_to_cpp(item_type_name, lower=True),
                "type_cpp_upper":  type_name_to_cpp(item_type_name, upper=True),
                "parent": parent_name,
                "parent_lower": parent_name.lower() if parent_name else None,
                "parent_upper": parent_name.upper() if parent_name else None,
                "google": proto_file.name.startswith("google")
            }

            if isinstance(item, DescriptorProto):
                properties = []
                data.update({ "properties": properties })
                messages.append(data)
                for f in item.field:
                    property_type = int(f.type)
                    property =  {
                        "name": f.name,
                        "name_cpp": name_to_cpp(f.name),
                        "name_cpp_lower": name_to_cpp(f.name).lower(),
                        "type": property_type,
                        "repeated": (f.label == FieldDescriptorProto.LABEL_REPEATED),
                        "required": (f.label == FieldDescriptorProto.LABEL_REQUIRED),
                        "optional": (f.label == FieldDescriptorProto.LABEL_OPTIONAL),
                    }

                    # https://developers.google.com/protocol-buffers/docs/proto#scalar
                    if property_type == Field.TYPE_DOUBLE:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "double"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_FLOAT:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "float"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_INT64 or property_type == Field.TYPE_SFIXED64 or property_type == Field.TYPE_SINT64:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "int64_t"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_INT32 or property_type == Field.TYPE_SFIXED32 or property_type == Field.TYPE_SINT32:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "int32_t"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_FIXED64 or property_type == Field.TYPE_UINT64:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "uint64_t"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_FIXED32 or property_type == Field.TYPE_UINT32:
                        property["type_lua"] = "number"
                        property["type_cpp"] = "uint32_t"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_BOOL:
                        property["type_lua"] = "boolean"
                        property["type_cpp"] = "bool"
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_ENUM:
                        property["type_lua"] = "number"
                        property["type_cpp"] = type_name_to_cpp(f.type_name)
                        property["type_is_enum"] = True
                        property["type_is_primitive"] = True
                    elif property_type == Field.TYPE_STRING:
                        property["type_lua"] = "string"
                        property["type_cpp"] = "char*"
                        property["type_is_string"] = True
                        property["type_is_primitive"] = False
                    elif property_type == Field.TYPE_BYTES:
                        property["type_lua"] = "ProtobufCBinaryData"
                        property["type_cpp"] = "ProtobufCBinaryData"
                        property["type_is_bytes"] = True
                        property["type_is_primitive"] = False
                    elif property_type == Field.TYPE_MESSAGE:
                        property["type_lua"] = type_name_to_lua(f.type_name)
                        property["type_cpp"] = type_name_to_cpp(f.type_name) + "*"
                        property["type_is_message"] = True
                        property["type_is_primitive"] = False
                    elif property_type == Field.TYPE_GROUP:
                        print("Unsupported type 'group'")
                    else:
                        print("Unknown property type!")
                    properties.append(property)

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