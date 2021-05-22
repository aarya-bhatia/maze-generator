#include "Dir.hpp"

#include <iostream>

#pragma once

namespace Math
{
    //A wrapper class to control basic grid actions.
    //It allows us to represent a 2d matrix as a 1d matrix.
    //It also allows us to go back and forth between the 1d and 2d form of the matrix.
    class Matrix
    {
    public:
        int width;  // cols
        int height; // rows

        //@param width number of cols
        //@param height number of rows
        explicit Matrix(int width, int height) : width(width), height(height) {}

        Matrix(const Matrix &matrix) : width(matrix.width), height(matrix.height) {}

        Matrix &operator=(const Matrix &matrix)
        {
            if (this != &matrix)
            {
                width = matrix.width;
                height = matrix.height;
            }
            return *this;
        }

        bool operator==(const Matrix &matrix)
        {
            return width == matrix.width && height == matrix.height;
        }

        bool operator!=(const Matrix &matrix)
        {
            return !(*this == matrix);
        }

        ~Matrix() {}

        // Represents a single cell of the matrix as 2D (row, col)
        class Coord
        {
        public:
            int row;
            int col;

            explicit Coord(int row = 0, int col = 0) : row(row), col(col) {}

            // construct coord from another coord
            Coord(const Coord &c) : row(c.row), col(c.col) {}

            ~Coord() {}

            // copies the given coord c
            Coord &operator=(const Coord &c)
            {
                if (this != &c)
                {
                    row = c.row;
                    col = c.col;
                }
                return *this;
            }

            friend std::ostream &operator<<(std::ostream &out, const Coord &coord)
            {
                out << "(" << coord.row << "," << coord.col << ")";
                return out;
            }

            // checks if the coord is equal to given coord
            bool operator==(const Coord &c)
            {
                return row == c.row && col == c.col;
            }

            // checks if the coord is not equal to given coord
            bool operator!=(const Coord &c)
            {
                return !(*this == c);
            }

            // maps a 2d coord to a 1d position
            int as1D(const Matrix &matrix) const
            {
                return row * matrix.width + col;
            }

            // checks if the coord is contained within matrix
            bool in(const Matrix &matrix) const
            {
                return row >= 0 && row < matrix.height && col >= 0 && col < matrix.width;
            }

            // @returns the new coord in the specified direction of this coord
            //
            // If the first bit of dir is 0, we change the column.
            // If the first bit of dir is 1, we change the row.
            // If the second bit of dir is 0, we decrement the row/col.
            // If the second bit of dir is 1, we increment the row/col.
            //
            // By multplying the result of the first part and the second part,
            // we get a unified formula for the new coord
            Coord get(Dir::dir_t d) const
            {
                return Coord(getRow(d), getCol(d));
            }

            int getRow(Dir::dir_t d) const
            {
                return row + (d & 1) * ((d & 2) - 1);
            }

            int getCol(Dir::dir_t d) const
            {
                return col + (~d & 1) * ((d & 2) - 1);
            }

            // checks if the coord in the specified direction exists
            bool has(const Matrix &matrix, Dir::dir_t dir) const
            {
                return get(dir).in(matrix);
            }
        };

        //  number of cells in grid
        int size() const
        {
            return width * height;
        }

        // maps a cell to its 2D row
        int row(int cell) const
        {
            return cell / height;
        }

        // maps a cell to its 2D column
        int col(int cell) const
        {
            return cell % width;
        }

        // checks whether cell has a column to its right
        bool hasRight(int cell) const
        {
            return col(cell) < width - 1;
        }

        // checks whether cell has a row below its current row
        bool hasBottom(int cell) const
        {
            return row(cell) < height - 1;
        }

        // checks whether cell has a row under and column in front of it
        bool hasDiagonal(int cell) const
        {
            return hasRight(cell) && hasBottom(cell);
        }

        // checks whether this cell has column before it
        bool hasLeft(int cell) const
        {
            return col(cell) > 0;
        }

        // checks whether this cell has row above it
        bool hasTop(int cell) const
        {
            return row(cell) > 0;
        }

        // the cell in the following column
        Coord right(int cell) const
        {
            return Coord(row(cell), col(cell) + 1);
        }

        // the cell in the following row
        Coord bottom(int cell) const
        {
            return Coord(row(cell) + 1, col(cell));
        }

        // the cell in the previous column
        Coord left(int cell) const
        {
            return Coord(row(cell), col(cell) - 1);
        }

        // the cell in the previous row
        Coord top(int cell) const
        {
            return Coord(row(cell) - 1, col(cell));
        }

        // the cell in the following row and following column
        Coord diagonal(int cell) const
        {
            return Coord(row(cell) + 1, col(cell) + 1);
        }

        // maps 2D cell coordinates to 1D array index
        int as1D(int row, int col) const
        {
            return row * width + col;
        }

        // maps 1d position to a 2d coord
        Coord as2D(int cell) const
        {
            return Coord(row(cell), col(cell));
        }

        Coord top(Coord c) const
        {
            return c.get(Dir::top);
        }

        Coord bottom(Coord c) const
        {
            return c.get(Dir::bottom);
        }

        Coord right(Coord c) const
        {
            return c.get(Dir::right);
        }

        Coord left(Coord c) const
        {
            return c.get(Dir::left);
        }

        Coord diagonal(const Coord &c) const
        {
            return Coord(c.getRow(Dir::bottom), c.getCol(Dir::right));
        }

        bool hasRight(Coord c) const
        {
            return c.has(*this, Dir::right);
        }

        bool hasLeft(Coord c) const
        {
            return c.has(*this, Dir::left);
        }

        bool hasTop(Coord c) const
        {
            return c.has(*this, Dir::top);
        }

        bool hasBottom(Coord c) const
        {
            return c.has(*this, Dir::bottom);
        }

        bool hasDiagonal(Coord c) const
        {
            return c.has(*this, Dir::right) && c.has(*this, Dir::bottom);
        }

        // maps a grid coord to maze coord
        static Coord mapToGrid(Coord c)
        {
            return Coord(c.row * 2, c.col * 2);
        }

        // maps a maze coord to grid coord
        static Coord mapToMaze(Coord c)
        {
            return Coord(c.row / 2, c.col / 2);
        }

        // returns the coord in the given direction of given coord
        Coord get(const Coord &cell, Dir::dir_t dir)
        {
            return cell.get(dir);
        }

        // checks if this matrix contains this cell
        bool has(const Coord &cell)
        {
            return cell.in(*this);
        }
    };
}