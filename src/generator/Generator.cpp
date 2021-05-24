#include "Generator.hpp"

// Main Algorithm to generate the maze!
void Generator::next()
{
    if (!finished())
    {
        iterations++;

        // Pick random direction
        Dir::dir_t dir = static_cast<Dir::dir_t>(rand() % 4);

        // Pick random cell
        Matrix::Coord coord = data.maze->matrix.as2D(rand() % set.size());

        // If there isn't a path from this coord to its neighbour in the
        // specific direction.
        if (coord.has(data.maze->matrix, dir) &&
            !hasPath(coord.as1D(data.maze->matrix),
                     coord.get(dir).as1D(data.maze->matrix)))
        {
            next(coord, dir);
        }
    }
}

// Make path from coord to its neighbour in the given direction
void Generator::next(Matrix::Coord coord, Dir::dir_t dir)
{
    // update the union set with the coord and its neighbour
    set.make_union(coord.as1D(data.maze->matrix), coord.get(dir).as1D(data.maze->matrix));

    // update the maze by adding the corresponding edges in both directions
    // that is, from coord to neighbour and back
    data.maze->addEdge(coord.as1D(data.maze->matrix), dir);
    data.maze->addEdge(coord.get(dir).as1D(data.maze->matrix), static_cast<Dir::dir_t>(Dir::inverse(dir)));

    // update the current maze coord and direction for the render method
    current_maze_coord = coord;
    current_dir = dir;

    // enable the render method to update the required cells
    foundNext = true;
}

// color the path cells picked by the generator
void Generator::update()
{
    if (foundNext)
    {
        foundNext = false;

        Matrix::Coord firstCell = Matrix::mapToGrid(current_maze_coord);
        Matrix::Coord linkingCell = firstCell.get(current_dir);
        Matrix::Coord secondCell = Matrix::mapToGrid(current_maze_coord.get(current_dir));

        colorCell(firstCell);
        colorCell(linkingCell);
        colorCell(secondCell);
    }
}