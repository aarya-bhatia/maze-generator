//
// Created by Aarya Bhatia on 23/05/21.
//

#ifndef MAZE_GENERATOR_SCENEMANAGER_H
#define MAZE_GENERATOR_SCENEMANAGER_H

#include "Scene.hpp"

#include <vector>

class SceneManager {
private:
    std::vector<Scene *> scenes;
    int len;
    int current;
public:
    SceneManager();

    ~SceneManager();

    bool hasNext() const;

    void next();

    Scene &get() const;

    void put(Scene *scene);
};

#endif //MAZE_GENERATOR_SCENEMANAGER_H
