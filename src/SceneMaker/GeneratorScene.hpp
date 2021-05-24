#pragma once

#include "SceneMaker.hpp"
#include "Generator.hpp"

struct GeneratorScene : public SceneMaker
{
    Scene *operator()(const SceneData *data) override
    {
        return new Generator(data);
    }
};
