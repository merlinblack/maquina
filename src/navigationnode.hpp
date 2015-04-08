#ifndef __NAVIGATIONNODE_HPP
#define __NAVIGATIONNODE_HPP

// Holds the path finding information for a particular
// navigation query.
//
// These last only as long as the query.

class NavigationNode
{
    // Associated cell for position info.
    NavigationCell* cell;

    // Which neighbour is the next in the path.
    int path;

    // A* Path finding data.
    bool isOpen;
    bool isClosed;
    float g_cost;               // Cost to get here
    float h_host;               // Guess at cost to destination
    float totalcost;
    NavigationNode *parent;     // Node we arrived from
}

#endif // __NAVIGATIONNODE_HPP
