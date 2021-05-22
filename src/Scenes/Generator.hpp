#pragma once

#include "DisjSet.hpp"
#include "Maze.hpp"
#include "Grid.hpp"
#include "K.hpp"
#include "Scene.hpp"

#include <memory>

//
// Maze Generator Scene class
//
// Description:
//
// The maze generator scene starts with an empty grid i.e,
// no two cells have a path between them, so they are colored
// in a different color.
//
// The generator then randomly picks two cells ie. a cell and a direction.
// If the cell does not have a path to its neighbour in that direction,
// then we update the disjoint-union set so that the next time, we know
// whether there is a path between the cells. We also have to
// color the cells of the grid that are to be added to the maze path.
//
// This requires us to map between the maze coord and grid coord
// since the grid has twice the number of rows and columns due to
// the presence of walls between every two cells.
//
// @author aarya.bhatia
///
class Generator : public Scene
{
private:
    DisjSet set;    /* data structure to represent the connected cells in the maze */
    int iterations; /* number of iterations of the scene */
    bool foundNext; /* whether a cell is to be updated in current iteration */

    struct Current
    {
        Matrix::Coord maze_coord;
        Dir::dir_t dir;
    };

    Current current;

    // colors the cell at given coord in the maze to the scene color
    void colorCell(Matrix::Coord coord)
    {
        grid->cells[coord.as1D(grid->matrix)].setFillColor(color);
    }

    // helper to check if there is a path between two cells in the maze
    bool hasPath(int x, int y)
    {
        return set.find(x) == set.find(y);
    }

public:
    // next iteration
    void next() override;

    // add the current cell, its neighbour and the linking cell to the maze path
    void update() override;

    // checks if there is a path from start to end in the maze
    bool finished() override
    {
        return hasPath(maze->start, maze->end);
    }

    void log() const
    {
        std::cout << "iterations: " << iterations << std::endl;
        std::cout << "set: " << set << std::endl;
    }

    explicit Generator(std::shared_ptr<Grid> grid) : Scene(grid, K::col_path),
                                                     set(maze->matrix.size()),
                                                     iterations(0),
                                                     foundNext(false)
    {
    }
};