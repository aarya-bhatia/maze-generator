#pragma once

#include "Task.hpp"
#include "TracerScene.hpp"

struct TracerTask : public Task
{
    TracerTask(int id) : Task(id, new TracerScene()) {}
};