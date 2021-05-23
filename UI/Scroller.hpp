#include <list>
#include "Scrollable.hpp"

#ifndef SCROLLER_HPP
#define SCROLLER_HPP

class Scroller
{
public:
    std::list<Scrollable> children;

    void scroll(int dy);

    void add(const Scrollable &child);
};

#endif