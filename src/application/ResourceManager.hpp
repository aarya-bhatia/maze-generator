#pragma once

#include "FontManager.hpp"
#include "ImageManager.hpp"
#include <string>
#include <memory>

class ResourceManager
{
public:
    std::unique_ptr<ImageManager> images;
    std::unique_ptr<FontManager> fonts;

    explicit ResourceManager(const std::string &image_file,
                             const std::string &font_file)
    {
        images = std::make_unique<ImageManager>(image_file);
        fonts = std::make_unique<FontManager>(font_file);
    }

    bool load()
    {
        return images->load() && fonts->load();
    }
};