// Testing Lua APIs

#ifdef __cplusplus
  #include "lua.hpp"
#else
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
#endif


int main(int argc, char** argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dofile(L, argv[1]);

    return 0;
}