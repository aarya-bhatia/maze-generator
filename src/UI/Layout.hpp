#pragma once

#include "K.hpp"

class Layout
{
    int n; // num items

    int y_spacing;

    //
    // @param sh screen height
    // @param h character size
    // @param n number of items
    //
    int get_y_spacing(int sh, int h, int n)
    {
        return (sh - n * h) / (1 + n);
    }

    int get_y_off(int sh, int h, int n)
    {
        return n * get_y_spacing(sh, h, n) + fmax(0, n - 1) * h;
    }

    int get_x_off(int line_width)
    {
    }

    Layout(int n) : n(n)
    {
    }
};