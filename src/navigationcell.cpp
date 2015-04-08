#include "navigationcell.hpp"
#include "ogretools.hpp"
#include <OgreVector2.h>

namespace maquina
{
    using Ogre::Vector2;

    bool NavigationCell::hasVertex( Vector3& vec )
    {
        if( a.positionEquals( vec, VERTEX_NEIGHBOUR_TOLERANCE ) ) return true;
        if( b.positionEquals( vec, VERTEX_NEIGHBOUR_TOLERANCE ) ) return true;
        if( c.positionEquals( vec, VERTEX_NEIGHBOUR_TOLERANCE ) ) return true;
        return false;
    }

    LineClassification NavigationCell::classifyLine( Vector3& start, Vector3& end,
            NavigationCell& from, NavigationCell* &next )
    {
        // Flatten co-ordinates to 2D

        Vector2 s( start.x, start.z );
        Vector2 e( end.x, end.z );

        Vector2 fa( a.x, a.z );
        Vector2 fb( b.x, b.z );
        Vector2 fc( c.x, c.z );

        // Check the line against each side.

        if( ab != &from && OgreTools::LinesIntersect2D( s, e, fa, fb ) ) {
            next = ab;
            return LineClassification::EXITS;
        }

        if( bc != &from && OgreTools::LinesIntersect2D( s, e, fb, fc ) ) {
            next = bc;
            return LineClassification::EXITS;
        }

        if( ca != &from && OgreTools::LinesIntersect2D( s, e, fc, fa ) ) {
            next = ca;
            return LineClassification::EXITS;
        }

        // The line does not cross one of the sides except possibly the one shared
        // with the cell that the line came from.  Check it hasn't missed completely.

        if( Ogre::Math::pointInTri2D( e, fa, fb, fc ) ) {
            next = &from;
            return LineClassification::STOPS;
        }

        next = nullptr;
        return LineClassification::MISSED;
    }
}
