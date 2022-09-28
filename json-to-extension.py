#!/usr/bin/env python

import pystache
import json
import codecs
import html

def generate():
    j = json.load(open("extension-proto/json/proto.json"))

    with open("extension-proto.cpp.mtl", 'r') as f:
        extension_proto_mtl = f.read()
        result = pystache.render(extension_proto_mtl, j)
        with codecs.open("extension-proto/src/gen/proto.cpp", "wb", encoding="utf-8") as f:
            f.write(html.unescape(result))


if __name__ == "__main__":
    generate()