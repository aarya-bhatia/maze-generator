#include "Logger.h"
#include "Animation.hpp"
#include "Menu.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

sf::RenderWindow *createWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(K::screen_width, K::screen_height), K::title, sf::Style::Default, settings);
    window->setFramerateLimit(20);
    return window;
}

int main()
{
    // Logger::logToFile();

    ResourceManager *resources = new ResourceManager(K::BACKGROUND_IMAGE_FILE, K::FONT_CAVIAR_DREAMS_BOLD);

    sf::RenderWindow *window = createWindow();
    assert(window != nullptr);

    Animation *app = new Animation;
    app->init();

    Menu *menu = new Menu(resources);

    if (resources->load())
    {
        std::cout << "Fonts and images loaded successfully" << std::endl;
    }

    else
    {
        std::cout << "Failed to load fonts and images." << std::endl;
    }

    bool error = resources->fonts == nullptr || resources->images == nullptr;

    while (!error && window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                break;
            }
            if (K::MENU)
            {
                menu->handleEvent(event);
            }
            else
            {
                app->handleEvent(event);
            }
        }

        if (!K::MENU && K::AUTOPLAY)
        {
            app->update();
        }
        else
        {
            menu->update();
        }

        window->clear(sf::Color::Black);

        if (resources->images != nullptr)
        {
            window->draw(resources->images->background);
        }

        if (K::MENU)
        {
            menu->render(*window);
        }
        else
        {
            app->render(*window);
        }

        window->display();
    }

    delete menu;
    delete resources;
    delete app;
    delete window;

    std::cout << "EXITING PROGRAM" << std::endl;
    return 0;
}