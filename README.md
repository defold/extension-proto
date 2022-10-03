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

1. To use this extension in your Defold project, either [download a copy](https://github.com/defold/extension-proto/archive/refs/heads/master.zip) of the project or [create a fork](https://github.com/defold/extension-proto/fork).

2. Add the protobuf message definitions (files with `.proto` extension) that the extension should handle to the `proto/` folder located in the root of the project.

3. Run `generate.py` to generate Lua bindings and other required files. The script does the following:
   * Process all .proto files into a single intermediate data file in JSON format containing information about the protobuf messages
   * Generate C representations of the protobuf messages for use at runtime
   * Generate Defold extension source code with Lua bindings to encode and decode all protobuf messages
   * Generate Defold script API definitions for the Lua bindings to enable auto-complete in the editor

The `generate.py` script uses the `protoc` compiler and the `protobuf-c` C-code generator:

* `protoc` from https://github.com/protocolbuffers/protobuf/releases/tag/v21.6
* `protobuf-c` from https://github.com/defold/protobuf-c


## Usage
The extension provides Lua bindings to encode and decode the protobuf messages defined in the `proto/` folder. Example:

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
|       +-- proto.cpp                      (GENERATED) Extension source code
|       +-- *-pb-c.c                       (GENERATED) Protobuf message source code
|       +-- *-pb-c.h                       (GENERATED) Protobuf message header
|
+--- proto
|    |
|    +-- *.proto                           Protobuf message defintions
```


