//
// Created by Aarya Bhatia on 23/05/21.
//

#include "SceneManager.h"

SceneManager::SceneManager() : len(0), current(0)
{
    scenes = std::vector<Scene *>();
}

SceneManager::~SceneManager()
{
    for (Scene *scene : scenes)
    {
        delete scene;
    }
}

Scene *SceneManager::get() const
{
    return scenes[current];
}

void SceneManager::put(Scene *scene)
{
    scenes[len++] = scene;
}

bool SceneManager::hasNext() const
{
    return current < len - 1;
}

void SceneManager::next()
{
    current++;
}