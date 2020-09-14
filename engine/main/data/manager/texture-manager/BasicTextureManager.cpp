//
// Created by roman on 24.08.2020.
//

#include "BasicTextureManager.h"
#include "../../../general/exceptions/custom/TextureCanNotBeLoaded.h"

std::shared_ptr<sf::Texture>
Managers::BasicTextureManager::loadTexture(const std::string &filename, const sf::Rect<int> &area) const {
    std::shared_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(TEXTURES_DIRECTORY + "/" + filename, area))
        throw PreferredExceptions::TextureCanNotBeLoaded("Texture " + filename + " cannot be loaded.");

    return std::move(texture);
}

std::shared_ptr<sf::Image> Managers::BasicTextureManager::loadImage(const std::string &filename) const {
    std::shared_ptr<sf::Image> image(new sf::Image());
    if (!image->loadFromFile(TEXTURES_DIRECTORY + "/" + filename))
        throw PreferredExceptions::TextureCanNotBeLoaded("Image " + filename + " cannot be loaded.");

    return std::move(image);
}
