#pragma once

#include <SFML/Graphics.hpp>

class Component
{
public:
    virtual void init() {}
    virtual void destroy() {}
    virtual void update() {}
    virtual void render(sf::RenderWindow &window) {}
    virtual void handleEvent(const sf::Event &event) {}
};