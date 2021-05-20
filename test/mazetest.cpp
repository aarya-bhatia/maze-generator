#include "Maze.hpp"
#include "MazeGeneration.hpp"

#define MAZE_W 3
#define MAZE_H 3

int test(int argc, const char *argv[])
{
    int w = (--argc > 1 ? atoi(argv[1]) : MAZE_W);
    int h = (--argc > 1 ? atoi(argv[2]) : MAZE_H);

    srand(time(0));
    Maze maze(w, h);

    maze.start = rand() % maze.size();
    maze.end = rand() % maze.size();

    std::cout << "maze width: " << maze.width << std::endl;
    std::cout << "maze height: " << maze.height << std::endl;

    std::cout << "start: " << maze.start << std::endl;
    std::cout << "end: " << maze.end << std::endl;

    createMaze(maze);
    maze.print();

    // std::list<int> offPath;
    // std::list<int> onPath;

    // maze.set.getPathList(maze.start, onPath, offPath);

    // std::cout << "on path: [";

    // for (std::list<int>::const_iterator itr = onPath.begin(); itr != onPath.end(); itr++)
    // {
    //     std::cout << *itr << " ";
    // }

    // std::cout << "]\n";

    // std::cout << "off path: [";

    // for (std::list<int>::const_iterator itr = offPath.begin(); itr != offPath.end(); itr++)
    // {
    //     std::cout << *itr << " ";
    // }

    // std::cout << "]\n";

    return 0;
}