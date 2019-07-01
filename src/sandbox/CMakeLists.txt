cmake_minimum_required (VERSION 2.6)

set( LUA ../../lua-5.3.5/src )

project (sandbox)

add_definitions( -DLUA_USE_LINUX)
include_directories( ${LUA} .. )

set (SOURCES sandbox.cpp
    ../lua_system.cpp
    ../lua_handles.cpp
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

add_executable(sandbox ${SOURCES} )
SET_SOURCE_FILES_PROPERTIES( ${SOURCES} PROPERTIES LANGUAGE CXX )

target_link_libraries(sandbox dl)
