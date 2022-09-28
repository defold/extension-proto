#!/usr/bin/env bash

rm -rf extension-proto/src/gen
mkdir extension-proto/src/gen

echo "Generating json"
./protoc --plugin=protoc-gen-json=protoc-gen-json.py --json_out=extension-proto/json/ --proto_path=proto proto/*.proto

echo "Generating C"
./protoc --plugin=protoc-gen-c=protoc-gen-c --c_out=extension-proto/src/gen --proto_path=proto proto/*.proto

echo "Generating extension"
python json-to-extension.py extension-proto/json/proto.json

echo "Generating extension docs"
python json-to-script_api.py extension-proto/json/proto.json