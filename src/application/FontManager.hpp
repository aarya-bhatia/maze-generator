#pragma once

#include <SFML/Graphics/Font.hpp>

class FontManager
{
public:
    sf::Font font;
    const std::string &file;

    FontManager(const std::string &f) : file(f)
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }

    ~FontManager()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }

    bool load()
    {
        return font.loadFromFile(file);
    }
};