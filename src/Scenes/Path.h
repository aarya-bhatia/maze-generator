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
    Matrix::Coord *start; // start cell of the view matrix
    Matrix::Coord *end;   // end cell of the view matrix

    Path(const Math::Matrix &view_matrix) : view_matrix(view_matrix),
                                            list(view_matrix.size())
    {
        if (K::DEBUG)
        {
            std::cout << "Path constructor" << std::endl;
        }
        init();
    }

    ~Path()
    {
        if (K::DEBUG)
        {
            std::cout << "Path Destructor" << std::endl;
        }
    }

    void set(const Math::Matrix::Coord &neighbour, const Math::Matrix::Coord &current)
    {
        list[key(neighbour)] = key(current);
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