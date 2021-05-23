#include "Animation.hpp"

void Animation::update()
{
    if (finished())
    {
        return;
    }
    if (currentScene->finished())
    {
        currentScene = scenes[sceneIndex++];
    }
    else
    {
        std::cout << "Updating app..." << std::endl;
        currentScene->next();
        currentScene->update();
    }
}

void Animation::handleEvent(const sf::Event &event)
{
    if (K::DEBUG)
    {
        std::cout << __FILE__ << ":" << __LINE__ << ": Event happened..." << std::endl;
    }
}

void Animation::nextScene()
{
    if (!queue.empty())
    {
        if (K::DEBUG)
        {
            std::cout << "Starting Next Scene: ID=" << queue.front().id << std::endl;
        }
        currentScene = queue.front().fptr(grid, maze, path);
        scenes[sceneIndex++] = currentScene;
        queue.pop();
    }
}

void Animation::init()
{
    // queue = std::queue<task>();
    // queue.push((task){1, &createGenerator});
    // queue.push((task){2, &createSolver});
    // queue.push((task){3, &createTracer});

    scenes = std::vector<Scene *>(numScenes);
    maze = new Maze(K::maze_cols, K::maze_rows);
    grid = new Grid(maze->matrix);
    path = std::vector<Matrix::Coord *>(grid->matrix.size());

    scenes[0] = createGenerator(grid, maze, path);
    scenes[1] = createSolver(grid, maze, path);
    scenes[2] = createTracer(grid, maze, path);

    numScenes = 3;
    sceneIndex = 0;
    currentScene = scenes[0];
}

void Animation::render(sf::RenderWindow &window)
{
    std::cout << "Rendering app..." << std::endl;
    if (!finished() && currentScene != nullptr)
    {
        currentScene->render(window);
    }
}

bool Animation::finished() const
{
    return sceneIndex >= numScenes;
}

Animation::~Animation()
{
    for (int i = 0; i < numScenes; i++)
    {
        if (scenes[i] != nullptr)
        {
            delete scenes[i];
        }
    }

    delete grid;
    delete maze;
}