#include "Animation.hpp"
#include "ImageManager.hpp"
#include "FontManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;

    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(K::screen_width, K::screen_height), K::title, sf::Style::Default, settings);

    assert(window != nullptr);
    window->setFramerateLimit(20);

    Animation *app = new Animation;
    app->init();

    ImageManager *images = new ImageManager(K::BACKGROUND_IMAGE_FILE);
    FontManager *fonts = new FontManager(K::FONT_CAVIAR_DREAMS_BOLD);

    if (fonts->load())
    {
        std::cout << "Fonts loaded successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to load fonts" << std::endl;
    }

    if (images->load())
    {
        std::cout << "Images loaded successfuly" << std::endl;
    }
    else
    {
        std::cout << "Failed to load images" << std::endl;
    }

    bool error = fonts == nullptr || images == nullptr;

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
            if (event.type == sf::Event::KeyReleased)
            {
                app->handleEvent(event);
                break;
            }
        }

        if (K::AUTOPLAY)
        {
            app->update();
        }

        window->clear(sf::Color::Black);

        if (images != nullptr)
        {
            window->draw(images->background);
        }

        app->render(*window);

        window->display();
    }

    if (app != nullptr)
    {
        delete app;
    }
    if (fonts != nullptr)
    {
        delete fonts;
    }
    if (images != nullptr)
    {
        delete images;
    }
    if (window != nullptr)
    {
        delete window;
    }
    std::cout << "EXITING PROGRAM" << std::endl;
    return 0;
}