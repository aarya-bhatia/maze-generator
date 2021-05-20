#include "PathTracer.hpp"

void PathTracer::next()
{
    if (current != -1)
    {
        current = path[current];
    }
}

bool PathTracer::finished() const
{
    return current == -1;
}

void PathTracer::init(const Maze &maze, const Grid &grid)
{
    start = grid.getMazeCell(maze.row(maze.start), maze.column(maze.start));
    end = grid.getMazeCell(maze.row(maze.end), maze.column(maze.end));
    current = end;
}

void PathTracer::update(Grid &grid)
{
    grid.cells[current].setFillColor(K::col_tracer);
}

void PathTracer::log() const
{
    std::cout << "Path: [";
    int tmp = current;
    while (tmp != -1 && tmp != start)
    {
        std::cout << tmp << " ";
        tmp = path[tmp];
    }
    std::cout << tmp << " ";
    std::cout << "]" << std::endl;
}