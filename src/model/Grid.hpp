#pragma once

#include "Maze.hpp"
#include "Matrix.hpp"
#include "K.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

///
// A grid class contains a list of cells as sf::RectangleShapes.
// The grid contains twice (minus one) the rows and cols of
// the maze because adjacent cells are used to represent
// the "walls" of the maze.
class Grid
{
private:
    void initCell(Matrix::Coord cell, const sf::Color &color = K::col_wall);

public:
    Matrix matrix;
    std::vector<sf::RectangleShape> cells; // Add this to a GridDisplay class later -> TODO

    explicit Grid(const Matrix &maze_mat) : matrix(maze_mat.width * 2 - 1, maze_mat.height * 2 - 1),
                                            cells(matrix.size())
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
        init();
    }

    ~Grid()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }

    /**
     * Initialises all cells as walls.
     */
    void init();

    void render(sf::RenderWindow &window)
    {
        for (size_t i = 0; i < cells.size(); i++)
        {
            window.draw(cells[i]);
        }
    }

    void resize(const Matrix &maze_mat)
    {
        matrix.width = maze_mat.width * 2 - 1;
        matrix.height = maze_mat.height * 2 - 1;
        cells.resize(matrix.size());
    }
};