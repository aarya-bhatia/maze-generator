#include "Timer.hpp"

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::chrono::microseconds elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    double milliseconds = static_cast<double>(elapsed_time.count() * 0.001);
    std::cout << "Elapsed time: " << milliseconds << std::endl;
}