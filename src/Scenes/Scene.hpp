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
    std::shared_ptr<std::vector<Matrix::Coord>> path;
    sf::Color color;

    explicit Scene(std::shared_ptr<Grid> grid, std::shared_ptr<Maze> maze,
                   std::shared_ptr<std::vector<Matrix::Coord>> path,
                   const sf::Color &color) : grid(grid),
                                             maze(maze),
                                             path(path),
                                             color(color)

    {
    }

public:
    void render(sf::RenderWindow &window) override
    {
        grid->render(window);
    }
};