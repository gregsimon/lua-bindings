// lua-runner for Fuchsia

#include <iostream>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "lua_system.h"


int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <luafile>" << std::endl;
        return -10;
    }

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    constructLuaSyscallThunks(L);

    luaL_loadfile(L, argv[1]);

    try {
      lua_call(L, 0, LUA_MULTRET);
    } catch(std::exception &e){
      std::cerr << "exception";
        luaL_error(L, e.what());
    }

    return 0;
}
