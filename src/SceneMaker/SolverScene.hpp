#pragma once

#include "SceneMaker.hpp"
#include "Solver.hpp"

struct SolverScene : public SceneMaker
{
    Scene *operator()(const SceneData *data) override
    {
        return new Solver(data);
    }
};