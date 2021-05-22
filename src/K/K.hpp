#include <SFML/Graphics/Color.hpp>
#include <string>

#ifndef K_HPP
#define K_HPP

/**
 * CONSTANTS AND GLOBAL VARIABLES
 */
namespace K
{
    extern const bool AUTOPLAY; /* whether to run animation automatically */
    extern const bool DEBUG;    /* whether to enable debug console logs */
    extern const bool OUTLINE;  /* whether to outline cells */

    extern const bool TRACER; /* whether to enable path tracer */
    extern const bool SOLVER; /* whether to enable maze solver */

    extern const char *title; /* window title */

    extern const int screen_width;  /* width of window in pixels */
    extern const int screen_height; /* height of window in pixels */

    extern int cell_width;  /* width of cell in pixels */
    extern int cell_height; /* height of cell in pixels */

    extern int maze_cols; /* number of columns in maze */
    extern int maze_rows; /* number of rows in maze */

    extern int grid_cols; /* contains maze columns with walls in between */
    extern int grid_rows; /* contains maze rows with walls in between */

    extern int grid_width;  /* grid width in pixels */
    extern int grid_height; /* grid height in pixels */

    extern int grid_xoff; /* x offset of grid from top left corner of window */
    extern int grid_yoff; /* y offset of grid from top left corner of window */

    extern const float slider_width;  /* width of slider */
    extern const float slider_height; /* height of slider */
    extern const float slider_radius; /* radius of slider marker */
    extern const float slider_x_off;  /* x offset of slider on window */

    extern const int MAX_ROWS;
    extern const int MIN_ROWS;
    extern const int MAX_COLS;
    extern const int MIN_COLS;

    extern const unsigned int alpha; /* alpha of colors */

    /**
     * COLORS USED IN THE APPLICATION
     */

    extern const sf::Color col_wall;
    extern const sf::Color col_path;
    extern const sf::Color col_outline;
    extern const sf::Color col_explore;
    extern const sf::Color col_tracer;
    extern const sf::Color col_text;
    extern const sf::Color col_selected_text;

    extern const std::string RES_DIR;   /* resources directory path */
    extern const std::string FONT_DIR;  /* fonts directory path */
    extern const std::string IMAGE_DIR; /* images directory path */

    /**
     * FONTS AND IMAGE RELATIVE PATHS
     */

    extern const std::string FONT_AMATIC_REGULAR;
    extern const std::string FONT_CAVIAR_DREAMS_BOLD;
    extern const std::string FONT_CAVIAR_DREAMS_REGULAR;
    extern const std::string FONT_FIRA_SANS_BOLD;
    extern const std::string BACKGROUND_IMAGE_FILE;

    extern const unsigned int CHARACTER_SIZE; /* size of font characters in pixel */
};

#endif