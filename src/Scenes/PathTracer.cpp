#include "PathTracer.hpp"

void PathTracer::next()
{
    if (current != *Matrix::Coord::getNull())
    {
        current = (*path)[current.as1D(grid->matrix)];
    }
}

bool PathTracer::finished()
{
    return Matrix::Coord::isNull(current);
}

void PathTracer::init()
{
    start = Matrix::mapToGrid(maze->matrix.as2D(maze->start));
    end = Matrix::mapToGrid(maze->matrix.as2D(maze->end));
    current = end;
}

void PathTracer::update()
{
    grid->cells[current.as1D(grid->matrix)].setFillColor(color);
}

void PathTracer::log() const
{
    std::cout << "Path: [";
    Matrix::Coord tmp = current;
    while (Matrix::Coord::isNull(tmp) && tmp != start)
    {
        std::cout << tmp << " ";
        tmp = (*path)[tmp.as1D(grid->matrix)];
    }
    std::cout << tmp << " ";
    std::cout << "]" << std::endl;
}