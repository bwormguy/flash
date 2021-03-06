//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COLLISION_H
#define FLASH_COLLISION_H

#include "moving-collision/MovingCollision.h"
#include "static-collision/StaticCollision.h"

namespace Material {

    /**
     * @brief The facade Collision class. This classes contains collision algorithms.
     * @namespace Material
     *
     * This class defines Collision realization.
    */
    class Collision final {
    public:
        Collision(float analysisStepX, float analysisStepY);

        const Material::MovingCollision &getMovingCollision() const noexcept;

        const Material::StaticCollision &getStaticCollision() const noexcept;

        ~Collision() = default;

    private:
        const Material::MovingCollision m_movingCollision;
        const Material::StaticCollision m_staticCollision;
    };
}

#endif //FLASH_COLLISION_H
