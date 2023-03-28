#define EXTENSION_NAME Proto
#define LIB_NAME "Proto"
#define MODULE_NAME "proto"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>
#include <stdlib.h>


#include "testproto3.pb-c.h"
#include "testproto2.pb-c.h"



/******************************************************************************
 * PUSH
 ******************************************************************************/

static void lua_pushtestp3__scalars(lua_State* L, Testp3__Scalars *msg);
static void lua_pushtestp3__outer(lua_State* L, Testp3__Outer *msg);
static void lua_pushtestp3__outer__middle(lua_State* L, Testp3__Outer__Middle *msg);
static void lua_pushtestp3__outer__middle__inner(lua_State* L, Testp3__Outer__Middle__Inner *msg);
static void lua_pushtestp3__basic(lua_State* L, Testp3__Basic *msg);
static void lua_pushtestp3__container(lua_State* L, Testp3__Container *msg);
static void lua_pushtestp3__container__basic_map_entry(lua_State* L, Testp3__Container__BasicMapEntry *msg);
static void lua_pushtestp3__container__string_map_entry(lua_State* L, Testp3__Container__StringMapEntry *msg);
static void lua_pushtestp3__one_of(lua_State* L, Testp3__OneOf *msg);
static void lua_pushtestp3__one_of__first_and_last(lua_State* L, Testp3__OneOf__FirstAndLast *msg);
static void lua_pushtestp2__scalars(lua_State* L, Testp2__Scalars *msg);
static void lua_pushtestp2__outer(lua_State* L, Testp2__Outer *msg);
static void lua_pushtestp2__outer__middle(lua_State* L, Testp2__Outer__Middle *msg);
static void lua_pushtestp2__outer__middle__inner(lua_State* L, Testp2__Outer__Middle__Inner *msg);
static void lua_pushtestp2__basic(lua_State* L, Testp2__Basic *msg);
static void lua_pushtestp2__container(lua_State* L, Testp2__Container *msg);
static void lua_pushtestp2__container__basic_map_entry(lua_State* L, Testp2__Container__BasicMapEntry *msg);
static void lua_pushtestp2__container__string_map_entry(lua_State* L, Testp2__Container__StringMapEntry *msg);
static void lua_pushtestp2__one_of(lua_State* L, Testp2__OneOf *msg);
static void lua_pushtestp2__one_of__first_and_last(lua_State* L, Testp2__OneOf__FirstAndLast *msg);
static void lua_pushtestp3__scalars_repeated(lua_State* L, Testp3__Scalars *msg, int count);
static void lua_pushtestp3__outer_repeated(lua_State* L, Testp3__Outer *msg, int count);
static void lua_pushtestp3__outer__middle_repeated(lua_State* L, Testp3__Outer__Middle *msg, int count);
static void lua_pushtestp3__outer__middle__inner_repeated(lua_State* L, Testp3__Outer__Middle__Inner *msg, int count);
static void lua_pushtestp3__basic_repeated(lua_State* L, Testp3__Basic *msg, int count);
static void lua_pushtestp3__container_repeated(lua_State* L, Testp3__Container *msg, int count);
static void lua_pushtestp3__container__basic_map_entry_repeated(lua_State* L, Testp3__Container__BasicMapEntry *msg, int count);
static void lua_pushtestp3__container__string_map_entry_repeated(lua_State* L, Testp3__Container__StringMapEntry *msg, int count);
static void lua_pushtestp3__one_of_repeated(lua_State* L, Testp3__OneOf *msg, int count);
static void lua_pushtestp3__one_of__first_and_last_repeated(lua_State* L, Testp3__OneOf__FirstAndLast *msg, int count);
static void lua_pushtestp2__scalars_repeated(lua_State* L, Testp2__Scalars *msg, int count);
static void lua_pushtestp2__outer_repeated(lua_State* L, Testp2__Outer *msg, int count);
static void lua_pushtestp2__outer__middle_repeated(lua_State* L, Testp2__Outer__Middle *msg, int count);
static void lua_pushtestp2__outer__middle__inner_repeated(lua_State* L, Testp2__Outer__Middle__Inner *msg, int count);
static void lua_pushtestp2__basic_repeated(lua_State* L, Testp2__Basic *msg, int count);
static void lua_pushtestp2__container_repeated(lua_State* L, Testp2__Container *msg, int count);
static void lua_pushtestp2__container__basic_map_entry_repeated(lua_State* L, Testp2__Container__BasicMapEntry *msg, int count);
static void lua_pushtestp2__container__string_map_entry_repeated(lua_State* L, Testp2__Container__StringMapEntry *msg, int count);
static void lua_pushtestp2__one_of_repeated(lua_State* L, Testp2__OneOf *msg, int count);
static void lua_pushtestp2__one_of__first_and_last_repeated(lua_State* L, Testp2__OneOf__FirstAndLast *msg, int count);

static void lua_pushProtobufCBinaryData(lua_State* L, ProtobufCBinaryData binarydata)
{
    lua_pushlstring(L, (const char*)binarydata.data, binarydata.len);
}

