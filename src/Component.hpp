#pragma once

#include <SFML/Graphics.hpp>

class Component
{
public:
    virtual void init() {}
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void handleEvent(const sf::Event &event) = 0;
};