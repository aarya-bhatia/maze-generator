#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

class ImageManager
{
public:
    sf::Texture texture;
    sf::Sprite background;
    const std::string &file;

    ImageManager(const std::string &f) : file(f)
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
    }

    ~ImageManager()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }

    bool load()
    {
        if (texture.loadFromFile(file, sf::IntRect(0, 20, K::screen_width, K::screen_height)))
        {
            background.setTexture(texture);
            return true;
        }
        return false;
    }
};