#include "Component.hpp"
#include <iostream>

#pragma once

struct Button
{
    sf::Text label;
    sf::Color fill_color = sf::Color::White;
    sf::Color text_color = sf::Color::Black;
    sf::Color margin_color = sf::Color::Black;
    sf::Color highlight_color = sf::Color::Blue;

    float width;
    float height;
    float x;
    float y;
    float padding = 5;
    float margin = 2;
};

struct RectButton : public Button, Component
{
    sf::RectangleShape shape;

    RectButton(const std::string &text) : Component::Component()
    {
        label.setString(text);
        pack();
    }

    void init() override
    {
        shape.setFillColor(fill_color);
        shape.setOutlineThickness(margin);
        shape.setOutlineColor(margin_color);
        label.setOutlineColor(text_color);
        label.setOutlineThickness(2);
        label.setCharacterSize(50u);
    }

    void pack()
    {
        width = label.getLocalBounds().width + padding * 2 + margin * 2;
        height = label.getLocalBounds().height + padding * 2 + margin * 2;
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        label.setPosition(sf::Vector2f(x + padding, y + padding));
    }

    void render(sf::RenderWindow &window) override
    {
        window.draw(shape);
        window.draw(label);
    }

    void handleEvent(const sf::Event &event) override
    {
        std::cout << name << " was clicked\n";
    }
};