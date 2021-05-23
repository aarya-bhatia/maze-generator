#pragma once

namespace Math
{
    namespace Bits
    {
        ///
        // @param field the bit field
        // @param bit the position to set on the bit
        ///
        static inline void setOn(int &field, int bit)
        {
            field |= (1 << bit);
        }

        ///
        // @param field the bit field
        // @param bit the position to set off the bit
        ///
        static inline void setOff(int &field, int bit)
        {
            field &= ~(1 << bit);
        }

        ///
        // @param field the bit field
        // @param bit the position to check bit for
        // @return check if field contains bit in specified position
        ///
        static inline bool contains(int field, int bit)
        {
            return field & (1 << bit);
        }

        ///
        // helper to count set bits in a number
        ///
        static inline int countOn(int c, int n)
        {
            return n ? countOn(c + 1, n & (n - 1)) : c;
        }

        ///
        // @return counts the set bits in number
        ///
        static inline int countOn(int n)
        {
            return countOn(0, n);
        }
    }
}