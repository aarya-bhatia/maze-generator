#include "Test.hpp"

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