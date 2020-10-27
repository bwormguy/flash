//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_BASEMOB_H
#define FLASH_BASEMOB_H

#include "Mob.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Mobs {

    class BaseMob : public Mob {
    public:
        explicit BaseMob(const Mobs::MobProperties &properties, const Components::Area &area,
                         const std::shared_ptr<Components::ISpriteBox> &sprite, const std::shared_ptr<::Material::Algorithms> &algorithms)
                : Mob(properties, area, sprite), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<::Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_BASEMOB_H