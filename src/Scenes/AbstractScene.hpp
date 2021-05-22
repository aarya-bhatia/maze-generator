#pragma once

#include "Component.hpp"

class AbstractScene : public Component
{
public:
    virtual void next() = 0;
    virtual bool finished() = 0;

protected:
    AbstractScene() {}
};