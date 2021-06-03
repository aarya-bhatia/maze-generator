#include <chrono>
#include <iostream>

#ifndef TIMER_HPP
#define TIMER_HPP

struct Timer
{
    std::chrono::steady_clock::time_point start;

    Timer() : start(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        std::cout << "Time taken=" << duration.count() * 1.0e6f << " microseconds" << std::endl;
    }
};

#endif