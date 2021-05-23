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

    ImageManager(const std::string &f) : file(f) {}

    bool load()
    {
        if (texture.loadFromFile(file))
        {
            background.setTexture(texture);
            return true;
        }
        return false;
    }
};