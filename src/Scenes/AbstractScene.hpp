#pragma once

#include "Component.hpp"
#include "Logger.h"

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
            // std::string file = __FILE__;
            // file += " constructor";
            // Logger::log(file.c_str());
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