#include "Decl.hpp"
#include "Matrix.hpp"
#include "Dir.hpp"

#include <iostream>

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

namespace Test
{
    void test_matrix()
    {
        using namespace Math;
        std::cout << "TESTING MATRIX" << std::endl;

        Matrix mat(2, 3);
        assert(mat.width == 2);
        assert(mat.height == 3);
        assert(mat.size() == 6);

        Matrix::Coord cell(0, 1);
        int cell1D = cell.as1D(mat);

        assert(cell.in(mat));

        assert(mat.as2D(cell.as1D(mat)) == cell);
        assert(mat.row(cell1D) == cell.row);
        assert(mat.col(cell1D) == cell.col);

        assert(mat.hasBottom(cell));
        assert(!mat.hasTop(cell));
        assert(!mat.hasRight(cell));
        assert(mat.hasLeft(cell));

        Matrix::Coord neighbour = mat.bottom(cell);

        assert(neighbour.in(mat));
        assert(neighbour.row == cell.row + 1);
        assert(neighbour.col == cell.col);

        int pos = cell.as1D(mat);
        std::cout << pos << std::endl;
        assert(pos == cell.row * mat.width + cell.col);

        std::cout << cell;
        std::cout << std::endl;

        std::cout << neighbour;
        std::cout << std::endl;

        std::cout << mat.as2D(pos);
        std::cout << std::endl;

        assert(cell == mat.as2D(pos));
    }
}

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

int main()
{
    std::cout << "STARTING TESTS" << std::endl;
    Test::test_bits();
    Test::test_inverse();
    Test::test_is_x();
    Test::test_is_y();
    Test::test_matrix();
    Test::test_coord();
    std::cout << "FINISHED TESTS" << std::endl;
    return 0;
}