
#include "lua_system.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern "C" {


int lua_clock_get_monotonic(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_channel_create(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_channel_from_file(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_connect_to_service(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_channel_write(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_event_pair_create(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_socket_create(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_socket_write(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_socket_read(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_create(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_from_file(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_get_size(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_set_size(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_read(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_vmo_write(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}

int lua_clock_get(lua_State* L)
{
  // return should be on top of stack.
  lua_pushinteger(L, 1000);
  return 1;
}



}
