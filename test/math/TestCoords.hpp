#include "Test.hpp"
#include "Matrix.hpp"

namespace Test
{
    void test_coord()
    {
        using namespace Math;
        std::cout << "TESTING COORD" << std::endl;

        Matrix mat(2, 3);
        Matrix::Coord c1(0, 1);

        assert(c1.in(mat));

        assert(c1.has(mat, Dir::left));
        assert(c1.has(mat, Dir::bottom));

        assert(!c1.has(mat, Dir::top));
        assert(!c1.has(mat, Dir::right));

        assert(c1.get(Dir::top) == mat.top(c1.as1D(mat)));
        assert(c1.get(Dir::bottom) == mat.bottom(c1.as1D(mat)));
        assert(c1.get(Dir::right) == mat.right(c1.as1D(mat)));
        assert(c1.get(Dir::left) == mat.left(c1.as1D(mat)));

        Matrix::Coord c = c1;
        std::cout << "Left " << c << " = " << c.get(Dir::left) << std::endl;
        std::cout << "Bottom " << c << " = " << c.get(Dir::bottom) << std::endl;
    }
}
