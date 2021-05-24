#include "Window.hpp"

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>

sf::RenderWindow *createWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;

    sf::RenderWindow *window = new sf::RenderWindow(
        sf::VideoMode(K::screen_width, K::screen_height),
        K::title,
        sf::Style::Default,
        settings);

    window->setFramerateLimit(20);

    return window;
}