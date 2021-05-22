#pragma once

#include "AbstractScene.hpp"
#include "Grid.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class Scene : public AbstractScene
{
protected:
    std::shared_ptr<Grid> grid;
    std::shared_ptr<Maze> maze;
    sf::Color color;

    explicit Scene(std::shared_ptr<Grid> grid, const sf::Color &color) : grid(grid),
                                                                         maze(grid->maze),
                                                                         color(color)
    {
    }
};