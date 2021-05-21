/**
 * CONSTANTS AND GLOBALS
 */

#include <SFML/Graphics/Color.hpp>
#include <string>

#ifndef K_HPP
#define K_HPP

namespace K
{
    extern const bool AUTOPLAY;
    extern const bool DEBUG;
    extern const bool OUTLINE;

    extern const bool TRACER;
    extern const bool SOLVER;

    extern const std::string title;

    extern const char PATH;
    extern const char VERT_WALL;
    extern const char HORZ_WALL;

    extern const int screen_width;
    extern const int screen_height;

    extern int cell_width;
    extern int cell_height;

    extern int maze_width;
    extern int maze_height;

    extern int grid_columns;
    extern int grid_rows;

    extern int grid_width;
    extern int grid_height;

    extern int grid_offset_x;
    extern int grid_offset_y;

    extern const unsigned int alpha;

    extern const sf::Color col_wall;
    extern const sf::Color col_path;
    extern const sf::Color col_outline;
    extern const sf::Color col_explore;
    extern const sf::Color col_tracer;
    extern const sf::Color col_text;
    extern const sf::Color col_selected_text;

    extern const std::string RES_DIR;
    extern const std::string FONT_DIR;
    extern const std::string IMAGE_DIR;
    extern const std::string FONT_AMATIC_REGULAR;
    extern const std::string FONT_CAVIAR_DREAMS_BOLD;
    extern const std::string FONT_CAVIAR_DREAMS_REGULAR;
    extern const std::string FONT_FIRA_SANS_BOLD;
    extern const std::string BACKGROUND_IMAGE_FILE;

    extern const unsigned int char_size;

    extern const float slider_width;
    extern const float slider_height;
    extern const float slider_radius;
    extern const float slider_x_off;

    extern const int MAX_ROWS;
    extern const int MIN_ROWS;
    extern const int MAX_COLS;
    extern const int MIN_COLS;

};

#endif