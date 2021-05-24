#pragma once

#include "Task.hpp"
#include "SolverScene.hpp"

struct SolverTask : public Task
{
    SolverTask(int id) : Task(id, new SolverScene()) {}
};