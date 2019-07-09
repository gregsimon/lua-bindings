
#include "lua_system.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "LuaBridge/LuaBridge.h"


bool constructLuaSyscallThunks(lua_State* L)
{
  // Vmo object
  luabridge::getGlobalNamespace(L)
    .beginClass <luafidl::Vmo>("Vmo")
      .addFunction ("foo", &luafidl::Vmo::foo)
    .endClass();

  luabridge::getGlobalNamespace(L)
    .beginClass <luafidl::Socket>("Socket")
      .addFunction ("foo", &luafidl::Socket::foo)
    .endClass();

  // zx objects
  luabridge::getGlobalNamespace (L)
    .beginNamespace ("zx")
      .addFunction("vmo_create", lua_vmo_create)
      .addFunction("vmo_read", lua_vmo_read)
      .addFunction("vmo_write", lua_vmo_write)

      .addFunction("socket_create", lua_socket_create)
      .addFunction("socket_write", lua_socket_write)
      .addFunction("socket_read", lua_socket_read)

      .addFunction("channel_create", lua_channel_create)
      .addFunction("channel_from_file", lua_channel_from_file)
      .addFunction("channel_write", lua_channel_write)

      .addFunction("connect_to_service", lua_connect_to_service)
    .endNamespace();

  return true;
}


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
  luabridge::RefCountedObjectPtr <luafidl::Socket> 
        object (new luafidl::Socket());
  luabridge::push(L, object);
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
  // allocate this object
  luabridge::RefCountedObjectPtr <luafidl::Vmo> 
        object (new luafidl::Vmo());
  luabridge::push(L, object);

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
