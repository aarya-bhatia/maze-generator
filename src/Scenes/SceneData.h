#pragma once

#include "Grid.hpp"
#include "Path.h"
#include "K.hpp"

struct SceneData
{
    Grid *grid;
    Maze *maze;
    Path *path;

    Matrix::Coord start; // start cell of the view matrix
    Matrix::Coord end;   // end cell of the view matrix

    SceneData()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
        maze = new Maze(K::maze_cols, K::maze_rows);
        grid = new Grid(maze->matrix);
        path = new Path(grid->matrix);

        Matrix::Coord maze_start = maze->matrix.as2D(maze->start);
        Matrix::Coord maze_end = maze->matrix.as2D(maze->end);

        start = Matrix::mapToGrid(maze_start);
        end = Matrix::mapToGrid(maze_end);

        path->start = &start;
        path->end = &end;
    }

    void setEnd(Matrix::Coord c)
    {
        end = c;
    }

    ~SceneData()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
        delete path;
        delete maze;
        delete grid;
    }
};