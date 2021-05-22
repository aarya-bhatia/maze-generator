#include "Generator.hpp"

// Main Algorithm to generate the maze!
void Generator::next()
{
    if (!finished())
    {
        iterations++;
        Dir::dir_t dir = static_cast<Dir::dir_t>(rand() % 4);
        Matrix::Coord coord = maze->matrix.as2D(rand() % set.size());

        if (coord.has(maze->matrix, dir) && !hasPath(coord.as1D(maze->matrix), coord.get(dir).as1D(maze->matrix)))
        {
            set.make_union(coord.as1D(maze->matrix), coord.get(dir).as1D(maze->matrix));
            maze->addEdge(coord.as1D(maze->matrix), dir);
            maze->addEdge(coord.get(dir).as1D(maze->matrix), static_cast<Dir::dir_t>(Dir::inverse(dir)));

            current.maze_coord = coord;
            current.dir = dir;

            foundNext = true;
        }
    }
}

// color the path cells picked by the generator
void Generator::update()
{
    if (foundNext)
    {
        foundNext = false;

        Matrix::Coord firstCell = Matrix::mapToGrid(current.maze_coord);
        Matrix::Coord linkingCell = firstCell.get(current.dir);
        Matrix::Coord secondCell = Matrix::mapToGrid(current.maze_coord.get(current.dir));

        colorCell(firstCell);
        colorCell(linkingCell);
        colorCell(secondCell);
    }
}