#include <cstdlib>
#include <iostream>
#include <lua.hpp>
#include <LuaBridge.h>

#include "navigationmesh.hpp"

using std::cout;
using std::endl;
using namespace luabridge;
using Ogre::Vector3;

void test( lua_State* L )
{
    maquina::NavigationMesh mesh;

    mesh.addCell( maquina::NavigationCell(
               Vector3( -1, 0, -1 ),
               Vector3(  1, 0, -1 ),
               Vector3(  1, 0,  1 )
               ) );

    mesh.addCell( maquina::NavigationCell(
               Vector3( -1, 0, -1 ),
               Vector3(  1, 0,  1 ),
               Vector3( -1, 0,  1 )
               ) );

    mesh.computeNeighbours();

    cout << mesh.dumpCellsToString() << endl;

    return;
}

int main()
{
    lua_State* L = luaL_newstate();

    luaL_openlibs( L );

    test( L );

    luaL_dostring( L, "print( _VERSION ) print( 'Selam Dünya' )" );

    lua_close( L );

    return EXIT_SUCCESS;
}
