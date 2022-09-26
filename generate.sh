#!/usr/bin/env bash

echo "Generating json"
./protoc --plugin=protoc-gen-json=protoc-gen-json.py --json_out=. --proto_path=proto proto/*.proto

echo "Generating C"
./protoc --plugin=protoc-gen-c=protoc-gen-c --c_out=extension-proto/src --proto_path=proto proto/*.proto

# echo "Generating CPP"
# ./protoc --cpp_out=extension-proto/src --proto_path=proto proto/*.proto

echo "Generating extension"
python json-to-extension.py

echo "Generating extension docs"
python json-to-script_api.py