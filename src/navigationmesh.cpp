#include "navigationmesh.hpp"

namespace maquina
{
    void NavigationMesh::computeNeighbours()
    {
        for( auto& cell : mCells ) {
            for( auto& test : mCells ) {
                if( cell == test ) {
                    continue;
                }
                if( test.hasVertex( cell.a ) ) {
                    if( test.hasVertex( cell.b ) ) {
                        cell.ab = &test;
                        continue;
                    }
                    if( test.hasVertex( cell.c ) ) {
                        cell.ca = &test;
                        continue;
                    }
                }
                if( test.hasVertex( cell.b ) && test.hasVertex( cell.c ) ) {
                    cell.bc = &test;
                }
            }
        }
    }
}
