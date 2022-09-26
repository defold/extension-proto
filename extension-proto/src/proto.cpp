#define EXTENSION_NAME Proto
#define LIB_NAME "Proto"
#define MODULE_NAME "proto"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>
#include <stdlib.h>


#include "person.pb-c.h"
#include "team.pb-c.h"



/******************************************************************************
 * PUSH
 ******************************************************************************/

static void lua_pushperson(lua_State* L, Person *msg);
static void lua_pushteam(lua_State* L, Team *msg);

static void lua_pushperson(lua_State* L, Person *msg)
{
    lua_newtable(L);
    // required
    lua_pushstring(L, "id");
    lua_pushnumber(L, msg->id);
    lua_settable(L, -3);
    lua_pushstring(L, "name");
    lua_pushstring(L, msg->name);
    lua_settable(L, -3);
    
    // optional
    lua_pushstring(L, "email");
    lua_pushstring(L, msg->email);
    lua_settable(L, -3);
    
    // repeated
}
static void lua_pushteam(lua_State* L, Team *msg)
{
    lua_newtable(L);
    // required
    
    // optional
    
    // repeated
    lua_pushstring(L, "members");
    lua_newtable(L);
    int members_size = msg->n_members;
    for (int i = 0; i < members_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushperson(L, msg->members[i]);
        lua_settable(L, -3);
    }
    lua_settable(L, -3);
    lua_pushstring(L, "numbers");
    lua_newtable(L);
    int numbers_size = msg->n_numbers;
    for (int i = 0; i < numbers_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_pushnumber(L, msg->numbers[i]);
        lua_settable(L, -3);
    }
    lua_settable(L, -3);
}


/******************************************************************************
 * CHECK 
 ******************************************************************************/

static Person* luaL_checkperson(lua_State* L, int narg);
static Team* luaL_checkteam(lua_State* L, int narg);

static Person* luaL_checkperson(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Person *msg = (Person*)malloc(sizeof(Person));
    person__init(msg);

    // required
    lua_pushstring(L, "id");
    lua_gettable(L, narg);
    msg->id = (int32_t)luaL_checknumber(L, lua_gettop(L));
    lua_pop(L, 1);
    lua_pushstring(L, "name");
    lua_gettable(L, narg);
    msg->name = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);
    
    // optional
    lua_pushstring(L, "email");
    lua_gettable(L, narg);
    msg->email = (char*)luaL_checkstring(L, lua_gettop(L));
    lua_pop(L, 1);
    
    // repeated
    return msg;
}
static Team* luaL_checkteam(lua_State* L, int narg)
{
    if (!lua_istable(L, narg)) {
        luaL_error(L, "Expected value at index %d to be a table", narg);
        return 0;
    }

    Team *msg = (Team*)malloc(sizeof(Team));
    team__init(msg);

    // required
    
    // optional
    
    // repeated
    lua_pushstring(L, "members");
    lua_gettable(L, narg);
    int members_size = lua_objlen(L, lua_gettop(L));
    int members_index = lua_gettop(L);
    msg->n_members = members_size;
    for (int i = 0; i < members_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_gettable(L, members_index);
        msg->members[i] = (Person*)luaL_checkperson(L, lua_gettop(L));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    lua_pushstring(L, "numbers");
    lua_gettable(L, narg);
    int numbers_size = lua_objlen(L, lua_gettop(L));
    int numbers_index = lua_gettop(L);
    msg->n_numbers = numbers_size;
    for (int i = 0; i < numbers_size; i++)
    {
        lua_pushnumber(L, i + 1);
        lua_gettable(L, numbers_index);
        msg->numbers[i] = (int32_t)luaL_checknumber(L, lua_gettop(L));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    return msg;
}



/******************************************************************************
 * FREE 
 ******************************************************************************/

static void free_person(Person* msg);
static void free_team(Team* msg);

static void free_number(int32_t) {};
static void free_string(char*) {};
static void free_bool(bool) {};

static void free_person(Person* msg)
{
    // required
    free_number(msg->id);
    free_string(msg->name);
    
    // optional
    free_string(msg->email);
    
    // repeated
    
    free(msg);
}
static void free_team(Team* msg)
{
    // required
    
    // optional
    
    // repeated
    int members_size = msg->n_members;
    for (int i = 0; i < members_size; i++)
    {
        free_person(msg->members[i]);
    }
    int numbers_size = msg->n_numbers;
    for (int i = 0; i < numbers_size; i++)
    {
        free_number(msg->numbers[i]);
    }
    
    free(msg);
}



/******************************************************************************
 * DECODE
 ******************************************************************************/

static int DecodePerson(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Person *msg = person__unpack(0, data_length, (uint8_t*)data);
    lua_pushperson(L, msg);
    person__free_unpacked(msg, 0);

    return 1;
}

static int EncodePerson(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Person *msg = luaL_checkperson(L, 1);

    size_t person_packed_size = person__get_packed_size(msg);
    char* buffer = (char*)malloc(person_packed_size);
    person__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, person_packed_size);
    free(buffer);

    // DO IT RECURSIVELY!!!!!!
    free_person(msg);

    return 1;
}
static int DecodeTeam(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    size_t data_length;
    const char* data = luaL_checklstring(L, 1, &data_length);

    Team *msg = team__unpack(0, data_length, (uint8_t*)data);
    lua_pushteam(L, msg);
    team__free_unpacked(msg, 0);

    return 1;
}

static int EncodeTeam(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    Team *msg = luaL_checkteam(L, 1);

    size_t team_packed_size = team__get_packed_size(msg);
    char* buffer = (char*)malloc(team_packed_size);
    team__pack(msg, (uint8_t*)buffer);

    lua_pushlstring(L, buffer, team_packed_size);
    free(buffer);

    // DO IT RECURSIVELY!!!!!!
    free_team(msg);

    return 1;
}

static const luaL_reg Module_methods[] =
{
    {"encode_person", EncodePerson },
    {"decode_person", DecodePerson },
    {"encode_team", EncodeTeam },
    {"decode_team", DecodeTeam },
    {0,0}
};

static void LuaInit(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
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
