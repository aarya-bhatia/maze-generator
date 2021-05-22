#include "K.hpp"
#include "PathTracer.hpp"
#include "Grid.hpp"
#include <queue>

#ifndef MAZE_SOLVER_HPP
#define MAZE_SOLVER_HPP

/**
 * Solves the maze step by step using BFS
 */
class Solver
{
private:
    std::vector<bool> visited;
    std::queue<int> queue;

    const Maze &maze;
    const Grid &grid;

    int start;
    int end;

    /**
     * updates the queue with unvisited neighbours of current cell
     */
    void update();

public:
    std::vector<int> path; /* stores the order in which cells are explored */
    int current;           /* The cell currently being explored */

    explicit Solver(const Maze &m, const Grid &g) : maze(m), grid(g), current(-1)
    {
        init();
    }

    /**
     * updates the color of the cell currently being explored by the maze solver
     */
    void update(Grid &grid)
    {
        grid.cells[current].setFillColor(K::col_explore);
    }

    /**
     * initialise data members
     */
    void init();

    /**
     * @return grid cell count
     */
    int size() const
    {
        return grid.size();
    }

    /**
     * advance current to next cell in the search and update the queue
     */
    void next();

    /**
     * @return checks if search is completed
     */
    bool finished() const
    {
        return current == end;
    }

    void visit(int cell);

    /**
     * Print K::DEBUG info
     */
    void log() const;
};

#endif