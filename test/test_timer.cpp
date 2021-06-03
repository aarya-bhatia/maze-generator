#include "Timer.hpp"

struct Coord
{
    int row;
    int col;

    Coord(int row, int col) : row(row), col(col) {}

    Coord get_1(int dir)
    {
        if (dir == 1)
        {
            return Coord(row - 1, col);
        }
        else if (dir == 2)
        {
            return Coord(row, col + 1);
        }
        else if (dir == 3)
        {
            return Coord(row + 1, col);
        }
        else
        {
            return Coord(row, col - 1);
        }
    }

    Coord get_2(int dir)
    {
        return Coord(
            row + (dir & 1) * ((dir & 2) - 1),
            col + (~dir & 1) * ((dir & 2) - 1));
    }

    friend std::ostream &operator<<(std::ostream &out, const Coord &c)
    {
        out << "(" << c.row << ", " << c.col << ")";
        return out;
    }
};

bool run_test_0(int numIter)
{
    Timer t;

    Coord c(2, 2);

    for (int i = 0; i < numIter; i++)
    {
        int dir = 1 + (rand() % 4);
        Coord c2 = c.get_1(dir);
        Coord c3 = c.get_2(dir);

        std::cout << "c2: " << c2 << std::endl;
        std::cout << "c3: " << c3 << std::endl;

        if (c2.row != c3.row || c2.col != c3.col)
        {
            return false;
        }
    }

    return true;
}

void run_test_1(int n)
{
    Timer t;

    Coord c(5, 5);

    for (int i = 0; i < n; i++)
    {
        c = c.get_1(1 + (rand() % 4));
    }
}

void run_test_2(int n)
{
    Timer t;

    Coord c(5, 5);

    for (int i = 0; i < n; i++)
    {
        c = c.get_2(1 + (rand() % 4));
    }
}

int main()
{
    srand(time(0));

    std::cout << "calculating coords with method 1: ";
    run_test_1(100);

    std::cout << "calculating coords with method 2: ";
    run_test_2(100);

    return 0;
}