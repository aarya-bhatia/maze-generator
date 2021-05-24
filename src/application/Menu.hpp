#pragma once

#include "K.hpp"
#include "ResourceManager.hpp"
#include "Component.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>
#include <array>

//
// MENU SCREEN
//
class Menu : public Component
{
public:
    // IMPORTANT: Do not change the order of this enum
    enum ItemID
    {
        Play,
        Help,
        Settings,
        Quit,
        numItems
    };

    Menu(const ResourceManager *resources) : resources(resources),
                                             itemLabels(),
                                             menuItems(),
                                             selectedItem(0)
    {
        itemLabels[Play] = std::string("Play");
        itemLabels[Help] = std::string("Help");
        itemLabels[Quit] = std::string("Quit");
        itemLabels[Settings] = std::string("Settings");

        init();
    }

    void init() override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
    void update() override {}
    bool isSelected(ItemID option) const { return selectedItem == option; }

private:
    const ResourceManager *resources;
    std::array<std::string, numItems> itemLabels;
    std::array<sf::Text, numItems> menuItems;
    int selectedItem;

    float getYOff() const;
    float getXOff() const;
    float getYAbs(int i, int yOff) const;

    void up();
    void down();
    void select(int);
    void deselect(int);
};