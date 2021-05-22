#include <iostream>
#include <SFML/Graphics/Font.hpp>

#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

class FontManager
{
public:
    sf::Font font;
    std::string file;
    bool loading;

    FontManager(const std::string &f) : file(f), loading(true)
    {
    }

    bool load();
};

#endif