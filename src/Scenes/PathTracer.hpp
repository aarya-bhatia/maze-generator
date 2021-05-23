#include "Scene.hpp"
#include "Grid.hpp"

#ifndef PATH_TRACER_HPP
#define PATH_TRACER_HPP

class PathTracer : public Scene
{
public:
    Matrix::Coord current;
    Matrix::Coord start;
    Matrix::Coord end;

    PathTracer(std::shared_ptr<Grid> grid,
               std::shared_ptr<Maze> maze,
               std::shared_ptr<std::vector<Matrix::Coord>> path) : Scene(grid, maze, path, K::col_tracer)
    {
        init();
    }

    void init() override;
    void next() override;
    bool finished() override;

    /**
     * updates the color of the cell color currently being traced by the path tracer
     */
    void update() override;

    /**
     * Print actual path
     */
    void log() const;
};

#endif