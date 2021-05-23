#pragma once

#include "K.hpp"
#include "Scene.hpp"
#include "PathTracer.hpp"

#include <queue>

/**
 * Solves the maze step by step using BFS
 */
class Solver : public Scene
{
private:
    std::vector<bool> visited;
    std::queue<Matrix::Coord> queue;
    Matrix::Coord current;
    bool solving;

public:
    explicit Solver(SceneData &data) : Scene(data, K::col_explore),
                                       visited(data.grid->matrix.size()),
                                       queue(),
                                       current(data.start),
                                       solving(true)
    {
        init();
    }

    ~Solver()
    {
    }

    /**
     * updates the color of the cell currently being explored by the maze solver
     */
    void update() override
    {
        data.grid->cells[current.as1D(data.grid->matrix)].setFillColor(color);
    }

    /**
     * initialise data members
     */
    void init() override;

    /**
     * advance current to next cell in the search and update the queue
     */
    void next() override;

    /**
     * @return checks if search is completed
     */
    bool finished() override
    {
        return current == data.end;
    }

    /**
     * Print DEBUG info
     */
    void log() const;
};