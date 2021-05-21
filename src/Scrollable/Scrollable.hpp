#include <list>

#ifndef SCROLLABLE_HPP
#define SCROLLABLE_HPP

class Scrollable
{
public:
    virtual void handleScroll(int dy) {}
};

#endif