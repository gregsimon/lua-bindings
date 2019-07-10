cmake_minimum_required (VERSION 3.9)

set (LUA ../../third_party/lua-5.3.5/src)
set (LUACJSON ../../third_party/lua-cjson-2.1.0)
set (LUABRIDGE ../../third_party/LuaBridge )

project (lua_generator)

add_definitions(-DLUA_USE_LINUX)
add_definitions(-DUSE_INTERNAL_FPCONV)
include_directories( 
    ${LUA}
    ${LUABRIDGE}/Source
    ../src
    ${LUACJSON}
     )

set (SOURCES
    generator.cc
    ${LUACJSON}/lua_cjson.c
    ${LUACJSON}/strbuf.c
    ${LUACJSON}/g_fmt.c
    ${LUACJSON}/dtoa.c
    ${LUA}/lapi.c
    ${LUA}/lauxlib.c
    ${LUA}/lbaselib.c
    ${LUA}/lbitlib.c
    ${LUA}/lcode.c
    ${LUA}/lcorolib.c
    ${LUA}/lctype.c
    ${LUA}/ldblib.c
    ${LUA}/ldebug.c
    ${LUA}/ldo.c
    ${LUA}/ldump.c 
    ${LUA}/lfunc.c 
    ${LUA}/lgc.c 
    ${LUA}/linit.c 
    ${LUA}/liolib.c 
    ${LUA}/llex.c 
    ${LUA}/lmathlib.c
    ${LUA}/lmem.c 
    ${LUA}/loadlib.c 
    ${LUA}/lobject.c
    ${LUA}/lopcodes.c 
    ${LUA}/loslib.c 
    ${LUA}/lparser.c 
    ${LUA}/lstate.c 
    ${LUA}/lstring.c 
    ${LUA}/lstrlib.c 
    ${LUA}/ltable.c  
    ${LUA}/ltablib.c 
    ${LUA}/ltm.c 
    ${LUA}/lundump.c 
    ${LUA}/lutf8lib.c 
    ${LUA}/lvm.c 
    ${LUA}/lzio.c  )

add_executable(lua_generator ${SOURCES} )
SET_SOURCE_FILES_PROPERTIES( ${SOURCES} PROPERTIES LANGUAGE CXX )

target_link_libraries(lua_generator dl)
