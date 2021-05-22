#include "ImageManager.hpp"
#include "K.hpp"
#include <iostream>

bool ImageManager::load()
{
    if (!texture.loadFromFile(file))
    {
        std::cout << "Could not load texture" << std::endl;
        return false;
    }
    else
    {
        if (K::DEBUG)
        {
            std::cout << "Texture was loaded" << std::endl;
        }
        loading = false;
        background.setTexture(texture);

        return true;
    }
}