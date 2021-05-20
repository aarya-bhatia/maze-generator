#include "PartitionSet.hpp"

void PartitionSet::getPathList(DisjSet &ds, int src, std::list<int> &onPathList, std::list<int> &offPathList)
{
    src = ds.find(src);

    for (int i = 0; i < size(); i++)
    {
        if (!set[i].empty())
        {
            if (ds.find(set[i].front()) != src)
            {
                copyList(offPathList, set[i]);
            }
            else
            {
                copyList(onPathList, set[i]);
            }
        }
    }
}

void PartitionSet::copyList(std::list<int> &list, std::list<int> &elements)
{
    for (std::list<int>::const_iterator iterator = elements.begin(); iterator != elements.end(); iterator++)
    {
        list.push_back(*iterator);
    }
}

void PartitionSet::printList(std::list<int> p)
{
    std::cout << "{";
    std::list<int>::const_iterator itr = p.begin();

    if (itr != p.end())
    {
        std::cout << *itr;
    }

    itr++;

    while (itr != p.end())
    {
        std::cout << "," << *itr;
        itr++;
    }
    std::cout << "}";
}

void PartitionSet::print() const
{
    std::cout << "[";
    for (unsigned int i = 0; i < set.size(); i++)
    {
        if (!set[i].empty())
        {
            printList(set[i]);
            std::cout << ' ';
        }
    }
    std::cout << "]\n";
}

void PartitionSet::init()
{
    for (int i = 0; i < size(); i++)
    {
        set[i].push_front(i);
    }
}