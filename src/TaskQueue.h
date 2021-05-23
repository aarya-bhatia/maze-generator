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
        auto ret = queue.front();
        queue.pop();
        return ret;
    }

    bool finished() const
    {
        return queue.empty();
    }

    TaskQueue() {}

    ~TaskQueue() {}

private:
    std::queue<Task> queue;
    int total;
};