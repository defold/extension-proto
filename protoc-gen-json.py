#!/usr/bin/env python

import sys
import itertools
import json

from google.protobuf.compiler import plugin_pb2 as plugin
from google.protobuf.descriptor_pb2 import DescriptorProto, EnumDescriptorProto, FieldDescriptorProto


def traverse(proto_file):

    def _traverse(package, items):
        for item in items:
            yield item, package

            if isinstance(item, DescriptorProto):
                for enum in item.enum_type:
                    yield enum, package

                for nested in item.nested_type:
                    nested_package = package + item.name

                    for nested_item in _traverse(nested, nested_package):
                        yield nested_item, nested_package

    return itertools.chain(
        _traverse(proto_file.package, proto_file.enum_type),
        _traverse(proto_file.package, proto_file.message_type),
    )

def generate_code(request, response):
    output = {
        "messages": [],
        "enums": [],
        "files": [],
    }
    for proto_file in request.proto_file:
        for item, package in traverse(proto_file):
            file = {
                "filename": proto_file.name,
            }
            output.get("files").append(file)

            data = {
                'package': proto_file.package or '',
                'filename': proto_file.name,
                'name': item.name,
                'name_lower': item.name.lower(),
            }

            if isinstance(item, DescriptorProto):
                data.update({
                    'type': 'Message',
                    'properties': [{'name': f.name, 'type': int(f.type), 'type_name': f.type_name, 'repeated': (f.label == FieldDescriptorProto.LABEL_REPEATED), 'required': (f.label == FieldDescriptorProto.LABEL_REQUIRED)}
                                   for f in item.field]
                })
                output.get("messages").append(data)

            elif isinstance(item, EnumDescriptorProto):
                data.update({
                    'type': 'Enum',
                    'values': [{'name': v.name, 'value': v.number}
                               for v in item.value]
                })
                output.get("enums").append(data)

    f = response.file.add()
    f.name = 'proto.json'
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