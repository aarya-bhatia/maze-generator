#include "Test.hpp"

namespace Test
{
    void test_inverse()
    {
        using namespace Math;
        std::cout << "TESTING INVERSE" << std::endl;

        using namespace Dir;
        assert(inverse(top) == bottom);
        assert(inverse(bottom) == top);
        assert(inverse(right) == left);
        assert(inverse(left) == right);
    }

    void test_is_y()
    {
        using namespace Math;
        std::cout << "TESTING IS Y" << std::endl;

        using namespace Dir;
        assert(isY(top));
        assert(isY(bottom));
        assert(!isY(right));
        assert(!isY(left));
    }

    void test_is_x()
    {
        using namespace Math;
        std::cout << "TESTING IS X" << std::endl;

        using namespace Dir;
        assert(isX(right));
        assert(isX(left));
        assert(!isX(top));
        assert(!isX(bottom));
    }
}
