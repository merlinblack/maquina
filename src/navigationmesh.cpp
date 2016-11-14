#include "navigationmesh.hpp"
#include <sstream>

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
    std::string NavigationMesh::dumpCellsToString() {
        using std::endl;
	    std::stringstream ss;

        for( auto& cell : mCells ) {
            ss << "Cell: " << &cell << endl;
            ss << " tag: " << cell.mTag << endl;
            ss << "cntr: " << cell.mCentre << endl;
            ss << "  ab: " << cell.ab << endl;
            ss << "  bc: " << cell.bc << endl;
            ss << "  ca: " << cell.ca << endl;
            ss << endl;
        }

	return ss.str();
    }
}
