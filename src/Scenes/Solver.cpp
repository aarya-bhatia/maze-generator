#include "Solver.hpp"

void Solver::init()
{
    start = Matrix::mapToGrid(maze->matrix.as2D(maze->start));
    end = Matrix::mapToGrid(maze->matrix.as2D(maze->end));
    visited = std::vector<bool>(grid->matrix.size());

    for (int i = 0; i < grid->matrix.size(); i++)
    {
        visited[i] = false;
        (*path)[i] = *Matrix::Coord::getNull();
    }

    while (!queue.empty())
    {
        queue.pop();
    }

    queue.push(start);

    if (K::DEBUG)
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": To solve maze from cell " << start << " to cell " << end << std::endl;
    }
}

/**
 * Main Algorithm
 */
void Solver::next()
{
    if (finished())
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": Path found" << std::endl;
        return;
    }

    if (!queue.empty())
    {
        current = queue.front();
        queue.pop();

        Matrix::Coord mazeCoord = Matrix::mapToMaze(current);

        // Visit the neighbours in all four directions of the current cell.
        // Add each neighbour to the queue if it is not explored yet.
        for (int i = 1; i <= 4; i++)
        {
            Dir::dir_t dir = static_cast<Dir::dir_t>(i);

            if (mazeCoord.has(maze->matrix, dir) &&
                current.has(grid->matrix, dir) &&
                maze->hasEdge(mazeCoord, dir) &&
                !visited[current.get(dir).as1D(grid->matrix)])
            {
                Matrix::Coord neighbour = current.get(dir);
                visited[neighbour.as1D(grid->matrix)] = true;
                (*path)[neighbour.as1D(grid->matrix)] = current;
                queue.push(neighbour);
            }
        }
    }
    else
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": No path found" << std::endl;
    }
}

void Solver::log() const
{

    std::cout << "Path: [";
    for (int i = 0; i < grid->matrix.size(); i++)
    {
        std::cout << (*path)[i] << " ";
    }
    std::cout << "]\n";

    int c = 0;
    for (int i = 0; i < grid->matrix.size(); i++)
    {
        if (visited[i])
        {
            c++;
        }
    }
    std::cout << "Visited cells: " << c << std::endl;
    std::cout << "Unvisited cells: " << grid->matrix.size() - c << std::endl;
}