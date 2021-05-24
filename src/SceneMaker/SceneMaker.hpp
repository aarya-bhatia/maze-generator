#pragma once

#include "Scene.hpp"

struct SceneMaker
{
    virtual Scene *operator()(SceneData &data) = 0;
};