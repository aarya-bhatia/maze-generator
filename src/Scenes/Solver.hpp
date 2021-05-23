#include "K.hpp"
#include "PathTracer.hpp"
#include "Grid.hpp"
#include <queue>

#include "Scene.hpp"

#ifndef MAZE_SOLVER_HPP
#define MAZE_SOLVER_HPP

/**
 * Solves the maze step by step using BFS
 */
class Solver : public Scene
{
private:
    std::vector<bool> visited;
    std::queue<Matrix::Coord> queue;

    Matrix::Coord start;
    Matrix::Coord end;
    Matrix::Coord current; /* The cell currently being explored */

public:
    explicit Solver(std::shared_ptr<Grid> grid,
                    std::shared_ptr<Maze> maze,
                    std::shared_ptr<std::vector<Matrix::Coord>> path)
        : Scene(grid, maze, path, K::col_explore),
          current(*Matrix::Coord::getNull())
    {
        init();
    }

    /**
     * updates the color of the cell currently being explored by the maze solver
     */
    void update() override
    {
        grid->cells[current.as1D(grid->matrix)].setFillColor(color);
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
        return current == end;
    }

    /**
     * Print DEBUG info
     */
    void log() const;
};

#endif