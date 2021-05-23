#pragma once

#include "AbstractScene.hpp"
#include "SceneData.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Scene : public AbstractScene
{
protected:
    SceneData data;
    sf::Color color;

    explicit Scene(SceneData &data, const sf::Color &color) : data(data), color(color)
    {
    }

public:
    void render(sf::RenderWindow &window) override
    {
        data.grid->render(window);
    }

    void handleEvent(const sf::Event &event) override
    {
        std::cout << "Scene Event" << std::endl;
    }

    virtual ~Scene() {}
};