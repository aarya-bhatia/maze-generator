#include "K.hpp"
#include "Slider.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

class Settings
{
public:
    sf::Font font;

    sf::Text section_label_maze;
    sf::Text slider_label_rows;
    sf::Text slider_label_cols;

    Slider mazeRowsSlider = Slider(K::maze_rows, K::MIN_ROWS, K::MAX_ROWS);
    Slider mazeColsSlider = Slider(K::maze_cols, K::MIN_COLS, K::MAX_COLS);

    Settings()
    {
        mazeRowsSlider.init(0);
        mazeColsSlider.init(0);
    }
};

#endif