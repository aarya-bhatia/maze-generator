#include "K.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>

#ifndef SLIDER_HPP
#define SLIDER_HPP

class Slider
{
private:
    sf::RectangleShape container = sf::RectangleShape();
    sf::CircleShape marker = sf::CircleShape();

    float pixels_per_unit;
    bool ready = false;

public:
    int value;
    int min;
    int max;

    Slider(int value, int min, int max) : value(value),
                                          min(min),
                                          max(max)
    {
        pixels_per_unit = K::slider_width / (max - min);

        container.setFillColor(sf::Color::White);
        container.setSize(sf::Vector2f(K::slider_width, K::slider_height));
        marker.setFillColor(sf::Color::Yellow);
        marker.setRadius(K::slider_radius);
    }

    void init(int y = K::screen_height / 2);
    void update();
    void render(sf::RenderWindow &window);
    void slide(int dx);
};

#endif