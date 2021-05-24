#pragma once

#include "Bits.hpp"
#include "Matrix.hpp"
#include "K.hpp"

#include <iostream>
#include <vector>

using namespace Math;

struct Maze
{
    int width;
    int height;

    Matrix matrix;
    std::vector<int> edges;

    int start;
    int end;

    explicit Maze(int width, int height) : width(width),
                                           height(height),
                                           matrix(width, height),
                                           edges(matrix.size()),
                                           start(0),
                                           end(matrix.size() - 1)
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }

    ~Maze()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }

    int countEdges(int cell) { return Bits::countOn(edges[cell]); }

    void addEdge(int cell, Dir::dir_t dir) { Bits::setOn(edges[cell], dir); }

    void removeEdge(int cell, Dir::dir_t dir) { Bits::setOff(edges[cell], dir); }

    bool hasEdge(int cell, Dir::dir_t dir) const
    {
        return Bits::contains(edges[cell], dir);
    }

    bool hasEdge(Matrix::Coord coord, Dir::dir_t dir) const
    {
        return coord.in(matrix) && Bits::contains(edges[coord.as1D(matrix)], dir);
    }

    bool hasAnyEdge(int cell) const { return edges[cell]; }
};
