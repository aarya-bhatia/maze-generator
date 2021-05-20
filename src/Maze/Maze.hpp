#include "DisjSet.hpp"
#include "K.hpp"

#ifndef MAZE_HPP
#define MAZE_HPP

class Maze
{
private:
    int *edges;

public:
    int width;
    int height;
    int start;
    int end;
    DisjSet set;

    const static int TOP = 1;
    const static int RIGHT = 2;
    const static int BOTTOM = 4;
    const static int LEFT = 8;

    Maze(int w, int h) : width(w), height(h), start(0), end(size() - 1), set(size())
    {
        edges = new int[size()];
    }

    ~Maze()
    {
        delete[] edges;
    }

    static Maze *create();

    int countEdges(int cell) const;

    int size() const
    {
        return width * height;
    }

    int getCell(int row, int col) const
    {
        return row * width + col;
    }

    int row(int cell) const
    {
        return cell / width;
    }

    int column(int cell) const
    {
        return cell % height;
    }

    int top(int cell) const
    {
        return cell - width;
    }

    int bottom(int cell) const
    {
        return cell + width;
    }

    int left(int cell) const
    {
        return cell - 1;
    }

    int right(int cell) const
    {
        return cell + 1;
    }

    bool hasRight(int cell) const
    {
        return column(cell) < width - 1;
    }

    bool hasLeft(int cell) const
    {
        return column(cell) > 0;
    }

    bool hasTop(int cell) const
    {
        return row(cell) > 0;
    }

    bool hasBottom(int cell) const
    {
        return row(cell) < height - 1;
    }

    void addEdge(int cell, int dir)
    {
        edges[cell] |= dir;
    }

    bool hasEdge(int cell, int dir) const
    {
        return edges[cell] & dir;
    }

    bool hasEdges(int cell) const
    {
        return edges[cell];
    }

    void printEdges() const;

    void print() const;

    bool hasPath(int x, int y)
    {
        return set.find(x) == set.find(y);
    }

    int getGridCell(int row, int col) const
    {
        return getCell((int)row / 2, (int)col / 2);
    }
};

#endif