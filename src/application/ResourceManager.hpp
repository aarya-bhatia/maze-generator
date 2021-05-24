#pragma once

#include "FontManager.hpp"
#include "ImageManager.hpp"
#include <string>

struct ResourceManager
{
    ImageManager *images;
    FontManager *fonts;

    explicit ResourceManager(const std::string &image_file,
                             const std::string &font_file)
    {
        images = new ImageManager(image_file);
        fonts = new FontManager(font_file);
    }

    ~ResourceManager()
    {
        delete fonts;
        delete images;
    }

    bool load()
    {
        return images->load() && fonts->load();
    }
};