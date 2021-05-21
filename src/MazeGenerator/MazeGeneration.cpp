#include "MazeGeneration.hpp"

void MazeGeneration::next()
{
    if (finished())
    {
        return;
    }

    iterations++;

    int direction = rand() % 4;
    int cell = rand() % maze.size();

    switch (direction)
    {
    case 0:
        if (maze.hasTop(cell) && !hasPath(cell, maze.top(cell)))
        {
            current.cell = cell;
            current.neighbour = maze.top(cell);

            set.make_union(cell, maze.top(cell));
            maze.addEdge(cell, Maze::TOP);
            maze.addEdge(maze.top(cell), Maze::BOTTOM);
        }
        break;

    case 1:
        if (maze.hasRight(cell) && !hasPath(cell, maze.right(cell)))
        {
            current.cell = cell;
            current.neighbour = maze.right(cell);

            set.make_union(cell, maze.right(cell));
            maze.addEdge(cell, Maze::RIGHT);
            maze.addEdge(maze.right(cell), Maze::LEFT);
        }
        break;

    case 2:
        if (maze.hasBottom(cell) && !hasPath(cell, maze.bottom(cell)))
        {
            current.cell = cell;
            current.neighbour = maze.bottom(cell);

            set.make_union(cell, maze.bottom(cell));
            maze.addEdge(cell, Maze::BOTTOM);
            maze.addEdge(maze.bottom(cell), Maze::TOP);
        }
        break;

    case 3:
        if (maze.hasLeft(cell) && !hasPath(cell, maze.left(cell)))
        {
            current.cell = cell;
            current.neighbour = maze.left(cell);

            set.make_union(cell, maze.left(cell));
            maze.addEdge(cell, Maze::LEFT);
            maze.addEdge(maze.left(cell), Maze::RIGHT);
        }
        break;
    }
}

bool MazeGeneration::finished()
{
    return hasPath(maze.start, maze.end);
}

void createMaze(Maze &maze)
{
    MazeGeneration(maze).generate();
}

void MazeGeneration::generate()
{
    while (!finished())
    {
        next();
    }
    if (K::DEBUG)
    {
        log();
    }
}
/**
 * updates the color of the cell selected by the generator to be in the path of the maze
 */
void MazeGeneration::update(Grid &grid)
{
    grid.update(maze.row(current.cell), maze.column(current.cell), K::col_path);
    grid.update(maze.row(current.neighbour), maze.column(current.neighbour), K::col_path);
}

void MazeGeneration::log() const
{
    std::cout << "iterations: " << iterations << std::endl;
    std::cout << "set: " << set << std::endl;
}