#ifndef __NAVIGATIONCELL_HPP
#define __NAVIGATIONCELL_HPP

// Defines a navigable triangle in space. The normal is assumed to be
// no more than 90deg from the up/down Y axis.  This allows us to
// ignore height when considering paths.
//
// These a collected into a mesh and remain fairly static.

#include <OgreVector3.h>
#include <cstdint>
#include <iostream>

#define VERTEX_NEIGHBOUR_TOLERANCE 2.0f

namespace maquina
{
    using Ogre::Vector3;

    enum class LineClassification
    {
        EXITS,
        STOPS,
        MISSED,
    };

    class NavigationMesh;

    class NavigationCell
    {
        friend NavigationMesh;

        Vector3 a;
        Vector3 b;
        Vector3 c;
        Vector3 mCentre;

        NavigationCell* ab;
        NavigationCell* bc;
        NavigationCell* ca;

        NavigationCell& operator= ( const NavigationCell& ) = delete;

        int mTag;

        public:

        NavigationCell( Vector3 na, Vector3 nb, Vector3 nc, int tag = 0 ) :
            a(na), b(nb), c(nc),
            ab(nullptr), bc(nullptr), ca(nullptr),
            mTag(tag)
        {
            mCentre = ( a + b + c ) / 3;
        }

        bool hasVertex( Vector3& vec );

        LineClassification classifyLine( Vector3& start, Vector3& end,
                NavigationCell& from, NavigationCell* &next );

        bool operator==( const NavigationCell& rhs ) const
        {
            return this == &rhs;
        }
    };
}

#endif  //__NAVIGATIONCELL_HPP
