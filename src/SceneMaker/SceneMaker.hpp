#pragma once

#include "Scene.hpp"

struct SceneMaker
{
    virtual Scene *operator()(const SceneData *data) = 0;
    virtual ~SceneMaker() {}
};