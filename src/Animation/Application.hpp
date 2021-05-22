#include "K.hpp"
#include "Grid.hpp"
#include "State.hpp"
#include "MazeGeneration.hpp"
#include "Menu.hpp"
#include "FontManager.hpp"
#include "ImageManager.hpp"

class PathTracer;
class Solver;

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

struct Application
{
    State *state;
    Maze *maze;
    Grid *grid;
    Generator *generator;
    Solver *solver;
    PathTracer *tracer;
    Menu *menu;

    FontManager *fontManager;
    ImageManager *imageManager;

    Application() : generator(nullptr), solver(nullptr), tracer(nullptr)
    {
    }

    ~Application()
    {
        clearMemory();
    }

    bool init();
    void clearMemory();

    void loadResources();

    void update();
    void pause();
    void resume();
    void render(sf::RenderWindow &window);
    void handleKeyRelease(const sf::Event &event);

    void createSolver();
    void createTracer();
    void createGenerator();

    void toggleMenu();
    void openMenu();
    void closeMenu();
};

#endif