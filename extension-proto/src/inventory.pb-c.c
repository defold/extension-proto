/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: inventory.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "inventory.pb-c.h"
void   game__inventory__init
                     (Game__Inventory         *message)
{
  static const Game__Inventory init_value = GAME__INVENTORY__INIT;
  *message = init_value;
}
size_t game__inventory__get_packed_size
                     (const Game__Inventory *message)
{
  assert(message->base.descriptor == &game__inventory__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t game__inventory__pack
                     (const Game__Inventory *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &game__inventory__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t game__inventory__pack_to_buffer
                     (const Game__Inventory *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &game__inventory__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Game__Inventory *
       game__inventory__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Game__Inventory *)
     protobuf_c_message_unpack (&game__inventory__descriptor,
                                allocator, len, data);
}
void   game__inventory__free_unpacked
                     (Game__Inventory *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &game__inventory__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor game__inventory__field_descriptors[2] =
{
  {
    "capacity",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Game__Inventory, capacity),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "items",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Game__Inventory, n_items),
    offsetof(Game__Inventory, items),
    &game__item__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned game__inventory__field_indices_by_name[] = {
  0,   /* field[0] = capacity */
  1,   /* field[1] = items */
};
static const ProtobufCIntRange game__inventory__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor game__inventory__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Game.Inventory",
  "Inventory",
  "Game__Inventory",
  "Game",
  sizeof(Game__Inventory),
  2,
  game__inventory__field_descriptors,
  game__inventory__field_indices_by_name,
  1,  game__inventory__number_ranges,
  (ProtobufCMessageInit) game__inventory__init,
  NULL,NULL,NULL    /* reserved[123] */
};
