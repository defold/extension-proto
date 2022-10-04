#!/usr/bin/env bash
install_name_tool -change /usr/local/opt/protobuf/lib/libprotobuf.32.dylib @loader_path/libprotobuf.32.dylib protoc-gen-c-x86_64-macos
install_name_tool -change /usr/local/opt/protobuf/lib/libprotoc.32.dylib @loader_path/libprotoc.32.dylib protoc-gen-c-x86_64-macos

install_name_tool -change /usr/local/Cellar/protobuf/21.6/lib/libprotobuf.32.dylib @loader_path/libprotobuf.32.dylib libprotoc.32.dylib
otool -l protoc-gen-c-x86_64-macos