#pragma once

#include "K.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Component
{
public:
    virtual void init() {}
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void handleEvent(const sf::Event &event) = 0;
    virtual ~Component()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }
    Component()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }
};