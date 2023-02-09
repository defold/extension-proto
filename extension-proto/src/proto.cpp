#define EXTENSION_NAME Proto
#define LIB_NAME "Proto"
#define MODULE_NAME "proto"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>
#include <stdlib.h>


#include "item.pb-c.h"
#include "inventory.pb-c.h"



/******************************************************************************
 * PUSH
 ******************************************************************************/

static void lua_pushgame__item(lua_State* L, Game__Item *msg);
static void lua_pushgame__inventory(lua_State* L, Game__Inventory *msg);

static void lua_pushProtobufCBinaryData(lua_State* L, ProtobufCBinaryData binarydata)
{
    lua_pushlstring(L, (const char*)binarydata.data, binarydata.len);
}

static void lua_pushgame__item(lua_State* L, Game__Item *msg)
{
    lua_newtable(L);

    // id
    lua_pushstring(L, "id");
    lua_pushnumber(L, (int32_t)(msg->id));
    lua_settable(L, -3);

    // name
    lua_pushstring(L, "name");
    lua_pushstring(L, (char*)(msg->name));
    lua_settable(L, -3);

    // weight
    lua_pushstring(L, "weight");
    lua_pushnumber(L, (float)(msg->weight));
    lua_settable(L, -3);

    // type
    lua_pushstring(L, "type");
    lua_pushnumber(L, (Game__Item__ItemType)(msg->type));
    lua_settable(L, -3);

    // magic
    if (msg->has_magic)
    {
        lua_pushstring(L, "magic");
        lua_pushboolean(L, (protobuf_c_boolean)(msg->magic));
        lua_settable(L, -3);
    }

}
static void lua_pushgame__inventory(lua_State* L, Game__Inventory *msg)
{
    lua_newtable(L);

    // capacity
    lua_pushstring(L, "capacity");
    lua_pushnumber(L, (int32_t)(msg->capacity));
    lua_settable(L, -3);

    // items
    lua_pushstring(L, "items");
    lua_newtable(L);
    int items_size = msg->n_items;
    for (int i = 0; i < items_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushgame__item(L, (Game__Item*)(msg->items[i]));
        lua_settable(L, -3);
    }
    lua_settable(L, -3);

}


/******************************************************************************
 * CHECK 
 ******************************************************************************/

static int luaL_checkboolean(lua_State* L, int narg) { return lua_toboolean(L, narg); }

static Game__Item* luaL_checkgame__item(lua_State* L, int narg);
static Game__Inventory* luaL_checkgame__inventory(lua_State* L, int narg);

static ProtobufCBinaryData luaL_checkProtobufCBinaryData(lua_State* L, int narg)
{
    size_t len;
    const char* data = luaL_checklstring(L, narg, &len);

    ProtobufCBinaryData binarydata;
    binarydata.data = (uint8_t*)data;
    binarydata.len = len;
    return binarydata;
}

static Game__Item* luaL_checkgame__item(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Game__Item *msg = (Game__Item*)malloc(sizeof(Game__Item));
    game__item__init(msg);

    // id
    lua_pushstring(L, "id");
    lua_gettable(L, narg);
    msg->id = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // name
    lua_pushstring(L, "name");
    lua_gettable(L, narg);
    msg->name = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);

    // weight
    lua_pushstring(L, "weight");
    lua_gettable(L, narg);
    msg->weight = (float)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // type
    lua_pushstring(L, "type");
    lua_gettable(L, narg);
    msg->type = (Game__Item__ItemType)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // magic
    lua_pushstring(L, "magic");
    lua_gettable(L, narg);
    if (!lua_isnil(L, lua_gettop(L)))
    {
        msg->has_magic = 1;
        msg->magic = (protobuf_c_boolean)luaL_checkboolean(L, lua_gettop(L));
    }
    lua_pop(L, 1);

    return msg;
}
static Game__Inventory* luaL_checkgame__inventory(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Game__Inventory *msg = (Game__Inventory*)malloc(sizeof(Game__Inventory));
    game__inventory__init(msg);

    // capacity
    lua_pushstring(L, "capacity");
    lua_gettable(L, narg);
    msg->capacity = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    // items
    lua_pushstring(L, "items");
    lua_gettable(L, narg);
    int items_size = lua_objlen(L, lua_gettop(L));
    int items_index = lua_gettop(L);
    msg->n_items = items_size;
    msg->items = (Game__Item**)malloc(sizeof(Game__Item*) * items_size);
    for (int i = 0; i < items_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_gettable(L, items_index);
        msg->items[i] = (Game__Item*)luaL_checkgame__item(L, lua_gettop(L));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);

    return msg;
}



/******************************************************************************
 * FREE 
 ******************************************************************************/

static void free_game__item(Game__Item* msg);
static void free_game__inventory(Game__Inventory* msg);

static void free_ProtobufCBinaryData(ProtobufCBinaryData) {};
static void free_number(int32_t) {};
static void free_string(char*) {};
static void free_bool(bool) {};
static void free_boolean(bool) {};

static void free_game__item(Game__Item* msg)
{
    free_number(msg->id);
    free_string(msg->name);
    free_number(msg->weight);
    free_number(msg->type);
    free_boolean(msg->magic);
    free(msg);
}
static void free_game__inventory(Game__Inventory* msg)
{
    free_number(msg->capacity);
    int items_size = msg->n_items;
    for (int i = 0; i < items_size; i++)
    {
        free_game__item(msg->items[i]);
    }
    free(msg->items);
    free(msg);
}



/******************************************************************************
 * ENCODE AND DECODE
 ******************************************************************************/

// item.proto
static int DecodeGame__Item(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Game__Item *msg = game__item__unpack(0, data_length, (uint8_t*)data);
    lua_pushgame__item(L, msg);
    game__item__free_unpacked(msg, 0);

    return 1;
}
static int EncodeGame__Item(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Game__Item *msg = luaL_checkgame__item(L, 1);

    size_t item_packed_size = game__item__get_packed_size(msg);
    char* buffer = (char*)malloc(item_packed_size);
    game__item__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, item_packed_size);
    free(buffer);

    free_game__item(msg);

    return 1;
}

// inventory.proto
static int DecodeGame__Inventory(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Game__Inventory *msg = game__inventory__unpack(0, data_length, (uint8_t*)data);
    lua_pushgame__inventory(L, msg);
    game__inventory__free_unpacked(msg, 0);

    return 1;
}
static int EncodeGame__Inventory(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Game__Inventory *msg = luaL_checkgame__inventory(L, 1);

    size_t inventory_packed_size = game__inventory__get_packed_size(msg);
    char* buffer = (char*)malloc(inventory_packed_size);
    game__inventory__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, inventory_packed_size);
    free(buffer);

    free_game__inventory(msg);

    return 1;
}


static const luaL_reg Module_methods[] =
{
    {"encode_game_item", EncodeGame__Item },
    {"decode_game_item", DecodeGame__Item },
    {"encode_game_inventory", EncodeGame__Inventory },
    {"decode_game_inventory", DecodeGame__Inventory },
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

    // ItemType
    SETCONSTANT(GAME__ITEM__ITEM_TYPE_WEAPON, GAME__ITEM__ITEM_TYPE__WEAPON);
    SETCONSTANT(GAME__ITEM__ITEM_TYPE_ARMOUR, GAME__ITEM__ITEM_TYPE__ARMOUR);
    SETCONSTANT(GAME__ITEM__ITEM_TYPE_RING, GAME__ITEM__ITEM_TYPE__RING);
    SETCONSTANT(GAME__ITEM__ITEM_TYPE_BOOK, GAME__ITEM__ITEM_TYPE__BOOK);
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
