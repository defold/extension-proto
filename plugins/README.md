This folder contains the `protoc` plugins for generating language specific files from .proto files.

## protoc-gen-c
This is the C language plugin for macOS, Windows and Linux. The binaries are built using [GitHub Actions](https://github.com/defold/protobuf-c/actions) and downloaded and unpacked into this folder. When the binaries have been downloaded and unpacked the macOS binary and dynamic libs are updated to load the libraries from within the same folder using `change_lib_paths.sh`

## protoc-gen-json
This is the JSON plugin which generates a single JSON definition for all messages and enums. The plugin is written in Python.

