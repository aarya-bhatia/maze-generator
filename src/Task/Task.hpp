#pragma once

#include "SceneMaker.hpp"

struct Task
{
    SceneMaker *maker;
    int id;

    Task(int id, SceneMaker *maker) : maker(maker), id(id) {}

    virtual ~Task()
    {
        delete maker;
    }
};