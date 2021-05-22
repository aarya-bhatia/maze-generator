#include "Grid.hpp"

void Grid::init()
{
    for (int row = 0; row < matrix.height; row++)
    {
        for (int col = 0; col < matrix.width; col++)
        {
            initCell(Matrix::Coord(row, col));
        }
    }
}

void Grid::initCell(Matrix::Coord coord, const sf::Color &color)
{
    int cell = coord.as1D(matrix);

    cells[cell].setSize(sf::Vector2f(K::cell_width, K::cell_height));
    cells[cell].setPosition(sf::Vector2f(K::grid_xoff + coord.col * K::cell_width, K::grid_yoff + coord.row * K::cell_height));

    if (K::OUTLINE)
    {
        cells[cell].setOutlineColor(K::col_outline);
        cells[cell].setOutlineThickness(3);
    }

    cells[cell].setFillColor(color);
}