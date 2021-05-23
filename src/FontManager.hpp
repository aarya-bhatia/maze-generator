#pragma once

#include <SFML/Graphics/Font.hpp>

class FontManager
{
public:
    sf::Font font;
    const std::string &file;

    FontManager(const std::string &f) : file(f)
    {
    }

    bool load()
    {
        return font.loadFromFile(file);
    }
};