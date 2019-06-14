
#include <iostream>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

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

extern "C" int zx_clock_get_monotonic(lua_State* L)
{
  lua_pushinteger(L, 1000);
  return 1;
}

void load_syscall_thunks(lua_State* L)
{
  lua_newtable(L);

  lua_pushstring(L, "clock_get_monotonic");
  lua_pushcfunction(L, zx_clock_get_monotonic);
  lua_settable(L, -3);

  lua_setglobal(L, "zx");
}