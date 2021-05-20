#include "Grid.hpp"

/**
 * Initialises all cells with path color and wall color alternately
 */
void Grid::init()
{
    for (int row = 0; row < maze.height; row++)
    {
        for (int col = 0; col < maze.width; col++)
        {
            int cell = getMazeCell(row, col);

            initCell(cell, K::col_path);

            if (hasRight(cell))
            {
                initCell(right(cell), K::col_wall);
            }
            if (hasBottom(cell))
            {
                initCell(bottom(cell), K::col_wall);
            }
            if (hasDiagonal(cell))
            {
                initCell(diagonal(cell), K::col_wall);
            }
        }
    }
}

/**
 * Colors the cell on the right or bottom of current cell,
 * if the current cell has an edge in either direction.
 */
void Grid::update(int row, int col, const sf::Color &color)
{
    int gridCell = getMazeCell(row, col);
    int cell = maze.getCell(row, col);

    if (maze.hasRight(cell) && maze.hasEdge(maze.getCell(row, col), maze.RIGHT))
    {
        cells[right(gridCell)].setFillColor(color);
    }
    if (maze.hasLeft(cell) && maze.hasEdge(maze.getCell(row, col), maze.BOTTOM))
    {
        cells[bottom(gridCell)].setFillColor(color);
    }
}

/**
 * Initialises grid cell and sets its screen position.
 */
void Grid::initCell(int cell, const sf::Color &color)
{
    cells[cell].setSize(sf::Vector2f(K::cell_width, K::cell_height));
    cells[cell].setPosition(sf::Vector2f(K::grid_offset_x + col(cell) * K::cell_width, K::grid_offset_y + row(cell) * K::cell_height));

    if (K::OUTLINE)
    {
        cells[cell].setOutlineColor(K::col_outline);
        cells[cell].setOutlineThickness(3);
    }
    cells[cell].setFillColor(color);
}