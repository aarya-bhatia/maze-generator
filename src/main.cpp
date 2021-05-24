#include "Logger.h"
#include "Window.hpp"
#include "Animation.hpp"
#include "Menu.hpp"

#include <SFML/Window/Event.hpp>

int main(int argc, const char *argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-log") == 0)
        {
            std::cout << "Logging to file...";
            Logger::logToFile();
        }
    }

    ResourceManager *resources = new ResourceManager(K::BACKGROUND_IMAGE_FILE, K::FONT_CAVIAR_DREAMS_BOLD);

    if (!resources->load())
    {
        std::cerr << "Failed to load fonts and images." << std::endl;
        exit(-1);
    }

    sf::RenderWindow *window = createWindow();

    Animation *app = new Animation;

    Menu *menu = new Menu(resources);

    while (!K::QUIT && window->isOpen())
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

        if (K::MENU)
        {
            menu->update();
        }
        else
        {
            if (K::AUTOPLAY && !K::PAUSE)
            {
                app->update();
            }
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