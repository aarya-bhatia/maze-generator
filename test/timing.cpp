#include "Timer.hpp"

int main()
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
}

/* mkdir -p obj/test bin/test; g++ -Wall -g -std=c++14 -Isrc/Timer -c test/timing.cpp -o obj/test/timing.o; g++ obj/test/timing.o -o bin/test/timing; */