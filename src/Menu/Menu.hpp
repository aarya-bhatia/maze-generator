#include "K.hpp"
#include <iostream>
#include "ImageManager.hpp"
#include "FontManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    float getYOff() const;
    float getXOff() const;
    float getYAbs(int i, int yOff) const;

public:
    std::string *itemLabels;
    sf::Text *menuItems;
    int selectedItem;

    ImageManager imageManager;
    FontManager fontManager;

    /* Warning: Do not change the order of this enum */
    enum ItemID
    {
        Play,
        Help,
        Settings,
        Quit,
        numItems
    };

    Menu(const ImageManager &_imageManager, const FontManager &_fontManager) : selectedItem(0), imageManager(_imageManager), fontManager(_fontManager)
    {
        itemLabels = new std::string[numItems];
        itemLabels[Play] = std::string("Play");
        itemLabels[Help] = std::string("Help");
        itemLabels[Quit] = std::string("Quit");
        itemLabels[Settings] = std::string("Settings");

        init();
    }

    ~Menu()
    {
        delete[] itemLabels;
        delete[] menuItems;
    }

    void init();
    void update();
    void draw(sf::RenderWindow &window);

    void up();
    void down();
    void select(int);

    bool is(ItemID option) const
    {
        return selectedItem == option;
    }
};

#endif