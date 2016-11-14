#ifndef __NAVIGATIONMESH_HPP
#define __NAVIGATIONMESH_HPP

#include <vector>
#include <string>
#include <OgreVector3.h>
#include "navigationcell.hpp"

namespace maquina
{
    using Ogre::Vector3;

    // Defines a navigable space made up of triangles (NavigationCell's).
    //

    class NavigationMesh
    {
        std::vector<NavigationCell> mCells;

        public:
        void addCells( std::vector<NavigationCell> cells )
        {
            for( auto& cell : cells ) {
                mCells.push_back( cell );
            }
        }

        void addCell( NavigationCell&& cell )
        {
            mCells.push_back( cell );
        }

        // Run through each cell, and cache the neighbours
        void computeNeighbours();
	    std::string dumpCellsToString();

        // Retrieve the cell that contains the given point within a tolerance of its
        // surface.
        NavigationCell* getCellContainingPoint( Vector3& point );
    };
}

#endif  //__NAVIGATIONMESH_HPP
