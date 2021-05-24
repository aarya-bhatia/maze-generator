#include "Decl.hpp"
#include "Bits.hpp"
#include "Dir.hpp"

#include <iostream>

namespace Test
{
    void test_bits()
    {
        using namespace Math;
        std::cout << "TESTING BITS" << std::endl;

        int field = 0;

        Bits::setOn(field, Dir::top);
        Bits::setOn(field, Dir::bottom);

        assert(field == (1 << Dir::top) + (1 << Dir::bottom));

        Bits::setOff(field, Dir::bottom);

        assert(field != 0);
        assert(field == 1 << Dir::top);

        assert(Bits::contains(field, Dir::top));
        assert(!Bits::contains(field, Dir::bottom));
        assert(!Bits::contains(field, Dir::left));

        Bits::setOn(field, Dir::right);
        assert(Bits::contains(field, Dir::right));

        assert(Bits::countOn(field) == 2);

        Bits::setOff(field, Dir::top);
        assert(Bits::countOn(field) == 1);

        std::cout << __FILE__ << ": All tests passed" << std::endl;
    }
}