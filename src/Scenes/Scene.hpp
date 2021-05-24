#pragma once

#include "AbstractScene.hpp"
#include "SceneData.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Scene : public AbstractScene
{
protected:
    const SceneData *data;
    const sf::Color color;

    explicit Scene(const SceneData *data, const sf::Color &color) : data(data), color(color)
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }

public:
    virtual void render(sf::RenderWindow &window) override
    {
        data->grid->render(window);
    }

    virtual void handleEvent(const sf::Event &event) override
    {
        if (event.type == sf::Event::KeyReleased)
        {
            // A -> toggle autoplay
            if (event.key.code == sf::Keyboard::A)
            {
                K::AUTOPLAY = !K::AUTOPLAY;
            }
            // P -> pauses animation when autoplay is on
            else if (K::AUTOPLAY && event.key.code == sf::Keyboard::P)
            {
                K::PAUSE = !K::PAUSE;
            }
            // N -> update frame when autoplay is off
            else if (!K::AUTOPLAY && event.key.code == sf::Keyboard::N)
            {
                next();
                update();
            }
        }
    }

    virtual ~Scene()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }
};