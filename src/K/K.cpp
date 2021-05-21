/**
 * Implementation
 */

#include "K.hpp"

namespace K
{
    const bool AUTOPLAY = true;
    const bool DEBUG = true;
    const bool OUTLINE = true;

    const bool TRACER = true;
    const bool SOLVER = true;

    const std::string title = "MAZE GENERATOR";

    const char PATH = '.';
    const char VERT_WALL = '|';
    const char HORZ_WALL = '_';

    const int screen_width = 1960;
    const int screen_height = 1715;

    int cell_width = 100;
    int cell_height = 100;

    int maze_width = 6;
    int maze_height = 6;

    int grid_columns = 2 * maze_width - 1;
    int grid_rows = 2 * maze_height - 1;

    int grid_width = grid_columns * cell_width;
    int grid_height = grid_rows * cell_height;

    int grid_offset_x = fmax(0, fmin(screen_width / 2, (screen_width - cell_width * grid_columns) / 2));
    int grid_offset_y = fmax(0, fmin(screen_height / 2, (screen_height - cell_height * grid_rows) / 2));

    const unsigned int alpha = 150;

    const sf::Color col_wall = sf::Color(50, 50, 50, alpha);
    const sf::Color col_path = sf::Color(50, 150, 250, alpha);
    const sf::Color col_outline = sf::Color(150, 150, 150, alpha);
    const sf::Color col_explore = sf::Color(6, 68, 32, (int)(1.5 * alpha) % 255);
    const sf::Color col_tracer = sf::Color(228, 239, 231, (int)(1.5 * alpha) % 255);
    const sf::Color col_text = sf::Color::White;
    const sf::Color col_selected_text = sf::Color::Yellow;

    const std::string RES_DIR = "res/";

    const std::string FONT_DIR = RES_DIR + "fonts/";

    const std::string IMAGE_DIR = RES_DIR + "images/";

    const std::string FONT_AMATIC_REGULAR = FONT_DIR + "amatic/AmaticSC-Regular.ttf";

    const std::string FONT_CAVIAR_DREAMS_BOLD = FONT_DIR + "Caviar-Dreams/Caviar_Dreams_Bold.ttf";

    const std::string FONT_CAVIAR_DREAMS_REGULAR = FONT_DIR + "Caviar-Dreams/CaviarDreams.ttf";

    const std::string FONT_FIRA_SANS_BOLD = FONT_DIR + "fira-sans/FiraSans-Bold.otf";

    const unsigned int char_size = 100U;

    const std::string BACKGROUND_IMAGE_FILE = IMAGE_DIR + "background/starry.jpg";

    const float slider_width = (screen_width * 0.45f);
    const float slider_height = 5;
    const float slider_radius = 7.5f;
    const float slider_x_off = 0.5 * (screen_width - slider_width);

    const int MAX_ROWS = 50;
    const int MIN_ROWS = 3;
    const int MAX_COLS = 50;
    const int MIN_COLS = 3;

};