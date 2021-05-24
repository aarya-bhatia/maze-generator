#pragma once

#include "Task.hpp"

#include <iostream>
#include <queue>

class TaskQueue
{
private:
    std::queue<Task *> queue;

public:
    int size() const
    {
        return queue.size();
    }

    void enqueue(Task *task)
    {
        std::cout << "Adding task" << task->id << " to queue..." << std::endl;
        queue.push(task);
    }

    void dequeue()
    {
        queue.pop();
    }

    Task *peek() const
    {
        return queue.front();
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
};