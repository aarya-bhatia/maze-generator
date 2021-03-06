#include "PathTracer.hpp"

void PathTracer::next()
{
    if (firstIter)
    {
        firstIter = false;
        return;
    }

    if (data->path->has(current))
    {
        current = data->path->get(current);
        // std::cout << __FILE__ << ": " << __LINE__ << ": Current coord: " << current << std::endl;
    }
    else
    {
        // std::cout << "finished tracer" << std::endl;
        tracing = false;
    }
}

bool PathTracer::finished()
{
    return !tracing;
}

void PathTracer::update()
{
    data->grid->cells[current.as1D(data->grid->matrix)].setFillColor(color);
}

void PathTracer::log() const
{
    std::cout << "Path: [";
    Matrix::Coord tmp = current;
    while (data->path->has(tmp))
    {
        std::cout << tmp << " ";
        tmp = data->path->get(tmp);
    }
    std::cout << tmp << " ";
    std::cout << "]" << std::endl;
}