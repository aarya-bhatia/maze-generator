#include "FontManager.hpp"
#include <iostream>

bool FontManager::load()
{
    if (!font.loadFromFile(file))
    {
        std::cout << "Could not load font" << std::endl;
        return false;
    }
    else
    {
        loading = false;
        return true;
    }
}