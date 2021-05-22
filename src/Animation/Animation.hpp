#include "Scene.hpp"
#include "Grid.hpp"

#include "Generator.hpp"
#include "Solver.hpp"
#include "PathTracer.hpp"

#include <list>

#pragma once

static Scene *createGenerator(Grid &grid)
{
    return new Generator(grid);
}

static Scene *createSolver(Grid &grid)
{
    return new Solver(grid);
}

static Scene *createTracer(Grid &grid)
{
    return new Tracer(grid);
}

struct SceneCreator
{
    typedef Scene *(*new_scene)(Grid &);

    std::list<new_scene> scenes;

    void push(new_scene scene)
    {
        scenes.push_back(scene);
    }

    Scene *pop(Grid &grid)
    {
        new_scene scene = scenes.front();
        scenes.pop_front();
        return scene(grid);
    }
};

struct Animation : public Component
{
    Grid *grid;
    SceneCreator builder;
    std::vector<Scene *> scenes;
    Scene *scene;

    enum SceneType
    {
        Generator,
        Solver,
        Tracer
    };

    void update() override
    {
        if (scene == nullptr)
        {
            return;
        }

        if (scene->finished())
        {
            nextScene();
        }
        else
        {
            scene->next();
            scene->update();
        }
    }

    Scene *nextScene()
    {
        scenes.push_back(builder.pop(*grid));
        scene = scenes.back();
    }

    void changeScene(SceneType num)
    {
        grid->reset();
        scene = scenes[num];
    }

    void init()
    {
        builder = SceneCreator();
        builder.push((SceneCreator::new_scene)createGenerator);
        builder.push((SceneCreator::new_scene)createSolver);
        builder.push((SceneCreator::new_scene)createTracer);

        grid = new Grid(maze_rows, maze_cols);
        nextScene();
    }

    Animation()
    {
    }

    ~Animation()
    {
        while (!scenes.empty())
        {
            Scene *scene = scenes.back();
            scenes.pop_back();
            delete scene;
        }
    }
};