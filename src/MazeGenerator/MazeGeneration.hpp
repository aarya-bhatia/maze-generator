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

    DisjSet set;

    int iterations = 0;

    struct Current
    {
        int cell;
        int neighbour;
    };

    Current current;

    void generate();

    void next();

    bool finished();

    explicit MazeGeneration(Maze &m) : maze(m), set(maze.size())
    {
    }

    bool hasPath(int x, int y)
    {
        return set.find(x) == set.find(y);
    }

    void update(Grid &grid);

    void log() const;
};

#endif