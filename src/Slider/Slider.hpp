#include "Scrollable.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "K.hpp"

#ifndef SLIDER_HPP
#define SLIDER_HPP

class Slider : public Scrollable
{
private:
    sf::Vector2f container_position;
    sf::RectangleShape container;

    sf::CircleShape marker;
    sf::Vector2f marker_position;

    float slider_pixels_per_unit;
    float yoff = 0;

public:
    int value;
    int min;
    int max;

    Slider(int value, int min, int max) : value(value),
                                          min(min),
                                          max(max)
    {
    }

    void init(int y)
    {
        slider_pixels_per_unit = K::slider_width / (max - min);

        container_position = sf::Vector2f(K::slider_x_off, y);
        container = sf::RectangleShape();
        container.setFillColor(sf::Color::White);
        container.setPosition(container_position);
        container.setSize(sf::Vector2f(K::slider_width, K::slider_height));

        marker_position = sf::Vector2f(K::slider_x_off + slider_pixels_per_unit * value, y);
        marker = sf::CircleShape();
        marker.setFillColor(sf::Color::Yellow);
        marker.setPosition(marker_position);
        marker.setRadius(K::slider_radius);
    }

    void render(sf::RenderWindow &window)
    {
        window.draw(container);
        window.draw(marker);
    }

    void slide(int dx)
    {
        value += min + ((dx / K::screen_width) * (max - min));
        marker_position.x = K::slider_x_off + slider_pixels_per_unit * value;
        marker.setPosition(marker_position);
    }

    void scroll(int dy) override
    {
        yoff -= dy;

        container_position.y = yoff;
        marker_position.y = yoff;

        container.setPosition(container_position);
        marker.setPosition(marker_position);
    }
};

#endif