#include <list>

#ifndef SCROLLABLE_HPP
#define SCROLLABLE_HPP

class Scrollable
{
public:
    virtual void scroll(int dy) = 0;
};

class Scroller
{
public:
    int y;

    std::list<Scrollable> children;

    void scroll(int dy)
    {
        for (std::list<Scrollable>::iterator itr = children.begin(); itr != children.end(); itr++)
        {
            Scrollable &child = *itr;
            child.scroll(dy);
        }
    }

    void add(const Scrollable &child)
    {
        children.push_back(child);
    }
};

#endif