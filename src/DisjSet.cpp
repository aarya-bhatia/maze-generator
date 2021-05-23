#include "DisjSet.hpp"

/**
 * Initialise set and partitions
 */
DisjSet::DisjSet(int n) : _size(n), set(size())
{
    for (int i = 0; i < size(); i++)
    {
        set[i] = -1;
    }
}

/**
 * Perform find with path compression
 */
int DisjSet::find(int x)
{
    if (set[x] < 0)
    {
        return x;
    }
    return set[x] = find(set[x]);
}

/**
 * Union two sets by height
 */
void DisjSet::make_union(int x, int y)
{
    x = find(x);
    y = find(y);

    // y is deeper than x
    if (set[y] < set[x])
    {
        set[x] = y;
        // partitionSet.mergeSets(y, x);
    }
    else
    {
        if (set[x] == set[y])
        {
            set[x]--; // increase negative height
        }
        set[y] = x;
        // partitionSet.mergeSets(x, y);
    }
}