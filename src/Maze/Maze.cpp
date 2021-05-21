#include "Maze.hpp"

void Maze::printEdges() const
{
    for (int cell = 0; cell < size(); cell++)
    {
        std::cout << "cell " << cell << ": [ ";

        if (hasTop(cell) && hasEdge(cell, TOP))
        {
            std::cout << top(cell) << " up ";
        }

        if (hasRight(cell) && hasEdge(cell, RIGHT))
        {
            std::cout << right(cell) << " right ";
        }

        if (hasLeft(cell) && hasEdge(cell, LEFT))
        {
            std::cout << left(cell) << " left ";
        }

        if (hasBottom(cell) && hasEdge(cell, BOTTOM))
        {
            std::cout << bottom(cell) << " bottom ";
        }

        std::cout << "]\n";
    }

    std::cout << "EDGES:[";
    int i;
    for (i = 0; i < size() - 1; i++)
    {
        std::cout << edges[i] << ", ";
    }
    std::cout << edges[i] << "]\n";
}

void Maze::print() const
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int cell = getCell(i, j);

            if (cell == start)
            {
                std::cout << "S";
            }
            else if (cell == end)
            {
                std::cout << "E";
            }
            else
            {
                std::cout << (hasEdge(cell, BOTTOM) ? K::HORZ_WALL : K::PATH);
            }

            std::cout << (hasEdge(cell, RIGHT) ? K::VERT_WALL : K::PATH);
        }

        std::cout << "\n";
    }
}

Maze *Maze::create()
{
    Maze *maze = new Maze(K::maze_cols, K::maze_rows);
    maze->start = 0;
    maze->end = maze->size() - 1;
    return maze;
}

/**
 * Function to count number of set bits i.e outgoing edges of a cell
 */
int Maze::countEdges(int cell) const
{
    int n = edges[cell];
    int c = 0;

    while (n)
    {
        n = n & (n - 1);
        c++;
    }

    return c;
}