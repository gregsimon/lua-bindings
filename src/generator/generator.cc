
#include <iostream>
#include <string>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "LuaBridge/LuaBridge.h"



int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <json file>" << std::endl;
        return -10;
    }

    std::string jsonFile = argv[1];
    std::string moduleFile = jsonFile + std::string(".lua");

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_loadfile(L, "lua_generator.lua");

    try {
      lua_call(L, 0, LUA_MULTRET);
    } catch(std::exception &e){
      std::cerr << "exception";
        luaL_error(L, e.what());
    }
 
    return 0;
}