static void lua_pushtestp3__scalars_repeated(lua_State* L, Testp3__Scalars *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__scalars(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__outer_repeated(lua_State* L, Testp3__Outer *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__outer(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__outer__middle_repeated(lua_State* L, Testp3__Outer__Middle *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__outer__middle(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__outer__middle__inner_repeated(lua_State* L, Testp3__Outer__Middle__Inner *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__outer__middle__inner(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__basic_repeated(lua_State* L, Testp3__Basic *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__basic(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__container_repeated(lua_State* L, Testp3__Container *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__container(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__container__basic_map_entry_repeated(lua_State* L, Testp3__Container__BasicMapEntry *msg, int index)
{
    char* key = (char*)(msg->key);
    Testp3__Basic* value = (Testp3__Basic*)(msg->value);
    lua_pushstring(L, key);
    lua_pushtestp3__basic(L, value);
    lua_settable(L, -3);
}
static void lua_pushtestp3__container__string_map_entry_repeated(lua_State* L, Testp3__Container__StringMapEntry *msg, int index)
{
    char* key = (char*)(msg->key);
    char* value = (char*)(msg->value);
    lua_pushstring(L, key);
    lua_pushstring(L, value);
    lua_settable(L, -3);
}
static void lua_pushtestp3__one_of_repeated(lua_State* L, Testp3__OneOf *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__one_of(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp3__one_of__first_and_last_repeated(lua_State* L, Testp3__OneOf__FirstAndLast *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp3__one_of__first_and_last(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__scalars_repeated(lua_State* L, Testp2__Scalars *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__scalars(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__outer_repeated(lua_State* L, Testp2__Outer *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__outer(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__outer__middle_repeated(lua_State* L, Testp2__Outer__Middle *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__outer__middle(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__outer__middle__inner_repeated(lua_State* L, Testp2__Outer__Middle__Inner *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__outer__middle__inner(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__basic_repeated(lua_State* L, Testp2__Basic *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__basic(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__container_repeated(lua_State* L, Testp2__Container *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__container(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__container__basic_map_entry_repeated(lua_State* L, Testp2__Container__BasicMapEntry *msg, int index)
{
    char* key = (char*)(msg->key);
    Testp2__Basic* value = (Testp2__Basic*)(msg->value);
    lua_pushstring(L, key);
    lua_pushtestp2__basic(L, value);
    lua_settable(L, -3);
}
static void lua_pushtestp2__container__string_map_entry_repeated(lua_State* L, Testp2__Container__StringMapEntry *msg, int index)
{
    char* key = (char*)(msg->key);
    char* value = (char*)(msg->value);
    lua_pushstring(L, key);
    lua_pushstring(L, value);
    lua_settable(L, -3);
}
static void lua_pushtestp2__one_of_repeated(lua_State* L, Testp2__OneOf *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__one_of(L, msg);
    lua_settable(L, -3);
}
static void lua_pushtestp2__one_of__first_and_last_repeated(lua_State* L, Testp2__OneOf__FirstAndLast *msg, int index)
{
    lua_pushnumber(L, index);
    lua_pushtestp2__one_of__first_and_last(L, msg);
    lua_settable(L, -3);
}

static void lua_pushtestp3__scalars(lua_State* L, Testp3__Scalars *msg)
{
    lua_newtable(L);

    // i32
    {
        lua_pushstring(L, "i32");
        lua_pushnumber(L, (int32_t)(msg->i32));
        lua_settable(L, -3);
    }

    // i64
    {
        lua_pushstring(L, "i64");
        lua_pushnumber(L, (int64_t)(msg->i64));
        lua_settable(L, -3);
    }

    // ui32
    {
        lua_pushstring(L, "ui32");
        lua_pushnumber(L, (uint32_t)(msg->ui32));
        lua_settable(L, -3);
    }

    // ui64
    {
        lua_pushstring(L, "ui64");
        lua_pushnumber(L, (uint64_t)(msg->ui64));
        lua_settable(L, -3);
    }

    // si32
    {
        lua_pushstring(L, "si32");
        lua_pushnumber(L, (int32_t)(msg->si32));
        lua_settable(L, -3);
    }

    // si64
    {
        lua_pushstring(L, "si64");
        lua_pushnumber(L, (int64_t)(msg->si64));
        lua_settable(L, -3);
    }

    // fix32
    {
        lua_pushstring(L, "fix32");
        lua_pushnumber(L, (uint32_t)(msg->fix32));
        lua_settable(L, -3);
    }

    // fix64
    {
        lua_pushstring(L, "fix64");
        lua_pushnumber(L, (uint64_t)(msg->fix64));
        lua_settable(L, -3);
    }

    // sfix32
    {
        lua_pushstring(L, "sfix32");
        lua_pushnumber(L, (int32_t)(msg->sfix32));
        lua_settable(L, -3);
    }

    // sfix64
    {
        lua_pushstring(L, "sfix64");
        lua_pushnumber(L, (int64_t)(msg->sfix64));
        lua_settable(L, -3);
    }

    // b
    {
        lua_pushstring(L, "b");
        lua_pushboolean(L, (protobuf_c_boolean)(msg->b));
        lua_settable(L, -3);
    }

    // s
    {
        lua_pushstring(L, "s");
        lua_pushstring(L, (char*)(msg->s));
        lua_settable(L, -3);
    }

    // bytes
    {
        lua_pushstring(L, "bytes");
        lua_pushProtobufCBinaryData(L, (ProtobufCBinaryData)(msg->bytes));
        lua_settable(L, -3);
    }

    // d
    {
        lua_pushstring(L, "d");
        lua_pushnumber(L, (double)(msg->d));
        lua_settable(L, -3);
    }

    // f
    {
        lua_pushstring(L, "f");
        lua_pushnumber(L, (float)(msg->f));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__outer(lua_State* L, Testp3__Outer *msg)
{
    lua_newtable(L);

    // text
    {
        lua_pushstring(L, "text");
        lua_pushstring(L, (char*)(msg->text));
        lua_settable(L, -3);
    }

    // middle
    {
        lua_pushstring(L, "middle");
        if (msg->middle)
        {
            lua_pushtestp3__outer__middle(L, (Testp3__Outer__Middle*)(msg->middle));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__outer__middle(lua_State* L, Testp3__Outer__Middle *msg)
{
    lua_newtable(L);

    // text
    {
        lua_pushstring(L, "text");
        lua_pushstring(L, (char*)(msg->text));
        lua_settable(L, -3);
    }

    // inner
    {
        lua_pushstring(L, "inner");
        if (msg->inner)
        {
            lua_pushtestp3__outer__middle__inner(L, (Testp3__Outer__Middle__Inner*)(msg->inner));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__outer__middle__inner(lua_State* L, Testp3__Outer__Middle__Inner *msg)
{
    lua_newtable(L);

    // text
    {
        lua_pushstring(L, "text");
        lua_pushstring(L, (char*)(msg->text));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__basic(lua_State* L, Testp3__Basic *msg)
{
    lua_newtable(L);

    // s
    {
        lua_pushstring(L, "s");
        lua_pushstring(L, (char*)(msg->s));
        lua_settable(L, -3);
    }

    // i
    {
        lua_pushstring(L, "i");
        lua_pushnumber(L, (int32_t)(msg->i));
        lua_settable(L, -3);
    }

    // lang
    {
        lua_pushstring(L, "lang");
        lua_pushnumber(L, (Testp3__Language)(msg->lang));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__container(lua_State* L, Testp3__Container *msg)
{
    lua_newtable(L);

    // basic_map
    lua_pushstring(L, "basic_map");
    lua_newtable(L);
    int basic_map_size = msg->n_basic_map;
    for (int i = 0; i < basic_map_size; i++)
    {
        Testp3__Container__BasicMapEntry* basic_map_msg = (Testp3__Container__BasicMapEntry*)(msg->basic_map[i]);
        lua_pushtestp3__container__basic_map_entry_repeated(L, basic_map_msg, i + 1);
    }
    lua_settable(L, -3);

    // string_map
    lua_pushstring(L, "string_map");
    lua_newtable(L);
    int string_map_size = msg->n_string_map;
    for (int i = 0; i < string_map_size; i++)
    {
        Testp3__Container__StringMapEntry* string_map_msg = (Testp3__Container__StringMapEntry*)(msg->string_map[i]);
        lua_pushtestp3__container__string_map_entry_repeated(L, string_map_msg, i + 1);
    }
    lua_settable(L, -3);

    // repeated_string1
    lua_pushstring(L, "repeated_string1");
    lua_newtable(L);
    int repeated_string1_size = msg->n_repeated_string1;
    for (int i = 0; i < repeated_string1_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushstring(L, (char*)(msg->repeated_string1[i]));
        lua_settable(L, -3);
    }
    lua_settable(L, -3);

    // repeated_string2
    lua_pushstring(L, "repeated_string2");
    lua_newtable(L);
    int repeated_string2_size = msg->n_repeated_string2;
    for (int i = 0; i < repeated_string2_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushstring(L, (char*)(msg->repeated_string2[i]));
        lua_settable(L, -3);
    }
    lua_settable(L, -3);

    // repeated_basic1
    lua_pushstring(L, "repeated_basic1");
    lua_newtable(L);
    int repeated_basic1_size = msg->n_repeated_basic1;
    for (int i = 0; i < repeated_basic1_size; i++)
    {
        Testp3__Basic* repeated_basic1_msg = (Testp3__Basic*)(msg->repeated_basic1[i]);
        lua_pushtestp3__basic_repeated(L, repeated_basic1_msg, i + 1);
    }
    lua_settable(L, -3);

    // repeated_basic2
    lua_pushstring(L, "repeated_basic2");
    lua_newtable(L);
    int repeated_basic2_size = msg->n_repeated_basic2;
    for (int i = 0; i < repeated_basic2_size; i++)
    {
        Testp3__Basic* repeated_basic2_msg = (Testp3__Basic*)(msg->repeated_basic2[i]);
        lua_pushtestp3__basic_repeated(L, repeated_basic2_msg, i + 1);
    }
    lua_settable(L, -3);

}
static void lua_pushtestp3__container__basic_map_entry(lua_State* L, Testp3__Container__BasicMapEntry *msg)
{
    lua_newtable(L);

}
static void lua_pushtestp3__container__string_map_entry(lua_State* L, Testp3__Container__StringMapEntry *msg)
{
    lua_newtable(L);

}
static void lua_pushtestp3__one_of(lua_State* L, Testp3__OneOf *msg)
{
    lua_newtable(L);

    // name
    if (msg->oftest1_case == TESTP3__ONE_OF__OFTEST1_NAME)
    {
        lua_pushstring(L, "name");
        lua_pushstring(L, (char*)(msg->name));
        lua_settable(L, -3);
    }

    // first_and_last
    if (msg->oftest1_case == TESTP3__ONE_OF__OFTEST1_FIRST_AND_LAST)
    {
        lua_pushstring(L, "first_and_last");
        if (msg->first_and_last)
        {
            lua_pushtestp3__one_of__first_and_last(L, (Testp3__OneOf__FirstAndLast*)(msg->first_and_last));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

    // foo
    if (msg->oftest2_case == TESTP3__ONE_OF__OFTEST2_FOO)
    {
        lua_pushstring(L, "foo");
        lua_pushnumber(L, (int32_t)(msg->foo));
        lua_settable(L, -3);
    }

    // bar
    if (msg->oftest2_case == TESTP3__ONE_OF__OFTEST2_BAR)
    {
        lua_pushstring(L, "bar");
        lua_pushboolean(L, (protobuf_c_boolean)(msg->bar));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp3__one_of__first_and_last(lua_State* L, Testp3__OneOf__FirstAndLast *msg)
{
    lua_newtable(L);

    // first
    {
        lua_pushstring(L, "first");
        lua_pushstring(L, (char*)(msg->first));
        lua_settable(L, -3);
    }

    // last
    {
        lua_pushstring(L, "last");
        lua_pushstring(L, (char*)(msg->last));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp2__scalars(lua_State* L, Testp2__Scalars *msg)
{
    lua_newtable(L);

    // i32
    lua_pushstring(L, "i32");
    lua_pushnumber(L, (int32_t)(msg->i32));
    lua_settable(L, -3);

    // i64
    lua_pushstring(L, "i64");
    lua_pushnumber(L, (int64_t)(msg->i64));
    lua_settable(L, -3);

    // ui32
    lua_pushstring(L, "ui32");
    lua_pushnumber(L, (uint32_t)(msg->ui32));
    lua_settable(L, -3);

    // ui64
    lua_pushstring(L, "ui64");
    lua_pushnumber(L, (uint64_t)(msg->ui64));
    lua_settable(L, -3);

    // si32
    lua_pushstring(L, "si32");
    lua_pushnumber(L, (int32_t)(msg->si32));
    lua_settable(L, -3);

    // si64
    lua_pushstring(L, "si64");
    lua_pushnumber(L, (int64_t)(msg->si64));
    lua_settable(L, -3);

    // fix32
    lua_pushstring(L, "fix32");
    lua_pushnumber(L, (uint32_t)(msg->fix32));
    lua_settable(L, -3);

    // fix64
    lua_pushstring(L, "fix64");
    lua_pushnumber(L, (uint64_t)(msg->fix64));
    lua_settable(L, -3);

    // sfix32
    lua_pushstring(L, "sfix32");
    lua_pushnumber(L, (int32_t)(msg->sfix32));
    lua_settable(L, -3);

    // sfix64
    lua_pushstring(L, "sfix64");
    lua_pushnumber(L, (int64_t)(msg->sfix64));
    lua_settable(L, -3);

    // b
    lua_pushstring(L, "b");
    lua_pushboolean(L, (protobuf_c_boolean)(msg->b));
    lua_settable(L, -3);

    // s
    lua_pushstring(L, "s");
    lua_pushstring(L, (char*)(msg->s));
    lua_settable(L, -3);

    // bytes
    lua_pushstring(L, "bytes");
    lua_pushProtobufCBinaryData(L, (ProtobufCBinaryData)(msg->bytes));
    lua_settable(L, -3);

    // d
    lua_pushstring(L, "d");
    lua_pushnumber(L, (double)(msg->d));
    lua_settable(L, -3);

    // f
    lua_pushstring(L, "f");
    lua_pushnumber(L, (float)(msg->f));
    lua_settable(L, -3);

}
static void lua_pushtestp2__outer(lua_State* L, Testp2__Outer *msg)
{
    lua_newtable(L);

    // text
    lua_pushstring(L, "text");
    lua_pushstring(L, (char*)(msg->text));
    lua_settable(L, -3);

    // middle
    lua_pushstring(L, "middle");
    lua_pushtestp2__outer__middle(L, (Testp2__Outer__Middle*)(msg->middle));
    lua_settable(L, -3);

}
static void lua_pushtestp2__outer__middle(lua_State* L, Testp2__Outer__Middle *msg)
{
    lua_newtable(L);

    // text
    lua_pushstring(L, "text");
    lua_pushstring(L, (char*)(msg->text));
    lua_settable(L, -3);

    // inner
    lua_pushstring(L, "inner");
    lua_pushtestp2__outer__middle__inner(L, (Testp2__Outer__Middle__Inner*)(msg->inner));
    lua_settable(L, -3);

}
static void lua_pushtestp2__outer__middle__inner(lua_State* L, Testp2__Outer__Middle__Inner *msg)
{
    lua_newtable(L);

    // text
    lua_pushstring(L, "text");
    lua_pushstring(L, (char*)(msg->text));
    lua_settable(L, -3);

}
static void lua_pushtestp2__basic(lua_State* L, Testp2__Basic *msg)
{
    lua_newtable(L);

    // s
    lua_pushstring(L, "s");
    lua_pushstring(L, (char*)(msg->s));
    lua_settable(L, -3);

    // i
    lua_pushstring(L, "i");
    lua_pushnumber(L, (int32_t)(msg->i));
    lua_settable(L, -3);

    // lang
    lua_pushstring(L, "lang");
    lua_pushnumber(L, (Testp2__Language)(msg->lang));
    lua_settable(L, -3);

}
static void lua_pushtestp2__container(lua_State* L, Testp2__Container *msg)
{
    lua_newtable(L);

    // basic_map
    lua_pushstring(L, "basic_map");
    lua_newtable(L);
    int basic_map_size = msg->n_basic_map;
    for (int i = 0; i < basic_map_size; i++)
    {
        Testp2__Container__BasicMapEntry* basic_map_msg = (Testp2__Container__BasicMapEntry*)(msg->basic_map[i]);
        lua_pushtestp2__container__basic_map_entry_repeated(L, basic_map_msg, i + 1);
    }
    lua_settable(L, -3);

    // string_map
    lua_pushstring(L, "string_map");
    lua_newtable(L);
    int string_map_size = msg->n_string_map;
    for (int i = 0; i < string_map_size; i++)
    {
        Testp2__Container__StringMapEntry* string_map_msg = (Testp2__Container__StringMapEntry*)(msg->string_map[i]);
        lua_pushtestp2__container__string_map_entry_repeated(L, string_map_msg, i + 1);
    }
    lua_settable(L, -3);

    // repeated_string
    lua_pushstring(L, "repeated_string");
    lua_newtable(L);
    int repeated_string_size = msg->n_repeated_string;
    for (int i = 0; i < repeated_string_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushstring(L, (char*)(msg->repeated_string[i]));
        lua_settable(L, -3);
    }
    lua_settable(L, -3);

    // repeated_basic
    lua_pushstring(L, "repeated_basic");
    lua_newtable(L);
    int repeated_basic_size = msg->n_repeated_basic;
    for (int i = 0; i < repeated_basic_size; i++)
    {
        Testp2__Basic* repeated_basic_msg = (Testp2__Basic*)(msg->repeated_basic[i]);
        lua_pushtestp2__basic_repeated(L, repeated_basic_msg, i + 1);
    }
    lua_settable(L, -3);

    // optional_string1
    if (msg->optional_string1 != 0)
    {
        lua_pushstring(L, "optional_string1");
        lua_pushstring(L, (char*)(msg->optional_string1));
        lua_settable(L, -3);
    }

    // optional_string2
    if (msg->optional_string2 != 0)
    {
        lua_pushstring(L, "optional_string2");
        lua_pushstring(L, (char*)(msg->optional_string2));
        lua_settable(L, -3);
    }

    // optional_basic1
    if (msg->optional_basic1 != 0)
    {
        lua_pushstring(L, "optional_basic1");
        if (msg->optional_basic1)
        {
            lua_pushtestp2__basic(L, (Testp2__Basic*)(msg->optional_basic1));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

    // optional_basic2
    if (msg->optional_basic2 != 0)
    {
        lua_pushstring(L, "optional_basic2");
        if (msg->optional_basic2)
        {
            lua_pushtestp2__basic(L, (Testp2__Basic*)(msg->optional_basic2));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

}
static void lua_pushtestp2__container__basic_map_entry(lua_State* L, Testp2__Container__BasicMapEntry *msg)
{
    lua_newtable(L);

}
static void lua_pushtestp2__container__string_map_entry(lua_State* L, Testp2__Container__StringMapEntry *msg)
{
    lua_newtable(L);

}
static void lua_pushtestp2__one_of(lua_State* L, Testp2__OneOf *msg)
{
    lua_newtable(L);

    // name
    if (msg->oftest1_case == TESTP2__ONE_OF__OFTEST1_NAME)
    {
        lua_pushstring(L, "name");
        lua_pushstring(L, (char*)(msg->name));
        lua_settable(L, -3);
    }

    // first_and_last
    if (msg->oftest1_case == TESTP2__ONE_OF__OFTEST1_FIRST_AND_LAST)
    {
        lua_pushstring(L, "first_and_last");
        if (msg->first_and_last)
        {
            lua_pushtestp2__one_of__first_and_last(L, (Testp2__OneOf__FirstAndLast*)(msg->first_and_last));
        }
        else
        {
            lua_pushnil(L);
        }
        lua_settable(L, -3);
    }

    // foo
    if (msg->oftest2_case == TESTP2__ONE_OF__OFTEST2_FOO)
    {
        lua_pushstring(L, "foo");
        lua_pushnumber(L, (int32_t)(msg->foo));
        lua_settable(L, -3);
    }

    // bar
    if (msg->oftest2_case == TESTP2__ONE_OF__OFTEST2_BAR)
    {
        lua_pushstring(L, "bar");
        lua_pushboolean(L, (protobuf_c_boolean)(msg->bar));
        lua_settable(L, -3);
    }

}
static void lua_pushtestp2__one_of__first_and_last(lua_State* L, Testp2__OneOf__FirstAndLast *msg)
{
    lua_newtable(L);

    // first
    lua_pushstring(L, "first");
    lua_pushstring(L, (char*)(msg->first));
    lua_settable(L, -3);

    // last
    lua_pushstring(L, "last");
    lua_pushstring(L, (char*)(msg->last));
    lua_settable(L, -3);

}


/******************************************************************************
 * CHECK 
 ******************************************************************************/

// get size of table by counting number of keys
static int lua_tablelen(lua_State* L, int index)
{
    int count = 0;
    lua_pushnil(L);  // first key
    while (lua_next(L, index) != 0) // pops key, pushes key-value pair
    {
        lua_pop(L, 1); // remove value, keep key for next iteration
        count++;
    }
    return count;
}

static ProtobufCBinaryData luaL_checkProtobufCBinaryData(lua_State* L, int narg)
{
    size_t len;
    const char* data = luaL_checklstring(L, narg, &len);

    ProtobufCBinaryData binarydata;
    binarydata.data = (uint8_t*)data;
    binarydata.len = len;
    return binarydata;
}

static int luaL_checkboolean(lua_State* L, int narg) { return lua_toboolean(L, narg); }

static Testp3__Scalars* luaL_checktestp3__scalars(lua_State* L, int narg);
static Testp3__Outer* luaL_checktestp3__outer(lua_State* L, int narg);
static Testp3__Outer__Middle* luaL_checktestp3__outer__middle(lua_State* L, int narg);
static Testp3__Outer__Middle__Inner* luaL_checktestp3__outer__middle__inner(lua_State* L, int narg);
static Testp3__Basic* luaL_checktestp3__basic(lua_State* L, int narg);
static Testp3__Container* luaL_checktestp3__container(lua_State* L, int narg);
static Testp3__Container__BasicMapEntry* luaL_checktestp3__container__basic_map_entry(lua_State* L, int key, int value);
static Testp3__Container__StringMapEntry* luaL_checktestp3__container__string_map_entry(lua_State* L, int key, int value);
static Testp3__OneOf* luaL_checktestp3__one_of(lua_State* L, int narg);
static Testp3__OneOf__FirstAndLast* luaL_checktestp3__one_of__first_and_last(lua_State* L, int narg);
static Testp2__Scalars* luaL_checktestp2__scalars(lua_State* L, int narg);
static Testp2__Outer* luaL_checktestp2__outer(lua_State* L, int narg);
static Testp2__Outer__Middle* luaL_checktestp2__outer__middle(lua_State* L, int narg);
static Testp2__Outer__Middle__Inner* luaL_checktestp2__outer__middle__inner(lua_State* L, int narg);
static Testp2__Basic* luaL_checktestp2__basic(lua_State* L, int narg);
static Testp2__Container* luaL_checktestp2__container(lua_State* L, int narg);
static Testp2__Container__BasicMapEntry* luaL_checktestp2__container__basic_map_entry(lua_State* L, int key, int value);
static Testp2__Container__StringMapEntry* luaL_checktestp2__container__string_map_entry(lua_State* L, int key, int value);
static Testp2__OneOf* luaL_checktestp2__one_of(lua_State* L, int narg);
static Testp2__OneOf__FirstAndLast* luaL_checktestp2__one_of__first_and_last(lua_State* L, int narg);
static int luaL_checktestp3__language(lua_State* L, int narg);
static int luaL_checktestp2__language(lua_State* L, int narg);

static Testp3__Scalars* luaL_checktestp3__scalars(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Scalars *msg = (Testp3__Scalars*)malloc(sizeof(Testp3__Scalars));
    testp3__scalars__init(msg);

    // i32
    lua_pushstring(L, "i32");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->i32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // i64
    lua_pushstring(L, "i64");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->i64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // ui32
    lua_pushstring(L, "ui32");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->ui32 = (uint32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // ui64
    lua_pushstring(L, "ui64");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->ui64 = (uint64_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // si32
    lua_pushstring(L, "si32");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->si32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // si64
    lua_pushstring(L, "si64");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->si64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // fix32
    lua_pushstring(L, "fix32");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->fix32 = (uint32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // fix64
    lua_pushstring(L, "fix64");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->fix64 = (uint64_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // sfix32
    lua_pushstring(L, "sfix32");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->sfix32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // sfix64
    lua_pushstring(L, "sfix64");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->sfix64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // b
    lua_pushstring(L, "b");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->b = (protobuf_c_boolean)luaL_checkboolean(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // s
    lua_pushstring(L, "s");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->s = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // bytes
    lua_pushstring(L, "bytes");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->bytes = (ProtobufCBinaryData)luaL_checkProtobufCBinaryData(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // d
    lua_pushstring(L, "d");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->d = (double)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // f
    lua_pushstring(L, "f");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->f = (float)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__Outer* luaL_checktestp3__outer(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Outer *msg = (Testp3__Outer*)malloc(sizeof(Testp3__Outer));
    testp3__outer__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // middle
    lua_pushstring(L, "middle");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->middle = (Testp3__Outer__Middle*)luaL_checktestp3__outer__middle(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__Outer__Middle* luaL_checktestp3__outer__middle(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Outer__Middle *msg = (Testp3__Outer__Middle*)malloc(sizeof(Testp3__Outer__Middle));
    testp3__outer__middle__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // inner
    lua_pushstring(L, "inner");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->inner = (Testp3__Outer__Middle__Inner*)luaL_checktestp3__outer__middle__inner(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__Outer__Middle__Inner* luaL_checktestp3__outer__middle__inner(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Outer__Middle__Inner *msg = (Testp3__Outer__Middle__Inner*)malloc(sizeof(Testp3__Outer__Middle__Inner));
    testp3__outer__middle__inner__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__Basic* luaL_checktestp3__basic(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Basic *msg = (Testp3__Basic*)malloc(sizeof(Testp3__Basic));
    testp3__basic__init(msg);

    // s
    lua_pushstring(L, "s");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->s = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // i
    lua_pushstring(L, "i");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->i = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // lang
    lua_pushstring(L, "lang");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->lang = (Testp3__Language)luaL_checktestp3__language(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__Container* luaL_checktestp3__container(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__Container *msg = (Testp3__Container*)malloc(sizeof(Testp3__Container));
    testp3__container__init(msg);

    // basic_map [map]
    lua_pushstring(L, "basic_map");
    lua_gettable(L, narg);
    int basic_map_index = lua_gettop(L);
    if (!lua_isnil(L, basic_map_index))
    {
        int basic_map_size = lua_tablelen(L, basic_map_index);
        msg->n_basic_map = basic_map_size;
        msg->basic_map = (Testp3__Container__BasicMapEntry**)malloc(sizeof(Testp3__Container__BasicMapEntry*) * basic_map_size);
        {
            int i = 0;
            lua_pushnil(L);  // first key
            while (lua_next(L, basic_map_index) != 0) // pops key, pushes key-value pair
            {
                msg->basic_map[i++] = (Testp3__Container__BasicMapEntry*)luaL_checktestp3__container__basic_map_entry(L, lua_gettop(L) - 1, lua_gettop(L));
                lua_pop(L, 1); // pop value
            }
        }
    }
    lua_pop(L, 1); // pop table "basic_map"

    // string_map [map]
    lua_pushstring(L, "string_map");
    lua_gettable(L, narg);
    int string_map_index = lua_gettop(L);
    if (!lua_isnil(L, string_map_index))
    {
        int string_map_size = lua_tablelen(L, string_map_index);
        msg->n_string_map = string_map_size;
        msg->string_map = (Testp3__Container__StringMapEntry**)malloc(sizeof(Testp3__Container__StringMapEntry*) * string_map_size);
        {
            int i = 0;
            lua_pushnil(L);  // first key
            while (lua_next(L, string_map_index) != 0) // pops key, pushes key-value pair
            {
                msg->string_map[i++] = (Testp3__Container__StringMapEntry*)luaL_checktestp3__container__string_map_entry(L, lua_gettop(L) - 1, lua_gettop(L));
                lua_pop(L, 1); // pop value
            }
        }
    }
    lua_pop(L, 1); // pop table "string_map"

    // repeated_string1 [repeated]
    lua_pushstring(L, "repeated_string1");
    lua_gettable(L, narg);
    int repeated_string1_index = lua_gettop(L);
    if (!lua_isnil(L, repeated_string1_index))
    {
        int repeated_string1_size = lua_tablelen(L, repeated_string1_index);
        msg->n_repeated_string1 = repeated_string1_size;
        msg->repeated_string1 = (char**)malloc(sizeof(char*) * repeated_string1_size);
        for (int i = 0; i < repeated_string1_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_string1_index); // pops key, pushes value
            msg->repeated_string1[i] = (char*)luaL_checkstring(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_string1"

    // repeated_string2 [repeated]
    lua_pushstring(L, "repeated_string2");
    lua_gettable(L, narg);
    int repeated_string2_index = lua_gettop(L);
    if (!lua_isnil(L, repeated_string2_index))
    {
        int repeated_string2_size = lua_tablelen(L, repeated_string2_index);
        msg->n_repeated_string2 = repeated_string2_size;
        msg->repeated_string2 = (char**)malloc(sizeof(char*) * repeated_string2_size);
        for (int i = 0; i < repeated_string2_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_string2_index); // pops key, pushes value
            msg->repeated_string2[i] = (char*)luaL_checkstring(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_string2"

    // repeated_basic1 [repeated]
    lua_pushstring(L, "repeated_basic1");
    lua_gettable(L, narg);
    int repeated_basic1_index = lua_gettop(L);
    if (!lua_isnil(L, repeated_basic1_index))
    {
        int repeated_basic1_size = lua_tablelen(L, repeated_basic1_index);
        msg->n_repeated_basic1 = repeated_basic1_size;
        msg->repeated_basic1 = (Testp3__Basic**)malloc(sizeof(Testp3__Basic*) * repeated_basic1_size);
        for (int i = 0; i < repeated_basic1_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_basic1_index); // pops key, pushes value
            msg->repeated_basic1[i] = (Testp3__Basic*)luaL_checktestp3__basic(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_basic1"

    // repeated_basic2 [repeated]
    lua_pushstring(L, "repeated_basic2");
    lua_gettable(L, narg);
    int repeated_basic2_index = lua_gettop(L);
    if (!lua_isnil(L, repeated_basic2_index))
    {
        int repeated_basic2_size = lua_tablelen(L, repeated_basic2_index);
        msg->n_repeated_basic2 = repeated_basic2_size;
        msg->repeated_basic2 = (Testp3__Basic**)malloc(sizeof(Testp3__Basic*) * repeated_basic2_size);
        for (int i = 0; i < repeated_basic2_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_basic2_index); // pops key, pushes value
            msg->repeated_basic2[i] = (Testp3__Basic*)luaL_checktestp3__basic(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_basic2"

    return msg;
}

static Testp3__Container__BasicMapEntry* luaL_checktestp3__container__basic_map_entry(lua_State* L, int key, int value)
{
    Testp3__Container__BasicMapEntry *msg = (Testp3__Container__BasicMapEntry*)malloc(sizeof(Testp3__Container__BasicMapEntry));
    testp3__container__basic_map_entry__init(msg);
    msg->key = (char*)luaL_checkstring(L, key);
    msg->value = (Testp3__Basic*)luaL_checktestp3__basic(L, value);
    return msg;
}

static Testp3__Container__StringMapEntry* luaL_checktestp3__container__string_map_entry(lua_State* L, int key, int value)
{
    Testp3__Container__StringMapEntry *msg = (Testp3__Container__StringMapEntry*)malloc(sizeof(Testp3__Container__StringMapEntry));
    testp3__container__string_map_entry__init(msg);
    msg->key = (char*)luaL_checkstring(L, key);
    msg->value = (char*)luaL_checkstring(L, value);
    return msg;
}

static Testp3__OneOf* luaL_checktestp3__one_of(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__OneOf *msg = (Testp3__OneOf*)malloc(sizeof(Testp3__OneOf));
    testp3__one_of__init(msg);

    // name
    lua_pushstring(L, "name");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest1_case = TESTP3__ONE_OF__OFTEST1_NAME;
        msg->name = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // first_and_last
    lua_pushstring(L, "first_and_last");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest1_case = TESTP3__ONE_OF__OFTEST1_FIRST_AND_LAST;
        msg->first_and_last = (Testp3__OneOf__FirstAndLast*)luaL_checktestp3__one_of__first_and_last(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // foo
    lua_pushstring(L, "foo");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest2_case = TESTP3__ONE_OF__OFTEST2_FOO;
        msg->foo = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // bar
    lua_pushstring(L, "bar");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest2_case = TESTP3__ONE_OF__OFTEST2_BAR;
        msg->bar = (protobuf_c_boolean)luaL_checkboolean(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp3__OneOf__FirstAndLast* luaL_checktestp3__one_of__first_and_last(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp3__OneOf__FirstAndLast *msg = (Testp3__OneOf__FirstAndLast*)malloc(sizeof(Testp3__OneOf__FirstAndLast));
    testp3__one_of__first_and_last__init(msg);

    // first
    lua_pushstring(L, "first");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->first = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // last
    lua_pushstring(L, "last");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->last = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp2__Scalars* luaL_checktestp2__scalars(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Scalars *msg = (Testp2__Scalars*)malloc(sizeof(Testp2__Scalars));
    testp2__scalars__init(msg);

    // i32
    lua_pushstring(L, "i32");
    lua_gettable(L, narg);
    msg->i32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // i64
    lua_pushstring(L, "i64");
    lua_gettable(L, narg);
    msg->i64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // ui32
    lua_pushstring(L, "ui32");
    lua_gettable(L, narg);
    msg->ui32 = (uint32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // ui64
    lua_pushstring(L, "ui64");
    lua_gettable(L, narg);
    msg->ui64 = (uint64_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // si32
    lua_pushstring(L, "si32");
    lua_gettable(L, narg);
    msg->si32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // si64
    lua_pushstring(L, "si64");
    lua_gettable(L, narg);
    msg->si64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // fix32
    lua_pushstring(L, "fix32");
    lua_gettable(L, narg);
    msg->fix32 = (uint32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // fix64
    lua_pushstring(L, "fix64");
    lua_gettable(L, narg);
    msg->fix64 = (uint64_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // sfix32
    lua_pushstring(L, "sfix32");
    lua_gettable(L, narg);
    msg->sfix32 = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // sfix64
    lua_pushstring(L, "sfix64");
    lua_gettable(L, narg);
    msg->sfix64 = (int64_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // b
    lua_pushstring(L, "b");
    lua_gettable(L, narg);
    msg->b = (protobuf_c_boolean)luaL_checkboolean(L, lua_gettop(L));
    lua_pop(L, 1);

    // s
    lua_pushstring(L, "s");
    lua_gettable(L, narg);
    msg->s = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // bytes
    lua_pushstring(L, "bytes");
    lua_gettable(L, narg);
    msg->bytes = (ProtobufCBinaryData)luaL_checkProtobufCBinaryData(L, lua_gettop(L));
    lua_pop(L, 1);

    // d
    lua_pushstring(L, "d");
    lua_gettable(L, narg);
    msg->d = (double)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // f
    lua_pushstring(L, "f");
    lua_gettable(L, narg);
    msg->f = (float)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}

static Testp2__Outer* luaL_checktestp2__outer(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Outer *msg = (Testp2__Outer*)malloc(sizeof(Testp2__Outer));
    testp2__outer__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // middle
    lua_pushstring(L, "middle");
    lua_gettable(L, narg);
    msg->middle = (Testp2__Outer__Middle*)luaL_checktestp2__outer__middle(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}

static Testp2__Outer__Middle* luaL_checktestp2__outer__middle(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Outer__Middle *msg = (Testp2__Outer__Middle*)malloc(sizeof(Testp2__Outer__Middle));
    testp2__outer__middle__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // inner
    lua_pushstring(L, "inner");
    lua_gettable(L, narg);
    msg->inner = (Testp2__Outer__Middle__Inner*)luaL_checktestp2__outer__middle__inner(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}

static Testp2__Outer__Middle__Inner* luaL_checktestp2__outer__middle__inner(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Outer__Middle__Inner *msg = (Testp2__Outer__Middle__Inner*)malloc(sizeof(Testp2__Outer__Middle__Inner));
    testp2__outer__middle__inner__init(msg);

    // text
    lua_pushstring(L, "text");
    lua_gettable(L, narg);
    msg->text = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}

static Testp2__Basic* luaL_checktestp2__basic(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Basic *msg = (Testp2__Basic*)malloc(sizeof(Testp2__Basic));
    testp2__basic__init(msg);

    // s
    lua_pushstring(L, "s");
    lua_gettable(L, narg);
    msg->s = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // i
    lua_pushstring(L, "i");
    lua_gettable(L, narg);
    msg->i = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // lang
    lua_pushstring(L, "lang");
    lua_gettable(L, narg);
    msg->lang = (Testp2__Language)luaL_checktestp2__language(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}

static Testp2__Container* luaL_checktestp2__container(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__Container *msg = (Testp2__Container*)malloc(sizeof(Testp2__Container));
    testp2__container__init(msg);

    // basic_map [map]
    lua_pushstring(L, "basic_map");
    lua_gettable(L, narg);
    int basic_map_index = lua_gettop(L);
    if (!lua_istable(L, basic_map_index))
    {
        luaL_error(L, "Expected value for key 'basic_map' to be a table");
        return 0;
    }
    {
        int basic_map_size = lua_tablelen(L, basic_map_index);
        msg->n_basic_map = basic_map_size;
        msg->basic_map = (Testp2__Container__BasicMapEntry**)malloc(sizeof(Testp2__Container__BasicMapEntry*) * basic_map_size);
        {
            int i = 0;
            lua_pushnil(L);  // first key
            while (lua_next(L, basic_map_index) != 0) // pops key, pushes key-value pair
            {
                msg->basic_map[i++] = (Testp2__Container__BasicMapEntry*)luaL_checktestp2__container__basic_map_entry(L, lua_gettop(L) - 1, lua_gettop(L));
                lua_pop(L, 1); // pop value
            }
        }
    }
    lua_pop(L, 1); // pop table "basic_map"

    // string_map [map]
    lua_pushstring(L, "string_map");
    lua_gettable(L, narg);
    int string_map_index = lua_gettop(L);
    if (!lua_istable(L, string_map_index))
    {
        luaL_error(L, "Expected value for key 'string_map' to be a table");
        return 0;
    }
    {
        int string_map_size = lua_tablelen(L, string_map_index);
        msg->n_string_map = string_map_size;
        msg->string_map = (Testp2__Container__StringMapEntry**)malloc(sizeof(Testp2__Container__StringMapEntry*) * string_map_size);
        {
            int i = 0;
            lua_pushnil(L);  // first key
            while (lua_next(L, string_map_index) != 0) // pops key, pushes key-value pair
            {
                msg->string_map[i++] = (Testp2__Container__StringMapEntry*)luaL_checktestp2__container__string_map_entry(L, lua_gettop(L) - 1, lua_gettop(L));
                lua_pop(L, 1); // pop value
            }
        }
    }
    lua_pop(L, 1); // pop table "string_map"

    // repeated_string [repeated]
    lua_pushstring(L, "repeated_string");
    lua_gettable(L, narg);
    int repeated_string_index = lua_gettop(L);
    if (!lua_istable(L, repeated_string_index))
    {
        luaL_error(L, "Expected value for key 'repeated_string' to be a table");
        return 0;
    }
    {
        int repeated_string_size = lua_tablelen(L, repeated_string_index);
        msg->n_repeated_string = repeated_string_size;
        msg->repeated_string = (char**)malloc(sizeof(char*) * repeated_string_size);
        for (int i = 0; i < repeated_string_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_string_index); // pops key, pushes value
            msg->repeated_string[i] = (char*)luaL_checkstring(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_string"

    // repeated_basic [repeated]
    lua_pushstring(L, "repeated_basic");
    lua_gettable(L, narg);
    int repeated_basic_index = lua_gettop(L);
    if (!lua_istable(L, repeated_basic_index))
    {
        luaL_error(L, "Expected value for key 'repeated_basic' to be a table");
        return 0;
    }
    {
        int repeated_basic_size = lua_tablelen(L, repeated_basic_index);
        msg->n_repeated_basic = repeated_basic_size;
        msg->repeated_basic = (Testp2__Basic**)malloc(sizeof(Testp2__Basic*) * repeated_basic_size);
        for (int i = 0; i < repeated_basic_size; i++)
        {
            lua_pushnumber(L, i + 1); // key
            lua_gettable(L, repeated_basic_index); // pops key, pushes value
            msg->repeated_basic[i] = (Testp2__Basic*)luaL_checktestp2__basic(L, lua_gettop(L));
            lua_pop(L, 1); // pop value
        }
    }
    lua_pop(L, 1); // pop table "repeated_basic"

    // optional_string1
    lua_pushstring(L, "optional_string1");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->optional_string1 = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // optional_string2
    lua_pushstring(L, "optional_string2");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->optional_string2 = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // optional_basic1
    lua_pushstring(L, "optional_basic1");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->optional_basic1 = (Testp2__Basic*)luaL_checktestp2__basic(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // optional_basic2
    lua_pushstring(L, "optional_basic2");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->optional_basic2 = (Testp2__Basic*)luaL_checktestp2__basic(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp2__Container__BasicMapEntry* luaL_checktestp2__container__basic_map_entry(lua_State* L, int key, int value)
{
    Testp2__Container__BasicMapEntry *msg = (Testp2__Container__BasicMapEntry*)malloc(sizeof(Testp2__Container__BasicMapEntry));
    testp2__container__basic_map_entry__init(msg);
    msg->key = (char*)luaL_checkstring(L, key);
    msg->value = (Testp2__Basic*)luaL_checktestp2__basic(L, value);
    return msg;
}

static Testp2__Container__StringMapEntry* luaL_checktestp2__container__string_map_entry(lua_State* L, int key, int value)
{
    Testp2__Container__StringMapEntry *msg = (Testp2__Container__StringMapEntry*)malloc(sizeof(Testp2__Container__StringMapEntry));
    testp2__container__string_map_entry__init(msg);
    msg->key = (char*)luaL_checkstring(L, key);
    msg->value = (char*)luaL_checkstring(L, value);
    return msg;
}

static Testp2__OneOf* luaL_checktestp2__one_of(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__OneOf *msg = (Testp2__OneOf*)malloc(sizeof(Testp2__OneOf));
    testp2__one_of__init(msg);

    // name
    lua_pushstring(L, "name");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest1_case = TESTP2__ONE_OF__OFTEST1_NAME;
        msg->name = (char*)luaL_checkstring(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // first_and_last
    lua_pushstring(L, "first_and_last");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest1_case = TESTP2__ONE_OF__OFTEST1_FIRST_AND_LAST;
        msg->first_and_last = (Testp2__OneOf__FirstAndLast*)luaL_checktestp2__one_of__first_and_last(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // foo
    lua_pushstring(L, "foo");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest2_case = TESTP2__ONE_OF__OFTEST2_FOO;
        msg->foo = (int32_t)luaL_checknumber(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    // bar
    lua_pushstring(L, "bar");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->oftest2_case = TESTP2__ONE_OF__OFTEST2_BAR;
        msg->bar = (protobuf_c_boolean)luaL_checkboolean(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}

static Testp2__OneOf__FirstAndLast* luaL_checktestp2__one_of__first_and_last(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Testp2__OneOf__FirstAndLast *msg = (Testp2__OneOf__FirstAndLast*)malloc(sizeof(Testp2__OneOf__FirstAndLast));
    testp2__one_of__first_and_last__init(msg);

    // first
    lua_pushstring(L, "first");
    lua_gettable(L, narg);
    msg->first = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // last
    lua_pushstring(L, "last");
    lua_gettable(L, narg);
    msg->last = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}


static int luaL_checktestp3__language(lua_State* L, int narg)
{
    if (lua_isnumber(L, narg))
    {
        return lua_tonumber(L, narg);
    }
    else if (lua_isstring(L, narg))
    {
        const ProtobufCEnumDescriptor desc = testp3__language__descriptor;
        const char* s = lua_tostring(L, narg);
        const ProtobufCEnumValue* e = protobuf_c_enum_descriptor_get_value_by_name(&desc, s);
        if (e == 0)
        {
            return luaL_error(L, "Unable to convert %s to testp3__language", s);
        }
        return e->value;
    }
    else
    {
        const char* tn = lua_typename(L, narg);
        return luaL_error(L, "Unable to convert value of type %s at index %d to testp3__language", tn, narg);
    }
}
static int luaL_checktestp2__language(lua_State* L, int narg)
{
    if (lua_isnumber(L, narg))
    {
        return lua_tonumber(L, narg);
    }
    else if (lua_isstring(L, narg))
    {
        const ProtobufCEnumDescriptor desc = testp2__language__descriptor;
        const char* s = lua_tostring(L, narg);
        const ProtobufCEnumValue* e = protobuf_c_enum_descriptor_get_value_by_name(&desc, s);
        if (e == 0)
        {
            return luaL_error(L, "Unable to convert %s to testp2__language", s);
        }
        return e->value;
    }
    else
    {
        const char* tn = lua_typename(L, narg);
        return luaL_error(L, "Unable to convert value of type %s at index %d to testp2__language", tn, narg);
    }
}


/******************************************************************************
 * FREE 
 ******************************************************************************/

static void free_testp3__scalars(Testp3__Scalars* msg);
static void free_testp3__outer(Testp3__Outer* msg);
static void free_testp3__outer__middle(Testp3__Outer__Middle* msg);
static void free_testp3__outer__middle__inner(Testp3__Outer__Middle__Inner* msg);
static void free_testp3__basic(Testp3__Basic* msg);
static void free_testp3__container(Testp3__Container* msg);
static void free_testp3__container__basic_map_entry(Testp3__Container__BasicMapEntry* msg);
static void free_testp3__container__string_map_entry(Testp3__Container__StringMapEntry* msg);
static void free_testp3__one_of(Testp3__OneOf* msg);
static void free_testp3__one_of__first_and_last(Testp3__OneOf__FirstAndLast* msg);
static void free_testp2__scalars(Testp2__Scalars* msg);
static void free_testp2__outer(Testp2__Outer* msg);
static void free_testp2__outer__middle(Testp2__Outer__Middle* msg);
static void free_testp2__outer__middle__inner(Testp2__Outer__Middle__Inner* msg);
static void free_testp2__basic(Testp2__Basic* msg);
static void free_testp2__container(Testp2__Container* msg);
static void free_testp2__container__basic_map_entry(Testp2__Container__BasicMapEntry* msg);
static void free_testp2__container__string_map_entry(Testp2__Container__StringMapEntry* msg);
static void free_testp2__one_of(Testp2__OneOf* msg);
static void free_testp2__one_of__first_and_last(Testp2__OneOf__FirstAndLast* msg);

static void free_ProtobufCBinaryData(ProtobufCBinaryData) {};
static void free_number(int32_t) {};
static void free_string(char*) {};
static void free_bool(bool) {};
static void free_boolean(bool) {};

static void free_testp3__scalars(Testp3__Scalars* msg)
{
    if (msg == 0x0) return;
    free_number(msg->i32);
    free_number(msg->i64);
    free_number(msg->ui32);
    free_number(msg->ui64);
    free_number(msg->si32);
    free_number(msg->si64);
    free_number(msg->fix32);
    free_number(msg->fix64);
    free_number(msg->sfix32);
    free_number(msg->sfix64);
    free_boolean(msg->b);
    free_string(msg->s);
    free_ProtobufCBinaryData(msg->bytes);
    free_number(msg->d);
    free_number(msg->f);
    free(msg);
}
static void free_testp3__outer(Testp3__Outer* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free_testp3__outer__middle(msg->middle);
    free(msg);
}
static void free_testp3__outer__middle(Testp3__Outer__Middle* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free_testp3__outer__middle__inner(msg->inner);
    free(msg);
}
static void free_testp3__outer__middle__inner(Testp3__Outer__Middle__Inner* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free(msg);
}
static void free_testp3__basic(Testp3__Basic* msg)
{
    if (msg == 0x0) return;
    free_string(msg->s);
    free_number(msg->i);
    free_number(msg->lang);
    free(msg);
}
static void free_testp3__container(Testp3__Container* msg)
{
    if (msg == 0x0) return;
    int basic_map_size = msg->n_basic_map;
    for (int i = 0; i < basic_map_size; i++)
    {
        free_testp3__container__basic_map_entry(msg->basic_map[i]);
    }
    free(msg->basic_map);
    int string_map_size = msg->n_string_map;
    for (int i = 0; i < string_map_size; i++)
    {
        free_testp3__container__string_map_entry(msg->string_map[i]);
    }
    free(msg->string_map);
    int repeated_string1_size = msg->n_repeated_string1;
    for (int i = 0; i < repeated_string1_size; i++)
    {
        free_string(msg->repeated_string1[i]);
    }
    free(msg->repeated_string1);
    int repeated_string2_size = msg->n_repeated_string2;
    for (int i = 0; i < repeated_string2_size; i++)
    {
        free_string(msg->repeated_string2[i]);
    }
    free(msg->repeated_string2);
    int repeated_basic1_size = msg->n_repeated_basic1;
    for (int i = 0; i < repeated_basic1_size; i++)
    {
        free_testp3__basic(msg->repeated_basic1[i]);
    }
    free(msg->repeated_basic1);
    int repeated_basic2_size = msg->n_repeated_basic2;
    for (int i = 0; i < repeated_basic2_size; i++)
    {
        free_testp3__basic(msg->repeated_basic2[i]);
    }
    free(msg->repeated_basic2);
    free(msg);
}
static void free_testp3__container__basic_map_entry(Testp3__Container__BasicMapEntry* msg)
{
    if (msg == 0x0) return;
    free(msg);
}
static void free_testp3__container__string_map_entry(Testp3__Container__StringMapEntry* msg)
{
    if (msg == 0x0) return;
    free(msg);
}
static void free_testp3__one_of(Testp3__OneOf* msg)
{
    if (msg == 0x0) return;
    free_string(msg->name);
    free_testp3__one_of__first_and_last(msg->first_and_last);
    free_number(msg->foo);
    free_boolean(msg->bar);
    free(msg);
}
static void free_testp3__one_of__first_and_last(Testp3__OneOf__FirstAndLast* msg)
{
    if (msg == 0x0) return;
    free_string(msg->first);
    free_string(msg->last);
    free(msg);
}
static void free_testp2__scalars(Testp2__Scalars* msg)
{
    if (msg == 0x0) return;
    free_number(msg->i32);
    free_number(msg->i64);
    free_number(msg->ui32);
    free_number(msg->ui64);
    free_number(msg->si32);
    free_number(msg->si64);
    free_number(msg->fix32);
    free_number(msg->fix64);
    free_number(msg->sfix32);
    free_number(msg->sfix64);
    free_boolean(msg->b);
    free_string(msg->s);
    free_ProtobufCBinaryData(msg->bytes);
    free_number(msg->d);
    free_number(msg->f);
    free(msg);
}
static void free_testp2__outer(Testp2__Outer* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free_testp2__outer__middle(msg->middle);
    free(msg);
}
static void free_testp2__outer__middle(Testp2__Outer__Middle* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free_testp2__outer__middle__inner(msg->inner);
    free(msg);
}
static void free_testp2__outer__middle__inner(Testp2__Outer__Middle__Inner* msg)
{
    if (msg == 0x0) return;
    free_string(msg->text);
    free(msg);
}
static void free_testp2__basic(Testp2__Basic* msg)
{
    if (msg == 0x0) return;
    free_string(msg->s);
    free_number(msg->i);
    free_number(msg->lang);
    free(msg);
}
static void free_testp2__container(Testp2__Container* msg)
{
    if (msg == 0x0) return;
    int basic_map_size = msg->n_basic_map;
    for (int i = 0; i < basic_map_size; i++)
    {
        free_testp2__container__basic_map_entry(msg->basic_map[i]);
    }
    free(msg->basic_map);
    int string_map_size = msg->n_string_map;
    for (int i = 0; i < string_map_size; i++)
    {
        free_testp2__container__string_map_entry(msg->string_map[i]);
    }
    free(msg->string_map);
    int repeated_string_size = msg->n_repeated_string;
    for (int i = 0; i < repeated_string_size; i++)
    {
        free_string(msg->repeated_string[i]);
    }
    free(msg->repeated_string);
    int repeated_basic_size = msg->n_repeated_basic;
    for (int i = 0; i < repeated_basic_size; i++)
    {
        free_testp2__basic(msg->repeated_basic[i]);
    }
    free(msg->repeated_basic);
    free_string(msg->optional_string1);
    free_string(msg->optional_string2);
    free_testp2__basic(msg->optional_basic1);
    free_testp2__basic(msg->optional_basic2);
    free(msg);
}
static void free_testp2__container__basic_map_entry(Testp2__Container__BasicMapEntry* msg)
{
    if (msg == 0x0) return;
    free(msg);
}
static void free_testp2__container__string_map_entry(Testp2__Container__StringMapEntry* msg)
{
    if (msg == 0x0) return;
    free(msg);
}
static void free_testp2__one_of(Testp2__OneOf* msg)
{
    if (msg == 0x0) return;
    free_string(msg->name);
    free_testp2__one_of__first_and_last(msg->first_and_last);
    free_number(msg->foo);
    free_boolean(msg->bar);
    free(msg);
}
static void free_testp2__one_of__first_and_last(Testp2__OneOf__FirstAndLast* msg)
{
    if (msg == 0x0) return;
    free_string(msg->first);
    free_string(msg->last);
    free(msg);
}



/******************************************************************************
 * ENCODE AND DECODE
 ******************************************************************************/

// testproto3.proto
static int DecodeTestp3__Scalars(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp3__Scalars *msg = testp3__scalars__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp3__scalars(L, msg);
        testp3__scalars__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp3__Scalars(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp3__Scalars *msg = luaL_checktestp3__scalars(L, 1);

    size_t scalars_packed_size = testp3__scalars__get_packed_size(msg);
    char* buffer = (char*)malloc(scalars_packed_size);
    testp3__scalars__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, scalars_packed_size);
    free(buffer);

    free_testp3__scalars(msg);

    return 1;
}

// testproto3.proto
static int DecodeTestp3__Outer(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp3__Outer *msg = testp3__outer__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp3__outer(L, msg);
        testp3__outer__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp3__Outer(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp3__Outer *msg = luaL_checktestp3__outer(L, 1);

    size_t outer_packed_size = testp3__outer__get_packed_size(msg);
    char* buffer = (char*)malloc(outer_packed_size);
    testp3__outer__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, outer_packed_size);
    free(buffer);

    free_testp3__outer(msg);

    return 1;
}

// testproto3.proto
static int DecodeTestp3__Basic(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp3__Basic *msg = testp3__basic__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp3__basic(L, msg);
        testp3__basic__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp3__Basic(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp3__Basic *msg = luaL_checktestp3__basic(L, 1);

    size_t basic_packed_size = testp3__basic__get_packed_size(msg);
    char* buffer = (char*)malloc(basic_packed_size);
    testp3__basic__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, basic_packed_size);
    free(buffer);

    free_testp3__basic(msg);

    return 1;
}

// testproto3.proto
static int DecodeTestp3__Container(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp3__Container *msg = testp3__container__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp3__container(L, msg);
        testp3__container__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp3__Container(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp3__Container *msg = luaL_checktestp3__container(L, 1);

    size_t container_packed_size = testp3__container__get_packed_size(msg);
    char* buffer = (char*)malloc(container_packed_size);
    testp3__container__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, container_packed_size);
    free(buffer);

    free_testp3__container(msg);

    return 1;
}

// testproto3.proto
static int DecodeTestp3__OneOf(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp3__OneOf *msg = testp3__one_of__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp3__one_of(L, msg);
        testp3__one_of__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp3__OneOf(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp3__OneOf *msg = luaL_checktestp3__one_of(L, 1);

    size_t oneof_packed_size = testp3__one_of__get_packed_size(msg);
    char* buffer = (char*)malloc(oneof_packed_size);
    testp3__one_of__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, oneof_packed_size);
    free(buffer);

    free_testp3__one_of(msg);

    return 1;
}

// testproto2.proto
static int DecodeTestp2__Scalars(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp2__Scalars *msg = testp2__scalars__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp2__scalars(L, msg);
        testp2__scalars__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp2__Scalars(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp2__Scalars *msg = luaL_checktestp2__scalars(L, 1);

    size_t scalars_packed_size = testp2__scalars__get_packed_size(msg);
    char* buffer = (char*)malloc(scalars_packed_size);
    testp2__scalars__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, scalars_packed_size);
    free(buffer);

    free_testp2__scalars(msg);

    return 1;
}

// testproto2.proto
static int DecodeTestp2__Outer(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp2__Outer *msg = testp2__outer__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp2__outer(L, msg);
        testp2__outer__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp2__Outer(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp2__Outer *msg = luaL_checktestp2__outer(L, 1);

    size_t outer_packed_size = testp2__outer__get_packed_size(msg);
    char* buffer = (char*)malloc(outer_packed_size);
    testp2__outer__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, outer_packed_size);
    free(buffer);

    free_testp2__outer(msg);

    return 1;
}

// testproto2.proto
static int DecodeTestp2__Basic(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp2__Basic *msg = testp2__basic__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp2__basic(L, msg);
        testp2__basic__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp2__Basic(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp2__Basic *msg = luaL_checktestp2__basic(L, 1);

    size_t basic_packed_size = testp2__basic__get_packed_size(msg);
    char* buffer = (char*)malloc(basic_packed_size);
    testp2__basic__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, basic_packed_size);
    free(buffer);

    free_testp2__basic(msg);

    return 1;
}

// testproto2.proto
static int DecodeTestp2__Container(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp2__Container *msg = testp2__container__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp2__container(L, msg);
        testp2__container__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp2__Container(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp2__Container *msg = luaL_checktestp2__container(L, 1);

    size_t container_packed_size = testp2__container__get_packed_size(msg);
    char* buffer = (char*)malloc(container_packed_size);
    testp2__container__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, container_packed_size);
    free(buffer);

    free_testp2__container(msg);

    return 1;
}

// testproto2.proto
static int DecodeTestp2__OneOf(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Testp2__OneOf *msg = testp2__one_of__unpack(0, data_length, (uint8_t*)data);
    if (msg != 0)
    {
        lua_pushtestp2__one_of(L, msg);
        testp2__one_of__free_unpacked(msg, 0);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}
static int EncodeTestp2__OneOf(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Testp2__OneOf *msg = luaL_checktestp2__one_of(L, 1);

    size_t oneof_packed_size = testp2__one_of__get_packed_size(msg);
    char* buffer = (char*)malloc(oneof_packed_size);
    testp2__one_of__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, oneof_packed_size);
    free(buffer);

    free_testp2__one_of(msg);

    return 1;
}


static const luaL_reg Module_methods[] =
{
    {"encode_testp3_scalars", EncodeTestp3__Scalars },
    {"decode_testp3_scalars", DecodeTestp3__Scalars },
    {"encode_testp3_outer", EncodeTestp3__Outer },
    {"decode_testp3_outer", DecodeTestp3__Outer },
    {"encode_testp3_basic", EncodeTestp3__Basic },
    {"decode_testp3_basic", DecodeTestp3__Basic },
    {"encode_testp3_container", EncodeTestp3__Container },
    {"decode_testp3_container", DecodeTestp3__Container },
    {"encode_testp3_oneof", EncodeTestp3__OneOf },
    {"decode_testp3_oneof", DecodeTestp3__OneOf },
    {"encode_testp2_scalars", EncodeTestp2__Scalars },
    {"decode_testp2_scalars", DecodeTestp2__Scalars },
    {"encode_testp2_outer", EncodeTestp2__Outer },
    {"decode_testp2_outer", DecodeTestp2__Outer },
    {"encode_testp2_basic", EncodeTestp2__Basic },
    {"decode_testp2_basic", DecodeTestp2__Basic },
    {"encode_testp2_container", EncodeTestp2__Container },
    {"decode_testp2_container", DecodeTestp2__Container },
    {"encode_testp2_oneof", EncodeTestp2__OneOf },
    {"decode_testp2_oneof", DecodeTestp2__OneOf },
    {0,0}
};

static void LuaInit(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);

    #define SETCONSTANT(name, val) \
    lua_pushnumber(L, (lua_Number) val); \
    lua_setfield(L, -2, #name);

    // Language
    SETCONSTANT(TESTP3__LANGUAGE_LANGUAGE_LUA, TESTP3__LANGUAGE__LANGUAGE_LUA);
    SETCONSTANT(TESTP3__LANGUAGE_LANGUAGE_CPP, TESTP3__LANGUAGE__LANGUAGE_CPP);
    SETCONSTANT(TESTP3__LANGUAGE_LANGUAGE_JAVA, TESTP3__LANGUAGE__LANGUAGE_JAVA);
    // Language
    SETCONSTANT(TESTP2__LANGUAGE_LANGUAGE_LUA, TESTP2__LANGUAGE__LANGUAGE_LUA);
    SETCONSTANT(TESTP2__LANGUAGE_LANGUAGE_CPP, TESTP2__LANGUAGE__LANGUAGE_CPP);
    SETCONSTANT(TESTP2__LANGUAGE_LANGUAGE_JAVA, TESTP2__LANGUAGE__LANGUAGE_JAVA);
    #undef SETCONSTANT

    lua_pop(L, 1);
}

static dmExtension::Result InitializeProto(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizProto(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeProto, 0, 0, FinalizProto)
