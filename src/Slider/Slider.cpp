#include "Slider.hpp"

void Slider::init(int y = K::screen_height / 2)
{
    ready = true;
    container.setPosition(sf::Vector2f(K::slider_x_off, y));
    marker.setPosition(container.getPosition());
}

void Slider::update()
{
    float xPos = K::slider_x_off + pixels_per_unit * value;
    sf::Vector2f markerPos = marker.getPosition();
    if (markerPos.x != xPos)
    {
        markerPos.x = K::slider_x_off + pixels_per_unit * value;
        marker.setPosition(markerPos);
    }
}

void Slider::render(sf::RenderWindow &window)
{
    if (!ready)
    {
        std::cout << "Slider not initialised" << std::endl;
        return;
    }
    window.draw(container);
    window.draw(marker);
}

void Slider::slide(int dx)
{
    value += min + ((dx / K::screen_width) * (max - min));
    update();
}