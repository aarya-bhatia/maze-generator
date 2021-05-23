#pragma once

#include "Scene.hpp"
#include <queue>

class TaskQueue
{
public:
    struct Task
    {
        int id;
        Scene *(*fptr)(SceneData &);
    };

    int countTotal() const
    {
        return total;
    }

    int countPending() const
    {
        return queue.size();
    }

    void add(Task task)
    {
        queue.push(task);
        total++;
    }

    Task next()
    {
        return queue.front();
        queue.pop();
    }

    TaskQueue() {}

    ~TaskQueue() {}

private:
    std::queue<Task> queue;
    int total;
};