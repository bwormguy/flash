//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_TEXTUREMANAGER_H
#define FLASH_TEXTUREMANAGER_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Managers {

    /**
     * @brief The base class of the TextureManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base TextureManager interface.
     */
    class TextureManager {
    public:
        explicit TextureManager(const std::string &textureDirectory)
                : _textureDirectory(textureDirectory) {}

        explicit TextureManager(const char *textureDirectory)
                : _textureDirectory(textureDirectory) {}

        /**
         * @brief Method loads texture from Texture directory.
         * @param filename Texture file name in Texture directory.
         * @return std::shared_ptr<sf::Texture>
         */
        virtual std::shared_ptr<sf::Texture> load(const std::string &filename) const = 0;

        virtual ~TextureManager() = default;

    protected:
        const std::string _textureDirectory;
    };
}

#endif //FLASH_TEXTUREMANAGER_H
