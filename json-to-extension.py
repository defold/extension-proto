#!/usr/bin/env python

import pystache
import json
import codecs
import html

from google.protobuf.type_pb2 import Field


def parse_files(files):
    for file in files:
        file["filename_h"] = file["filename"].replace(".proto", ".pb-c.h")

def parse_messages(messages):
    for message in messages:
        repeated_properties = []
        required_properties = []
        optional_properties = []
        # https://developers.google.com/protocol-buffers/docs/proto#scalar
        for property in message["properties"]:
            property_type = property["type"]
            if property_type == Field.TYPE_DOUBLE:
                property["type_lua"] = "number"
                property["type_cpp"] = "double"
            elif property_type == Field.TYPE_FLOAT:
                property["type_lua"] = "number"
                property["type_cpp"] = "float"
            elif property_type == Field.TYPE_INT64 or property_type == Field.TYPE_SFIXED64 or property_type == Field.TYPE_SINT64:
                property["type_lua"] = "number"
                property["type_cpp"] = "int64_t"
            elif property_type == Field.TYPE_INT32 or property_type == Field.TYPE_SFIXED32 or property_type == Field.TYPE_SINT32:
                property["type_lua"] = "number"
                property["type_cpp"] = "int32_t"
            elif property_type == Field.TYPE_FIXED64 or property_type == Field.TYPE_UINT64:
                property["type_lua"] = "number"
                property["type_cpp"] = "uint64_t"
            elif property_type == Field.TYPE_FIXED32 or property_type == Field.TYPE_UINT32:
                property["type_lua"] = "number"
                property["type_cpp"] = "uint32_t"
            elif property_type == Field.TYPE_BOOL:
                property["type_lua"] = "boolean"
                property["type_cpp"] = "bool"
            elif property_type == Field.TYPE_ENUM:
                property["type_lua"] = "number"
                property["type_cpp"] = "int"
            elif property_type == Field.TYPE_STRING:
                property["type_lua"] = "string"
                property["type_cpp"] = "char*"
            elif property_type == Field.TYPE_BYTES:
                property["type_lua"] = "string"
                property["type_cpp"] = "uint8_t*"
            elif property_type == Field.TYPE_MESSAGE:
                property["type_lua"] = property["type_name"].replace(".", "").lower()
                property["type_cpp"] = property["type_name"].replace(".", "") + "*"
            elif property_type == Field.TYPE_GROUP:
                print("Unsupported type 'group'")
            else:
                print("Unknown property type!")

            if property["required"]:
                required_properties.append(property)
            elif property["repeated"]:
                repeated_properties.append(property)
            else:
                optional_properties.append(property)

            message["required_properties"] = required_properties
            message["repeated_properties"] = repeated_properties
            message["optional_properties"] = optional_properties

def generate():
    j = json.load(open("proto.json"))
    parse_files(j["files"])
    parse_messages(j["messages"])
    # print(json.dumps(j, indent=4))

    with open("extension-proto.cpp.mtl", 'r') as f:
        extension_proto_mtl = f.read()
        result = pystache.render(extension_proto_mtl, j)
        with codecs.open("extension-proto/src/proto.cpp", "wb", encoding="utf-8") as f:
            f.write(html.unescape(result))


if __name__ == "__main__":
    generate()