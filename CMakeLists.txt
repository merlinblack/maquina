cmake_minimum_required( VERSION 2.6 )

project( maquina )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

message( STATUS "Searching for CMake modules in: ${CMAKE_MODULE_PATH} " )

add_subdirectory( Lua/src )

include_directories(
    ${PROJECT_SOURCE_DIR}/LuaBridge/Source/LuaBridge
    ${Lua_INCLUDE_DIRS}
    )

file( GLOB SRCS src/*.cpp )
file( GLOB HDRS src/*.h )

add_executable( maquina
    ${SRCS}
    ${HDRS}
    )


target_link_libraries( maquina
    ${Lua_LIBRARIES}
    )

include( GitVersioning )
enable_git_versioning( maquina )

message( STATUS "Lua libraries:      ${Lua_LIBRARIES} ")
message( STATUS "Lua headers:        ${Lua_INCLUDE_DIRS} ")
