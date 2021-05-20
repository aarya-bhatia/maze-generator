#include "MazeSolver.hpp"

void MazeSolver::init()
{
    start = grid.getMazeCell(maze.row(maze.start), maze.column(maze.start));
    end = grid.getMazeCell(maze.row(maze.end), maze.column(maze.end));

    visited = std::vector<bool>(size());
    path = std::vector<int>(size());

    for (int i = 0; i < size(); i++)
    {
        visited[i] = false;
        path[i] = -1;
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

void MazeSolver::next()
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
        update();
    }
    else
    {
        std::cout << __FILE__ << ": " << __LINE__ << ": No path found" << std::endl;
    }
}

void MazeSolver::visit(int cell)
{
    visited[cell] = true;
    path[cell] = current;
    queue.push(cell);
}

void MazeSolver::update()
{
    int mazeCell = maze.getGridCell(grid.row(current), grid.col(current));
    int gridLeft = grid.left(current);
    int gridRight = grid.right(current);
    int gridTop = grid.top(current);
    int gridBottom = grid.bottom(current);

    if (maze.hasTop(mazeCell) && maze.hasEdge(mazeCell, maze.TOP) &&
        grid.hasTop(current) && !visited[gridTop])
    {
        visit(gridTop);
    }

    if (maze.hasRight(mazeCell) && maze.hasEdge(mazeCell, maze.RIGHT) &&
        grid.hasRight(current) && !visited[gridRight])
    {
        visit(gridRight);
    }

    if (maze.hasBottom(mazeCell) && grid.hasBottom(current) &&
        maze.hasEdge(mazeCell, maze.BOTTOM) && !visited[gridBottom])
    {
        visit(gridBottom);
    }

    if (maze.hasLeft(mazeCell) && grid.hasLeft(current) &&
        maze.hasEdge(mazeCell, maze.LEFT) && !visited[gridLeft])
    {
        visit(gridLeft);
    }
}

void MazeSolver::log() const
{

    std::cout << "Path: [";
    for (int i = 0; i < size(); i++)
    {
        std::cout << path[i] << " ";
    }
    std::cout << "]\n";

    int c = 0;
    for (int i = 0; i < size(); i++)
    {
        if (visited[i])
        {
            c++;
        }
    }
    std::cout << "Visited cells: " << c << std::endl;
    std::cout << "Unvisited cells: " << size() - c << std::endl;
}