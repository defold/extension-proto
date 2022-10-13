#!/usr/bin/env python

import pystache
import json
import codecs
import html
import subprocess
import os
import shutil
import pathlib
import sys
from sys import platform

BASE_DIR = str(pathlib.Path(__file__).parent.resolve())

EXTENSION_DIR_ROOT = BASE_DIR + "/extension-proto"
EXTENSION_DIR_SRC = EXTENSION_DIR_ROOT + "/src/gen"
EXTENSION_DIR_JSON = EXTENSION_DIR_ROOT + "/json"

EXTENSION_PROTO_JSON = EXTENSION_DIR_ROOT + "/json/proto.json"
EXTENSION_PROTO_CPP = EXTENSION_DIR_SRC + "/proto.cpp"
EXTENSION_PROTO_API = EXTENSION_DIR_ROOT + "/api/extension-proto.script_api"

PLUGINS_DIR = BASE_DIR + "/plugins"
PROTO_DIR = "./proto"
PROTO_INCLUDES_DIR = "./proto_includes"


def call(args):
	ret = os.system(args)
	if ret != 0:
		sys.exit(1)
	return ret

def mkdir(dir):
	if os.path.exists(dir):
		shutil.rmtree(dir)
	os.makedirs(dir)

def get_platform():
	if platform == "linux" or platform == "linux2":
		return "x86_64-linux"
	elif platform == "darwin":
		return "x86_64-macos"
	elif platform == "win32":
		return "x86_64-win"
	else:
		raise Exception("Unknown platform")

def get_protoc():
	return PLUGINS_DIR + "/protoc-" + get_platform()

def get_protoc_gen_c():
	return PLUGINS_DIR + "/protoc-gen-c-" + get_platform()

def get_protoc_gen_json():
	return PLUGINS_DIR + "/protoc-gen-json.py"

def generate_extension():
	j = json.load(open("extension-proto/json/proto.json"))

	with open("extension-proto.cpp.mtl", 'r') as f:
		extension_proto_mtl = f.read()
		result = pystache.render(extension_proto_mtl, j)
		with codecs.open(EXTENSION_PROTO_CPP, "wb", encoding="utf-8") as f:
			f.write(html.unescape(result))

def find_all_proto_files():
	files = []
	# r=root, d=directories, f = files
	for r, d, f in os.walk(PROTO_DIR):
		for file in f:
			if file.endswith(".proto"):
				files.append(os.path.join(r, file))
	return files

def generate_json():
	print("Generating json")
	mkdir(EXTENSION_DIR_JSON)
	args = [
		get_protoc(),
		"--plugin=protoc-gen-json=" + get_protoc_gen_json(),
		"--json_out=" + EXTENSION_DIR_JSON,
		"--proto_path={} --proto_path={}".format(PROTO_DIR, PROTO_INCLUDES_DIR),
	] + find_all_proto_files()
	call(" ".join(args))

def generate_c():
	print("Generating C")
	mkdir(EXTENSION_DIR_SRC)
	args = [
		get_protoc(),
		"--plugin=protoc-gen-c=" + get_protoc_gen_c(),
		"--c_out=" + EXTENSION_DIR_SRC,
		"--proto_path={} --proto_path={}".format(PROTO_DIR, PROTO_INCLUDES_DIR),
	] + find_all_proto_files()
	call(" ".join(args))


def generate_proto_cpp():
	print("Generating extension main")
	with open("extension-proto.cpp.mtl", 'r') as f:
		proto_json = json.load(open(EXTENSION_PROTO_JSON))
		extension_proto_mtl = f.read()
		result = pystache.render(extension_proto_mtl, proto_json)
		with codecs.open(EXTENSION_PROTO_CPP, "wb", encoding="utf-8") as f:
			f.write(html.unescape(result))

def generate_proto_api():
	print("Generating extension docs")
	with open("extension-proto.script_api.mtl", 'r') as f:
		proto_json = json.load(open(EXTENSION_PROTO_JSON))
		extension_proto_mtl = f.read()
		result = pystache.render(extension_proto_mtl, proto_json)
		with codecs.open(EXTENSION_PROTO_API, "wb", encoding="utf-8") as f:
			f.write(html.unescape(result))

generate_json()
generate_c()
generate_proto_cpp()
generate_proto_api()
