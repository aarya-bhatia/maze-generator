#include "Application.hpp"
#include "MazeSolver.hpp"
#include "PathTracer.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

bool Application::init()
{
    srand(time(0));

    state = State::create();
    assert(state != nullptr);

    fontManager = new FontManager(K::FONT_CAVIAR_DREAMS_BOLD);
    imageManager = new ImageManager(K::BACKGROUND_IMAGE_FILE);

    loadResources();

    if (state->is(State::loadError))
    {
        return false;
    }

    maze = Maze::create();
    assert(maze != nullptr);

    grid = new Grid(*maze);
    assert(grid != nullptr);

    menu = new Menu(*imageManager, *fontManager);
    assert(menu != nullptr);

    return true;
}

void Application::loadResources()
{
    if (!fontManager->load() || !imageManager->load())
    {
        state->on(State::loadError);
    }
    else if (K::DEBUG)
    {
        std::cout << "Font and textures were loaded" << std::endl;
    }
}

void Application::createGenerator()
{
    if (maze == nullptr)
    {
        std::cerr << "Cannot create generator because maze does not exist" << std::endl;
        exit(-1);
    }
    generator = new MazeGeneration(*maze);
}

void Application::createSolver()
{
    if (!generator->finished())
    {
        std::cerr << "Cannot create solver because generator is not finished" << std::endl;
        exit(-1);
    }
    solver = new MazeSolver(*maze, *grid);
}

void Application::createTracer()
{
    if (solver == nullptr || !solver->finished())
    {
        std::cerr << "Cannot create tracer because solver did not finish" << std::endl;
        exit(-1);
    }
    tracer = new PathTracer(*maze, *grid, solver->path);
}

void Application::update()
{
    if (state->is(State::showMenu))
    {
        menu->update();
    }

    if (state->is(State::paused))
    {
        return;
    }

    if (state->is(State::generating))
    {
        if (generator == nullptr)
        {
            createGenerator();
        }
        if (!generator->finished())
        {
            generator->next();
            generator->update(*grid);
        }
        else
        {
            if (K::DEBUG)
            {
                std::cout << "MAZE GENERATOR FINISHED" << std::endl;
                std::cout << "---------------------" << std::endl;
                generator->log();
                std::cout << "---------------------" << std::endl;
            }

            state->off(State::generating);
            assert(state->isNot(State::generating));

            if (K::SOLVER)
            {
                state->on(State::exploring);
            }
        }
    }
    else if (state->is(State::exploring))
    {
        if (solver == nullptr)
        {
            createSolver();
        }

        if (!solver->finished())
        {
            solver->next();
            solver->update(*grid);
        }
        else
        {
            if (K::DEBUG)
            {
                std::cout << "PATH FINDER FINISHED" << std::endl;
                std::cout << "---------------------" << std::endl;
                solver->log();
                std::cout << "---------------------" << std::endl;
            }

            state->off(State::exploring);

            if (K::TRACER)
            {
                state->on(State::tracing);
            }
        }
    }
    else if (state->is(State::tracing))
    {
        if (tracer == nullptr)
        {
            createTracer();
        }
        if (!tracer->finished())
        {
            tracer->update(*grid);
            tracer->next();
        }
        else
        {
            if (K::DEBUG)
            {

                std::cout << "PATH TRACER FINISHED" << std::endl;
                tracer->log();
                std::cout << "---------------------" << std::endl;
            }
            state->off(State::tracing);
        }
    }
}

void Application::pause()
{
    state->on(State::paused);

    if (K::DEBUG)
    {
        std::cout << "PAUSING APPLICATION" << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

void Application::toggleMenu()
{
    if (state->is(State::showMenu))
    {
        closeMenu();
    }
    else
    {
        openMenu();
    }
}

void Application::openMenu()
{
    pause();
    state->on(State::showMenu);

    if (K::DEBUG)
    {
        std::cout << "OPENING MENU" << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

void Application::closeMenu()
{
    state->off(State::showMenu);
    resume();

    if (K::DEBUG)
    {
        std::cout << "CLOSING MENU" << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

void Application::resume()
{
    state->off(State::paused);

    if (K::DEBUG)
    {
        std::cout << "RESUMING APPLICATION" << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

void Application::render(sf::RenderWindow &window)
{
    if (state->is(State::showMenu))
    {
        menu->draw(window);
        return;
    }

    for (int i = 0; i < grid->size(); i++)
    {
        window.draw(grid->cells[i]);
    }
}

/**
 * Controls:
 * N-> update app if autoplay is off
 * M-> open menu
 * Up,Down,Enter-> interact with menu
 * P-> toggle pause and resume
 */
void Application::handleKeyRelease(const sf::Event &event)
{
    if (event.key.code == sf::Keyboard::N)
    {
        if (!K::AUTOPLAY)
        {
            update();
        }
        else if (K::DEBUG)
        {
            std::cout << __FILE__ << ": " << __LINE__ << ": Autoplay is turned on." << std::endl;
        }
    }

    if (event.key.code == sf::Keyboard::P)
    {
        if (state->isNot(State::paused))
        {
            pause();
        }
        else
        {
            resume();
        }
    }

    if (state->isNot(State::showMenu) && event.key.code == sf::Keyboard::M)
    {
        openMenu();
    }

    if (state->is(State::showMenu))
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            menu->up();
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            menu->down();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (menu->is(Menu::Quit))
            {
                state->on(State::quit);
            }
            else if (menu->is(Menu::Play))
            {
                closeMenu();
            }
            else if (menu->is(Menu::Help))
            {
                state->on(State::help);
            }
        }
    }
}

void Application::clearMemory()
{
    delete imageManager;
    delete fontManager;
    delete menu;
    delete tracer;
    delete solver;
    delete generator;
    delete grid;
    delete maze;
    delete state;
}