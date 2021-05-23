#pragma once

#include "Scene.hpp"
#include "Grid.hpp"
#include "Generator.hpp"
#include "Solver.hpp"
#include "PathTracer.hpp"

#include <memory>
#include <list>
#include <queue>
#include <vector>

std::unique_ptr<Scene> createGenerator(std::shared_ptr<Grid> grid, std::shared_ptr<Maze> maze, std::shared_ptr<std::vector<Matrix::Coord>> path)
{
    return std::unique_ptr<Scene>(new Generator(grid, maze, path));
}

std::unique_ptr<Scene> createSolver(std::shared_ptr<Grid> grid, std::shared_ptr<Maze> maze, std::shared_ptr<std::vector<Matrix::Coord>> path)
{
    return std::unique_ptr<Scene>(new Solver(grid, maze, path));
}

std::unique_ptr<Scene> createTracer(std::shared_ptr<Grid> grid, std::shared_ptr<Maze> maze, std::shared_ptr<std::vector<Matrix::Coord>> path)
{
    return std::unique_ptr<Scene>(new PathTracer(grid, maze, path));
}

class Animation : public Component
{
private:
    std::shared_ptr<Maze> maze;
    std::shared_ptr<Grid> grid;
    std::shared_ptr<std::vector<Matrix::Coord>> path;
    std::vector<std::unique_ptr<Scene>> scenes;

    struct task
    {
        int id;
        std::unique_ptr<Scene> (*fptr)(std::shared_ptr<Grid> grid, std::shared_ptr<Maze> maze, std::shared_ptr<std::vector<Matrix::Coord>> path);
    };

    std::queue<task> queue;

    int sceneIndex;
    int numScenes;

public:
    void update() override
    {
        if (finished())
        {
            return;
        }

        if (scenes[sceneIndex]->finished())
        {
            assert(!queue.empty());
            nextScene();
        }

        std::unique_ptr<Scene> &scene = scenes[sceneIndex];
        scene->next();
        scene->update();
    }

    bool finished()
    {
        return sceneIndex >= numScenes;
    }

    void render(sf::RenderWindow &window) override
    {
        if (!finished())
        {
            scenes[sceneIndex]->render(window);
        }
    }

    void nextScene()
    {
        if (queue.empty())
        {
            if (K::DEBUG)
            {
                std::cout << __FILE__ << ":" << __LINE__ << ": Scene queue is empty" << std::endl;
            }
            return;
        }
        if (K::DEBUG)
        {
            std::cout << __FILE__ << ":" << __LINE__ << ": Starting Next Scene: ID=" << queue.front().id << std::endl;
        }
        scenes[sceneIndex++] = queue.front().fptr(grid, maze, path);
        queue.pop();
    }

    void init()
    {
        queue = std::queue<task>();
        queue.push((task){1, &createGenerator});
        queue.push((task){2, &createSolver});
        queue.push((task){3, &createTracer});

        numScenes = queue.size();
        assert(numScenes == 3);

        scenes = std::vector<std::unique_ptr<Scene>>(numScenes);

        maze = std::make_shared<Maze>(K::maze_cols, K::maze_rows);
        grid = std::make_shared<Grid>(maze->matrix);
    }

    Animation() : sceneIndex(-1)
    {
        init();
    }
};