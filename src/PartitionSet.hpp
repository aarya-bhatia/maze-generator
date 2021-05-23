#include "DisjSet.hpp"

#ifndef PARTITION_SET_HPP
#define PARTITION_SET_HPP

struct PartitionSet
{
    std::vector<std::list<int> > set;

    PartitionSet()
    {
        init();
    }

    void init();

    int size() const
    {
        return set.size();
    }

    void getPathList(DisjSet &ds, int src, std::list<int> &onPathList, std::list<int> &offPathList);

    static void copyList(std::list<int> &list, std::list<int> &elements);

    static void printList(std::list<int> p);

    void print() const;

    void mergeSets(int dest, int src)
    {
        set[dest].merge(set[src]);
    }
};

#endif