#pragma once

#include "Component.hpp"

class AbstractScene : public Component
{
public:
    virtual void next() = 0;
    virtual bool finished() = 0;

protected:
    AbstractScene()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }

public:
    virtual ~AbstractScene()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }
};