#pragma once

#include "Scene.hpp"
#include "Grid.hpp"

class PathTracer : public Scene
{
public:
    Matrix::Coord current;
    bool tracing;
    bool firstIter = true;

    explicit PathTracer(const SceneData *data) : Scene(data, K::col_tracer), current(data->end), tracing(true)
    {
        if (K::DEBUG)
        {
            std::cout << "PathTracer constructor" << std::endl;
        }
    }

    ~PathTracer()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
        if (K::SCENE_LOG)
        {
            log();
        }
    }

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