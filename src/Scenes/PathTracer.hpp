#include "Grid.hpp"

#ifndef PATH_TRACER_HPP
#define PATH_TRACER_HPP

class PathTracer
{
public:
    std::vector<int> path;
    int current; // the cell we are currently at
    int start;
    int end;

    PathTracer(const Maze &maze, const Grid &grid, const std::vector<int> &p) : path(p)
    {
        init(maze, grid);
    }

    void init(const Maze &, const Grid &);
    void next();
    bool finished() const;

    /**
     * updates the color of the cell color currently being traced by the path tracer
     */
    void update(Grid &grid);

    /**
     * Print actual path
     */
    void log() const;
};

#endif