//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_STONEWALLSPRITEFACTORY_H
#define FLASH_STONEWALLSPRITEFACTORY_H

#include "SpriteFactory.h"

namespace Components {

    namespace Factory {

        class StoneWallSpriteFactory : public SpriteFactory {
        public:
            std::shared_ptr<Components::ISprite>
            createSprite(const Point &point, const Size &size, Managers::DataManager *dataManager) const override;
        };
    }
}
#endif //FLASH_STONEWALLSPRITEFACTORY_H