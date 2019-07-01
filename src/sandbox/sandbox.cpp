
#include <iostream>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua_system.h"

void load_syscall_thunks(lua_State* L);

extern "C" int error_cb(lua_State* L)
{
  int idx = lua_gettop(L);
  size_t len;

  std::cerr << "error - " << lua_tolstring(L, idx, &len) << std::endl;
  return 1;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <luafile>" << std::endl;
        return -10;
    }

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    load_syscall_thunks(L);

    luaL_loadfile(L, argv[1]);

    try {
      lua_call(L, 0, LUA_MULTRET);
    } catch(std::exception &e){
        luaL_error(L, e.what());
    }
 
    std::cerr << "end\n";

    return 0;
}



void load_syscall_thunks(lua_State* L)
{
  lua_newtable(L); // zx global object
  
  // zx.clock_get_monotonic
  lua_pushstring(L, "clock_get_monotonic");
  lua_pushcfunction(L, lua_clock_get_monotonic);
  lua_settable(L, -3);

  // channel_create
  // (u32 opts, handle out0, handle out1) -> status
  lua_pushstring(L, "channel_create");
  lua_pushcfunction(L, lua_channel_create);
  lua_settable(L, -3);

  // channel_from_file
  lua_pushstring(L, "channel_from_file");
  lua_pushcfunction(L, lua_channel_from_file);
  lua_settable(L, -3);

  // connect_to_service
  lua_pushstring(L, "connect_to_service");
  lua_pushcfunction(L, lua_connect_to_service);
  lua_settable(L, -3);

  // channel_write
  lua_pushstring(L, "channel_write");
  lua_pushcfunction(L, lua_channel_write);
  lua_settable(L, -3);

  // event_pair_create
  lua_pushstring(L, "event_pair_create");
  lua_pushcfunction(L, lua_event_pair_create);
  lua_settable(L, -3);

  // socket_create
  lua_pushstring(L, "socket_create");
  lua_pushcfunction(L, lua_socket_create);
  lua_settable(L, -3);

  // socket_write
  lua_pushstring(L, "socket_write");
  lua_pushcfunction(L, lua_socket_write);
  lua_settable(L, -3);

  // socket_read
  lua_pushstring(L, "socket_read");
  lua_pushcfunction(L, lua_socket_read);
  lua_settable(L, -3);

  // vmo_create
  lua_pushstring(L, "vmo_create");
  lua_pushcfunction(L, lua_vmo_create);
  lua_settable(L, -3);

  // vmo_from_file
  lua_pushstring(L, "vmo_from_file");
  lua_pushcfunction(L, lua_vmo_from_file);
  lua_settable(L, -3);
  
  // vmo_get_size
  lua_pushstring(L, "vmo_get_size");
  lua_pushcfunction(L, lua_vmo_get_size);
  lua_settable(L, -3);

  // vmo_set_size
  lua_pushstring(L, "vmo_set_size");
  lua_pushcfunction(L, lua_vmo_set_size);
  lua_settable(L, -3);

  // vmo_write
  lua_pushstring(L, "vmo_write");
  lua_pushcfunction(L, lua_vmo_set_size);
  lua_settable(L, -3);

  // vmo_read
  lua_pushstring(L, "vmo_read");
  lua_pushcfunction(L, lua_vmo_read);
  lua_settable(L, -3);

  // clock_get
  lua_pushstring(L, "clock_get");
  lua_pushcfunction(L, lua_clock_get);
  lua_settable(L, -3);

  lua_setglobal(L, "zx"); // close, and push the zx global
}

