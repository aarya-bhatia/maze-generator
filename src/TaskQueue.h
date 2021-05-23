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

    int countPending() const
    {
        return queue.size();
    }

    void add(Task task)
    {
        queue.push(task);
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

    TaskQueue()
    {
        if (K::DEBUG)
        {
            std::cout << "TaskQueue constructor" << std::endl;
        }
    }

    ~TaskQueue()
    {
        if (K::DEBUG)
        {
            std::cout << "TaskQueue destructor" << std::endl;
        }
    }

private:
    std::queue<Task> queue;
};