//
// Created by roman on 27.09.2020.
//

#include "TextureManager.h"
#include "../../../support/exceptions/custom/TextureCannotBeLoaded.h"

std::shared_ptr<sf::Texture>
Managers::TextureManager::loadTexture(const std::string &filename, const sf::Rect<int> &area) const {
    std::shared_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(TEXTURES_DIRECTORY + "/" + filename, area))
        throw Exceptions::TextureCannotBeLoaded("Texture " + filename + " cannot be loaded.");

    return texture;
}

std::shared_ptr<sf::Image> Managers::TextureManager::loadImage(const std::string &filename) const {
    std::shared_ptr<sf::Image> image(new sf::Image());
    if (!image->loadFromFile(TEXTURES_DIRECTORY + "/" + filename))
        throw Exceptions::TextureCannotBeLoaded("Image " + filename + " cannot be loaded.");

    return image;
}