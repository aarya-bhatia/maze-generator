#include "Solver.hpp"

void Solver::init()
{
    for (int i = 0; i < data->grid->matrix.size(); i++)
    {
        visited[i] = false;
    }

    queue.push(data->start);

    if (K::DEBUG)
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": To solve data->maze from cell " << data->start << " to cell " << data->end << std::endl;
    }
}

/**
 * Main Algorithm
 */
void Solver::next()
{
    if (finished() || !solving)
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": Path found" << std::endl;
        return;
    }

    if (!queue.empty())
    {
        current = queue.front();
        queue.pop();
        visited[current.as1D(data->grid->matrix)] = true;

        Matrix::Coord mazeCoord = Matrix::mapToMaze(current);

        // Visit the neighbours in all four directions of the current cell.
        // Add each neighbour to the queue if it is not explored yet.
        for (int i = 1; i <= 4; i++)
        {
            Dir::dir_t dir = static_cast<Dir::dir_t>(i);

            if (mazeCoord.has(data->maze->matrix, dir) && current.has(data->grid->matrix, dir) &&
                data->maze->hasEdge(mazeCoord, dir) && !visited[current.get(dir).as1D(data->grid->matrix)])
            {
                queue.push(current.get(dir));
                visited[current.get(dir).as1D(data->grid->matrix)] = true;
                data->path->set(current.get(dir), current);
            }
        }
    }
    else
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": No path found" << std::endl;
        solving = false;
    }
}

void Solver::log() const
{
    int c = 0;
    for (int i = 0; i < data->grid->matrix.size(); i++)
    {
        if (visited[i])
        {
            c++;
        }
    }
    std::cout << "Visited cells: " << c << std::endl;
    std::cout << "Unvisited cells: " << data->grid->matrix.size() - c << std::endl;
}