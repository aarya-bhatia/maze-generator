/**
 * CONSTANTS AND GLOBALS
 */

#include <SFML/Graphics/Color.hpp>
#include <string>

#ifndef K_HPP
#define K_HPP

namespace K
{
    static const bool AUTOPLAY = true;
    static const bool DEBUG = true;
    static const bool OUTLINE = true;

    static const bool TRACER = true;
    static const bool SOLVER = true;

    static const std::string title = "MAZE GENERATOR";

    static const char PATH = '.';
    static const char VERT_WALL = '|';
    static const char HORZ_WALL = '_';

    static const int screen_width = 1960;
    static const int screen_height = 1715;

    static int cell_width = 100;
    static int cell_height = 100;

    static int maze_width = 6;
    static int maze_height = 6;

    static int grid_columns = 2 * maze_width - 1;
    static int grid_rows = 2 * maze_height - 1;

    static int grid_width = grid_columns * cell_width;
    static int grid_height = grid_rows * cell_height;

    static int grid_offset_x = fmax(0, fmin(screen_width / 2, (screen_width - cell_width * grid_columns) / 2));
    static int grid_offset_y = fmax(0, fmin(screen_height / 2, (screen_height - cell_height * grid_rows) / 2));

    static const unsigned int alpha = 150;

    static const sf::Color col_wall = sf::Color(50, 50, 50, alpha);
    static const sf::Color col_path = sf::Color(50, 150, 250, alpha);
    static const sf::Color col_outline = sf::Color(150, 150, 150, alpha);
    static const sf::Color col_explore = sf::Color(6, 68, 32, (int)(1.5 * alpha) % 255);
    static const sf::Color col_tracer = sf::Color(228, 239, 231, (int)(1.5 * alpha) % 255);
    static const sf::Color col_text = sf::Color::White;
    static const sf::Color col_selected_text = sf::Color::Yellow;

    static const std::string RES_DIR = "res/";

    static const std::string FONT_DIR = RES_DIR + "fonts/";

    static const std::string IMAGE_DIR = RES_DIR + "images/";

    static const std::string FONT_AMATIC_REGULAR = FONT_DIR + "amatic/AmaticSC-Regular.ttf";

    static const std::string FONT_CAVIAR_DREAMS_BOLD = FONT_DIR + "Caviar-Dreams/Caviar_Dreams_Bold.ttf";

    static const std::string FONT_CAVIAR_DREAMS_REGULAR = FONT_DIR + "Caviar-Dreams/CaviarDreams.ttf";

    static const std::string FONT_FIRA_SANS_BOLD = FONT_DIR + "fira-sans/FiraSans-Bold.otf";

    static const unsigned int char_size = 100U;

    static const std::string BACKGROUND_IMAGE_FILE = IMAGE_DIR + "background/starry.jpg";

    static const float slider_width = (screen_width * 0.45f);
    static const float slider_height = 5;
    static const float slider_radius = 7.5f;
    static const float slider_x_off = 0.5 * (screen_width - slider_width);

    static const int MAX_ROWS = 50;
    static const int MIN_ROWS = 3;
    static const int MAX_COLS = 50;
    static const int MIN_COLS = 3;

};

#endif