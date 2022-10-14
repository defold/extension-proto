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
EXTENSION_DIR_SRC = EXTENSION_DIR_ROOT + "/src"
EXTENSION_DIR_HEADERS = EXTENSION_DIR_ROOT + "/include"
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

def clean_extension_src_dir(dir):
	for r, d, f in os.walk(dir, topdown=True):
		try :
			del d[d.index("protobuf-c")]
		except ValueError :
			pass

		for file in f:
			os.remove(os.path.join(r, file))
		for dir in d:
			shutil.rmtree(os.path.join(r, dir))

# copy generated .h files from src/ to include/
def move_extension_includes():
	for r, d, f in os.walk(EXTENSION_DIR_SRC, topdown=True):
		for file in f:
			if file.endswith(".h"):
				src_file = os.path.join(r, file)
				src_path = os.path.dirname(src_file)
				rel_path = os.path.relpath(src_path, start=os.path.abspath(EXTENSION_DIR_SRC))
				dst_path = os.path.join(EXTENSION_DIR_HEADERS, rel_path)
				if not os.path.exists(dst_path):
					os.makedirs(dst_path)
				shutil.move(src_file, dst_path)


def find_all_proto_files(dir):
	files = []
	for r, d, f in os.walk(dir):
		for file in f:
			if file.endswith(".proto"):
				files.append(os.path.join(r, file))
	return files

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

def generate_json():
	print("Generating json")
	args = [
		get_protoc(),
		"--plugin=protoc-gen-json=" + get_protoc_gen_json(),
		"--json_out=" + EXTENSION_DIR_JSON,
		"--proto_path={} --proto_path={}".format(PROTO_DIR, PROTO_INCLUDES_DIR),
	]
	call(" ".join(args + find_all_proto_files(PROTO_DIR)))

def generate_c():
	print("Generating C")
	clean_extension_src_dir(EXTENSION_DIR_SRC)
	clean_extension_src_dir(EXTENSION_DIR_HEADERS)
	args = [
		get_protoc(),
		"--plugin=protoc-gen-c=" + get_protoc_gen_c(),
		"--c_out=" + EXTENSION_DIR_SRC,
		"--proto_path={} --proto_path={}".format(PROTO_DIR, PROTO_INCLUDES_DIR),
	]
	call(" ".join(args + find_all_proto_files(PROTO_DIR)))
	move_extension_includes()


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
