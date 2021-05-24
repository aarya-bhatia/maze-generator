#pragma once

#include "Task.hpp"
#include "GeneratorScene.hpp"

struct GeneratorTask : public Task
{
    GeneratorTask(int id) : Task(id, new GeneratorScene()) {}
};
