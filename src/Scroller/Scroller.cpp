#include "Scroller.hpp"

void Scroller::scroll(int dy)
{
    for (Scrollable child : children)
    {
        child.handleScroll(dy);
    }
}

void Scroller::add(const Scrollable &child)
{
    children.push_back(child);
}