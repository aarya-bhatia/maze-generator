#include <SFML/Graphics.hpp>

#pragma once

struct Component
{
    virtual void handleEvent(const sf::Event &event) {}
    virtual void update() {}
    virtual void render(sf::RenderWindow &window) {}
    virtual void init() {}
    virtual void destroy() {}

    const std::string name;

    Component()
    {
        init();
    }

    ~Component()
    {
        destroy();
    }
};