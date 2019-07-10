
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <string>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "LuaBridge/LuaBridge.h"


extern int luaopen_cjson_safe(lua_State *l);


int main(int argc, char** argv)
{
    lua_State *L = nullptr;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <json file>" << std::endl;
        return -10;
    }

    try {

      std::string jsonFile = argv[1];
      std::string moduleFile = jsonFile + std::string(".lua");

      // Load the JSON file
      std::ifstream t(jsonFile);
      if (!t) {
        std::cerr << "Failed to open " << jsonFile << std::endl;
        return -12;
      }
      std::stringstream buffer;
      buffer << t.rdbuf();

      L = luaL_newstate();
      luaL_openlibs(L);

      luaopen_cjson_safe(L);

      if (luaL_loadfile(L, "lua_generator.lua")) {
        std::cerr << "Failed to load lua_generator.lua" << std::endl;
        return -10;
      }

      // Load the code
      lua_call(L, 0, LUA_MULTRET);

      // call the generator function.
      lua_getglobal(L, "generate_fidl_from_json");
      lua_pushstring(L, buffer.str().c_str());
      lua_call(L, 1, 0);
    } catch(std::exception &e){
      std::cerr << "exception";
        luaL_error(L, e.what());
    }
 
    return 0;
}
