#[[
    Makefile for Lua + Fuchsia runner. This includes the 
    lua vm and syscall bindings. The FIDL codec is written
    in Lua and injected as part of execution.

    Requires the Fuchsia SDK at
    https://fuchsia.dev/fuchsia-src/development/sdk/download
]]
cmake_minimum_required (VERSION 3.9)

#[[
    --- CONFIGURE (TODO: w env variables)
]]
set (FUCHSIA_SDK ~/fuchsia_sdk)
set(CMAKE_VERBOSE_MAKEFILE ON)

#[[
     --- BELOW SHOULD BE FIXED ---
]]

set (LUA ../third_party/lua-5.3.5/src)
set (LUABRIDGE ../third_party/LuaBridge)
set (FIDLC {$FUCHSIA_SDK}/tools/fidlc)

#set(CMAKE_SYSTEM_PROCESSOR arm64)
#set(fuchsia_target "aarch64-fuchsia")
set(CMAKE_SYSTEM_PROCESSOR x64)
set(fuchsia_target "x86_64-fuchsia")
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${fuchsia_target})
set(CMAKE_CXX_COMPILER_TARGET ${fuchsia_target})
set(CMAKE_SYSROOT ${FUCHSIA_SDK}/arch/x64/sysroot)


project (luarunner)

add_definitions( -DLUA_USE_LINUX)
include_directories( 
    ${LUA}
    ${LUABRIDGE}/Source 
    ${FUCHSIA_SDK}/arch/x64/sysroot/include2
    )

set (LUA_SOURCES
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

 
set (SOURCES main.cc
    lua_system.cc
    lua_handles.cc
    ${LUA_SOURCES}
)

add_executable(luarunner ${SOURCES} )
SET_SOURCE_FILES_PROPERTIES( ${SOURCES} PROPERTIES LANGUAGE CXX )

set_property(TARGET luarunner PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(luarunner dl)
