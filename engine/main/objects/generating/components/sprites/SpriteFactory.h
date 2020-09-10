//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_SPRITEFACTORY_H
#define FLASH_SPRITEFACTORY_H

#include "../../../auxiliary/components/sprite/common/base/ISprite.h"
#include "../../../../data/manager/DataManager.h"

#include <memory>

namespace ComponentsGenerating {

    /**
     * @brief The base class of the SpriteFactory class hierarchy.
     * @namespace ComponentsGenerating
     *
     * This class is a sprite-factory interface.
    */
    class SpriteFactory {
    public:
        SpriteFactory() = default;

        /**
         * @brief Main factory function which creates new sprite.
         * @param point Sprite coordinates.
         * @param size Sprite size.
         * @param manager Manager which uses to get some data resources.
         * @return Sprite.
        */
        virtual std::shared_ptr<Components::ISprite>
        createSprite(const Components::Point &point, const Components::Size &size, Managers::DataManager *manager) const = 0;

        virtual ~SpriteFactory() = default;
    };
}
#endif //FLASH_SPRITEFACTORY_H