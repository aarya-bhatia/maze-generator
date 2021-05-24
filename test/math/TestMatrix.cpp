#include "Test.hpp"
#include "Matrix.hpp"

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