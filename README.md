# extension-proto
This extension generates Lua bindings to encode and decode a predefined set of protobuf messages using Lua. The advantage with this solution is that there is no need to parse and compile protobuf message definitions, but the drawback is that the extension can only handle the protobuf messages that were processed when the extension was built. If you need an extension to also parse and compile protobuf message defintions then take a look at [defold-protobuf](https://defold.com/assets/protobuf/).


## Requirements
To generate the Lua bindings you need python 3 and the `protobuf` and `pystache` packages. Install the packages using `pip`:

```sh
# install required python packages
pip install protobuf
pip install pystache
```

## Setup
This extension requires a bit more setup than most other Defold extensions before it can be used in a project:

1. To use this extension in your Defold project, either [download a copy](https://github.com/defold/extension-proto/archive/refs/heads/master.zip) of the project, [create a fork](https://github.com/defold/extension-proto/fork) or [create a new repo from this template project](https://github.com/defold/extension-proto/generate).

2. Add the protobuf message definitions (files with `.proto` extension) that the extension should handle to the `proto/` folder located in the root of the project. You can also load the `.proto` files from another location:
   * Argument `-p` can be used when running `generate.py` to set list of paths where proto files are located (search paths)
   * Argument `-f` can be used when running `generate.py` to define list of `.proto` files that will be used in the project

3. Run `generate.py` to generate Lua bindings and other required files. The script does the following:
   * Process all .proto files into a single intermediate data file in JSON format containing information about the protobuf messages
   * Generate C representations of the protobuf messages for use at runtime
   * Generate Defold extension source code with Lua bindings to encode and decode all protobuf messages
   * Generate Defold script API definitions for the Lua bindings to enable auto-complete in the editor

Example:

```sh

# Generate bindings for all '.proto' files in the 'proto' folder
cd extension-proto
python .generate.py

# Generate bindings for file 'testproto3.proto' with imports located in './extension-proto/proto'
python ./extension-proto/generate.py -f testproto3.proto -p ./extension-proto/proto
```

The `generate.py` script uses the `protoc` compiler and the `protobuf-c` C-code generator:

* `protoc` from https://github.com/protocolbuffers/protobuf/releases/tag/v21.6
* `protobuf-c` from https://github.com/defold/protobuf-c


## Run-time usage
The extension provides Lua bindings to encode and decode the protobuf messages defined in the `proto/` folder. The extension can encode and decode binary messages in protobuf 2 and protobuf 3 format. The extension can also encode and decode text messages in protobuf 2 format. Example:

```
syntax = "proto2";

message Person {
  required int32 id = 1;
  required string name = 2;
  optional string email = 3;
}
```

Used in the extension like this:

```
-- Lua table matching
local person = {
	id = 1,
	name = "Bob",
	email = "bob@acme.com",
}

-- encode Lua table to a binary protobuf message
local msg = proto.encode_person(person)

-- decode from a binary protobuf message to a Lua table
local decoded = proto.decode_person(msg)
assert(person.id == decoded.id)
assert(person.name == decoded.name)
assert(person.email == decoded.email)

-- encode Lua table to a text message
local msg_totext = proto.encode_person_totext(person)

-- decode from a text message to a Lua table
local decoded_fromtext = proto.decode_person_fromtext(msg_totext)
assert(person.id == decoded_fromtext.id)
assert(person.name == decoded_fromtext.name)
assert(person.email == decoded_fromtext.email)
```


## Folder overview

```
|
+-- extension-proto                        The Defold extension
|   |
|   +-- api
|   |   |
|   |   +-- extension-proto.script_api     (GENERATED) Lua API defintions for auto completion
|   |   
|   +-- include
|   |   |
|   |   +-- protobuf-c
|   |       |
|   |       +-- protobuf-c.h               The protobuf c runtime header
|   |   
|   +-- json
|   |   |
|   |   +-- proto.json                     (GENERATED) Protobuf message definitions converted
|   |                                      to json. The json format is used when generating
|   |                                      the other files used by the extension.
|   +-- src                   
|       |
|       +-- protobuf-c
|       |   |
|       |   +-- protobuf-c.c               The protobuf c runtime source code
|       |
|       +-- protobuf-c-text
|       |   |
|       |   +-- ...                        The protobuf c text runtime source code
|       |
|       +-- proto.cpp                      (GENERATED) Extension source code
|       +-- *-pb-c.c                       (GENERATED) Protobuf message source code
|       +-- *-pb-c.h                       (GENERATED) Protobuf message header
|
+--- proto
|    |
|    +-- *.proto                           Protobuf message definitions
```


