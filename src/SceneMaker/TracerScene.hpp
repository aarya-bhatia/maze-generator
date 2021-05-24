#pragma once

#include "SceneMaker.hpp"
#include "PathTracer.hpp"

struct TracerScene : public SceneMaker
{
    Scene *operator()(const SceneData *data) override
    {
        return new PathTracer(data);
    }
};
