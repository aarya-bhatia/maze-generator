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

    for (int i = 0; i < numItems; i++)
    {
        menuItems[i].setFont(resources->fonts->font);
        menuItems[i].setString(itemLabels[i]);
        menuItems[i].setCharacterSize(K::CHARACTER_SIZE);
        menuItems[i].setFillColor(K::col_text);
        menuItems[i].setPosition(sf::Vector2f(xOff, getYAbs(i, yOff)));
    }

    select(Play);
}

void Menu::render(sf::RenderWindow &window)
{
    for (int i = 0; i < numItems; i++)
    {
        window.draw(menuItems[i]);
    }
}

void Menu::deselect(int item)
{
    if (item >= 0 && item < menuItems.size())
    {
        menuItems[selectedItem].setFillColor(K::col_text);
    }
}

void Menu::select(int item)
{
    if (item >= 0 && item < menuItems.size())
    {
        menuItems[item].setFillColor(K::col_selected_text);
        selectedItem = item;
    }
}

void Menu::up()
{
    deselect(selectedItem);
    select((selectedItem + numItems - 1) % numItems);
}

void Menu::down()
{
    deselect(selectedItem);
    select((selectedItem + 1) % numItems);
}

void Menu::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            up();
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            down();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (K::DEBUG)
            {
                std::cout << "Selected Item: " << itemLabels[selectedItem] << std::endl;
            }
            if (isSelected(Play))
            {
                K::MENU = false;
            }
            else if (isSelected(Quit))
            {
                K::QUIT = true;
            }
        }
    }
}
