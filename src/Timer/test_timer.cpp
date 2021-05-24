#include "Timer.hpp"

int TimerTest()
{
    {
        Timer t;

        int value = 0;

        for (int i = 0; i < 1000; i++)
        {
            value += value * 4000;

            value = value % 24;

            value = (5000 - value) / value;

            value = value % 100;
        }

        std::cout << "value is " << value << std::endl;
    }

    return 0;
}