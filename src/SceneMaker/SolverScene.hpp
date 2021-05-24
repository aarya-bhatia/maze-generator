#pragma once

#include "SceneMaker.hpp"
#include "Solver.hpp"

struct SolverScene : public SceneMaker
{
    Scene *operator()(SceneData &data) override
    {
        return new Solver(data);
    }
};