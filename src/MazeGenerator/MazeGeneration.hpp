#include "Maze.hpp"
#include "Grid.hpp"
#include "K.hpp"

#include <iostream>

#ifndef MAZE_GENERATION_HPP
#define MAZE_GENERATION_HPP

void createMaze(Maze &maze);

struct MazeGeneration
{
    Maze &maze;

    int iterations;

    struct Current
    {
        int cell;
        int neighbour;
    };

    Current current;

    void generate();

    void next();

    bool finished() const;

    explicit MazeGeneration(Maze &m) : maze(m), iterations(0)
    {
    }

    void update(Grid &grid);

    void log() const;
};

#endif