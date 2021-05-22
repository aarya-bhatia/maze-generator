#include "Application.hpp"

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(K::screen_width, K::screen_height), K::title, sf::Style::Default, settings);

    assert(window != nullptr);
    window->setFramerateLimit(20);

    Application app;

    if (!app.init())
    {
        delete window;
        return -1;
    }

    while (window->isOpen() && app.state->isNot(State::quit) && app.state->isNot(State::loadError))
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
                app.handleKeyRelease(event);
                break;
            }
        }

        if (app.state->is(State::autoplay))
        {
            app.update();
        }

        window->clear(sf::Color::Black);

        window->draw(app.imageManager->background);

        app.render(*window);

        window->display();
    }

    delete window;

    std::cout << "EXITING PROGRAM" << std::endl;
    return 0;
}