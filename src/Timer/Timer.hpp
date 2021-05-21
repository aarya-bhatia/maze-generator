#include <chrono>
#include <iostream>

#ifndef TIMER_HPP
#define TIMER_HPP

struct Timer
{
    std::chrono::steady_clock::time_point startTime;

    void start();

    void stop();

    Timer()
    {
        start();
    }

    ~Timer()
    {
        stop();
    }
};

#endif