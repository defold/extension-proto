#!/usr/bin/env python

import pystache
import json
import codecs
import html
import subprocess
import os
import shutil
import pathlib


BASE_DIR = pathlib.Path(__file__).parent.resolve()
EXTENSION_DIR_ROOT = BASE_DIR + "/extension-proto"
EXTENSION_DIR_SRC = EXTENSION_DIR_ROOT + "/src/gen"
EXTENSION_DIR_JSON = EXTENSION_DIR_ROOT + "/json"
EXTENSION_JSON = EXTENSION_DIR_ROOT + "/json/proto.json"

BIN_DIR = BASE_DIR + "/bin"
PROTO_DIR = BASE_DIR + "/proto"


def _call(args):
	print(args)
	ret = os.system(args)
	if ret != 0:
		sys.exit(1)

def call(args, dir=None):
	print(args)
	subprocess.call(args, cwd=dir)

def mkdir(dir):
	if os.path.exists(dir):
		os.remove(dir)
	os.makedirs(dir)

def generate_extension():
	j = json.load(open("extension-proto/json/proto.json"))

	with open("extension-proto.cpp.mtl", 'r') as f:
		extension_proto_mtl = f.read()
		result = pystache.render(extension_proto_mtl, j)
		with codecs.open("extension-proto/src/gen/proto.cpp", "wb", encoding="utf-8") as f:
			f.write(html.unescape(result))

def generate_json():
	mkdir(EXTENSION_DIR_JSON)
	args = [
		BIN_DIR + "/protoc-macos",
		"--plugin=protoc-gen-json=" + BIN_DIR + "/protoc-gen-json.py",
		"--json_out=" + EXTENSION_JSON,
		"--proto_path=" + PROTO_DIR,
		PROTO_DIR + "/*.proto" ]
	call(args)
	# ./protoc --plugin=protoc-gen-json=protoc-gen-json.py --json_out=extension-proto/json/ --proto_path=proto proto/*.proto




mkdir(EXTENSION_DIR_SRC)

generate_json()

# print("Generating json")


# echo "Generating C"
# ./protoc --plugin=protoc-gen-c=protoc-gen-c --c_out=extension-proto/src/gen --proto_path=proto proto/*.proto

# echo "Generating extension"
# python json-to-extension.py extension-proto/json/proto.json

# echo "Generating extension docs"
# python json-to-script_api.py extension-proto/json/proto.json