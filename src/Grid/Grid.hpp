#include "K.hpp"
#include "Maze.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

#ifndef GRID_HPP
#define GRID_HPP

/**
 * A grid struct contains a list of cells as rectangles.
 * The list is stored as a 1D array, however, it is
 * easy to map the cells to its 2D row and column.
 * 
 * The colors of the cell are updated in each iteration of
 * the application cycle accordingly. 
 * 
 * The grid contains twice (minus one) the rows and cols of
 * the maze because adjacent cells are used to represent
 * the "walls" of the maze. Use the helper methods to map
 * between maze cell and grid cells.
 */
class Grid
{
public:
    int width;
    int height;

    std::vector<sf::RectangleShape> cells;

    const Maze &maze;

    Grid(const Maze &m) : width(K::grid_columns), height(K::grid_rows), cells(size()), maze(m)
    {
        init();
    }

    /**
     * initialises path cells and wall cells alternately
     */
    void init();

    /**
     * update generator cell
     */
    void update(int row, int col, const sf::Color &color);

    /**
     * helper method to initialise a cell as SFML rectangle
     */
    void initCell(int cell, const sf::Color &color = K::col_path);

    /**
     * @return size of the GRID.
     * Note: grid size = 4 (maze size) because additional cells are
     * used as walls in between the maze cells.
     */
    int size() const
    {
        return width * height;
    }

    /**
     * @return maps a cell to its 2D row
     */
    int row(int cell) const
    {
        return cell / width;
    }

    /**
     * @return maps a cell to its 2D column
     */
    int col(int cell) const
    {
        return cell % width;
    }

    /**
     * @return checks whether cell has a column to its right
     */
    bool hasRight(int cell) const
    {
        return col(cell) < width - 1;
    }

    /**
     * @return checks whether cell has a row below its current row
     */
    bool hasBottom(int cell) const
    {
        return row(cell) < height - 1;
    }

    /**
     * @return checks whether cell has a row under and column in front of it
     */
    bool hasDiagonal(int cell) const
    {
        return hasRight(cell) && hasBottom(cell);
    }

    bool hasLeft(int cell) const
    {
        return col(cell) > 0;
    }

    bool hasTop(int cell) const
    {
        return row(cell) > 0;
    }

    /**
     * @return cell on the right of this cell
     */
    int right(int cell) const
    {
        return getCell(row(cell), col(cell) + 1);
    }

    /**
     * @return cell on the bottom of this cell
     */
    int bottom(int cell) const
    {
        return getCell(row(cell) + 1, col(cell));
    }

    int left(int cell) const
    {
        return getCell(row(cell), col(cell) - 1);
    }

    int top(int cell) const
    {
        return getCell(row(cell) - 1, col(cell));
    }

    /**
     * @return the cell one column on the right and one row under this cell
     */
    int diagonal(int cell) const
    {
        assert(hasDiagonal(cell));
        return getCell(row(cell) + 1, col(cell) + 1);
    }

    /**
     * @return maps 2D cell coordinates to 1D array index
     */
    int getCell(int row, int col) const
    {
        return row * width + col;
    }

    /**
     * @return maps 2D maze cell coordinates to 1D Grid cell index
     */
    int getMazeCell(int row, int col) const
    {
        return getCell(2 * row, 2 * col);
    }
};

#endif