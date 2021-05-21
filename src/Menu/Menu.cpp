#include "Menu.hpp"

float Menu::getYOff() const
{
    float n = static_cast<float>(numItems);
    float yOff = 1 - (n / (1 + n));
    return yOff * K::screen_height * 0.5;
}

float Menu::getXOff() const
{
    return K::screen_width / 2 - (K::CHARACTER_SIZE * 4) / 2;
}

float Menu::getYAbs(int i, int yOff) const
{
    return yOff + (K::screen_height / (1 + numItems)) * i;
}

void Menu::init()
{
    float yOff = getYOff();
    float xOff = getXOff();

    menuItems = new sf::Text[numItems];

    for (int i = 0; i < numItems; i++)
    {
        menuItems[i].setFont(fontManager.font);
        menuItems[i].setString(itemLabels[i]);
        menuItems[i].setCharacterSize(K::CHARACTER_SIZE);
        menuItems[i].setFillColor(K::col_text);
        menuItems[i].setPosition(sf::Vector2f(xOff, getYAbs(i, yOff)));
    }

    select(Play);
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < numItems; i++)
    {
        window.draw(menuItems[i]);
    }
}

void Menu::select(int item)
{
    assert(item >= 0 && item < numItems);
    menuItems[selectedItem].setFillColor(K::col_text);
    menuItems[item].setFillColor(K::col_selected_text);
    selectedItem = item;
}

void Menu::up()
{
    select((selectedItem + numItems - 1) % numItems);
}

void Menu::down()
{
    select((selectedItem + 1) % numItems);
}

void Menu::update()
{
}
