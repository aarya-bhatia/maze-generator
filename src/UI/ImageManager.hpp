#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

#ifndef IMAGE_MANAGER_HPP
#define IMAGE_MANAGER_HPP

class ImageManager
{
public:
    sf::Texture texture;
    sf::Sprite background;
    std::string file;

    bool loading;

    ImageManager(const std::string &f) : file(f), loading(true) {}

    bool load();
};

#endif