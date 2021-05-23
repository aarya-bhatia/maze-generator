#pragma once

#include "Matrix.hpp"
#include <vector>

class Path
{
private:
    Math::Matrix view_matrix; // grid
    std::vector<int> list;

    int key(const Math::Matrix::Coord &coord) const
    {
        return coord.as1D(view_matrix);
    }

    void init()
    {
        for (int i = 0; i < list.size(); i++)
        {
            list[i] = -1;
        }
    }

public:
    Path(const Math::Matrix &view_matrix) : view_matrix(view_matrix),
                                            list(view_matrix.size())
    {
        init();
    }

    void set(const Math::Matrix::Coord &from, const Math::Matrix::Coord &to)
    {
        list[key(to)] = key(from);
    }

    Math::Matrix::Coord get(const Math::Matrix::Coord &coord) const
    {
        return view_matrix.as2D(list[key((coord))]);
    }

    bool has(const Math::Matrix::Coord &coord) const
    {
        return list[key(coord)] != -1;
    }
};