
#include <iostream>

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

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

    lua_atpanic(L, error_cb);

    luaL_loadfile(L, argv[1]);
    lua_call(L, 0, LUA_MULTRET);

    std::cerr << "end\n";

    return 0;
}
