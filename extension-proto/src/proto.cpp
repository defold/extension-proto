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

static void lua_pushitem(lua_State* L, Item *msg);
static void lua_pushinventory(lua_State* L, Inventory *msg);

static void lua_pushitem(lua_State* L, Item *msg)
{
    lua_newtable(L);

    // id
    lua_pushstring(L, "id");
    lua_pushnumber(L, (int32_t)msg->id);
    lua_settable(L, -3);

    // name
    lua_pushstring(L, "name");
    lua_pushstring(L, (char*)msg->name);
    lua_settable(L, -3);

    // weight
    lua_pushstring(L, "weight");
    lua_pushnumber(L, (float)msg->weight);
    lua_settable(L, -3);

    // type
    lua_pushstring(L, "type");
    lua_pushnumber(L, (ItemType)msg->type);
    lua_settable(L, -3);

}
static void lua_pushinventory(lua_State* L, Inventory *msg)
{
    lua_newtable(L);

    // capacity
    lua_pushstring(L, "capacity");
    lua_pushnumber(L, (int32_t)msg->capacity);
    lua_settable(L, -3);

    // items
    lua_pushstring(L, "items");
    lua_newtable(L);
    int items_size = msg->n_items;
    for (int i = 0; i < items_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushitem(L, (Item*)msg->items[i]);
        lua_settable(L, -3);
    }
    lua_settable(L, -3);

}


/******************************************************************************
 * CHECK 
 ******************************************************************************/

static int luaL_checkboolean(lua_State* L, int narg) { return lua_toboolean(L, narg); }

static Item* luaL_checkitem(lua_State* L, int narg);
static Inventory* luaL_checkinventory(lua_State* L, int narg);

static Item* luaL_checkitem(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Item *msg = (Item*)malloc(sizeof(Item));
    item__init(msg);

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
    msg->type = (ItemType)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);

    return msg;
}
static Inventory* luaL_checkinventory(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Inventory *msg = (Inventory*)malloc(sizeof(Inventory));
    inventory__init(msg);

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
    msg->items = (Item**)malloc(sizeof(Item*) * items_size);
    for (int i = 0; i < items_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_gettable(L, items_index);
        msg->items[i] = (Item*)luaL_checkitem(L, lua_gettop(L));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);

    return msg;
}



/******************************************************************************
 * FREE 
 ******************************************************************************/

static void free_item(Item* msg);
static void free_inventory(Inventory* msg);

static void free_number(int32_t) {};
static void free_string(char*) {};
static void free_bool(bool) {};
static void free_boolean(bool) {};

static void free_item(Item* msg)
{
    free_number(msg->id);
    free_string(msg->name);
    free_number(msg->weight);
    free_number(msg->type);
    free(msg);
}
static void free_inventory(Inventory* msg)
{
    free_number(msg->capacity);
    int items_size = msg->n_items;
    for (int i = 0; i < items_size; i++)
    {
        free_item(msg->items[i]);
    }
    free(msg->items);
    free(msg);
}



/******************************************************************************
 * ENCODE AND DECODE
 ******************************************************************************/

static int DecodeItem(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Item *msg = item__unpack(0, data_length, (uint8_t*)data);
    lua_pushitem(L, msg);
    item__free_unpacked(msg, 0);

    return 1;
}

static int EncodeItem(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Item *msg = luaL_checkitem(L, 1);

    size_t item_packed_size = item__get_packed_size(msg);
    char* buffer = (char*)malloc(item_packed_size);
    item__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, item_packed_size);
    free(buffer);

    free_item(msg);

    return 1;
}
static int DecodeInventory(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Inventory *msg = inventory__unpack(0, data_length, (uint8_t*)data);
    lua_pushinventory(L, msg);
    inventory__free_unpacked(msg, 0);

    return 1;
}

static int EncodeInventory(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Inventory *msg = luaL_checkinventory(L, 1);

    size_t inventory_packed_size = inventory__get_packed_size(msg);
    char* buffer = (char*)malloc(inventory_packed_size);
    inventory__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, inventory_packed_size);
    free(buffer);

    free_inventory(msg);

    return 1;
}

static const luaL_reg Module_methods[] =
{
    {"encode_item", EncodeItem },
    {"decode_item", DecodeItem },
    {"encode_inventory", EncodeInventory },
    {"decode_inventory", DecodeInventory },
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
    SETCONSTANT(ITEMTYPE_WEAPON, 0);
    SETCONSTANT(ITEMTYPE_ARMOUR, 1);
    SETCONSTANT(ITEMTYPE_RING, 2);
    SETCONSTANT(ITEMTYPE_BOOK, 3);
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
