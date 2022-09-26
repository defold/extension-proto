#!/usr/bin/env python

import pystache
import json
import codecs
import html


def generate():
    j = json.load(open("proto.json"))
    # print(json.dumps(j, indent=4))

    with open("extension-proto.script_api.mtl", 'r') as f:
        extension_proto_mtl = f.read()
        result = pystache.render(extension_proto_mtl, j)
        with codecs.open("extension-proto/api/extension-proto.script_api", "wb", encoding="utf-8") as f:
            f.write(html.unescape(result))


if __name__ == "__main__":
    generate()