//
// Created by roman on 25.11.2020.
//

#ifndef FLASH_COLLISIONREDUCTION_H
#define FLASH_COLLISIONREDUCTION_H

#include "../../mobs/common/base/Mob.h"
#include "../../common/algorithms/Algorithms.h"

namespace RD {

    /**
     * @brief The function contains the basic implementation of the collision analysis with blocks from the unifier.
     * @param mob Target object that is being processed.
     * @param algorithms Configured facade of necessary algorithms.
     * @param unifier Scene unifier.
     */
    template<class Type>
    void ordinateBlocksNaturalCollision(Type *object, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept {
        Obstacles::Block *block;
        if ((block = algorithms.getCollision().getMovingCollision().ordinateMoveAble(object, unifier->getBlocks())) != nullptr) {
            bool sameSign = object->getSpeed().ySpeed * block->getSpeed().ySpeed >= 0;
            float ySpeed = static_cast<int>(-1 * object->getSpeed().ySpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().ySpeed));
            object->setYSpeed((std::abs(ySpeed) == 1) ? 0 : ySpeed);
            if (object->getSpeed().xSpeed != block->getSpeed().xSpeed) {
                object->setXSpeed(static_cast<int>(object->getSpeed().xSpeed * block->getProperties().frictionCoefficient));
            }
        }
    }

    /**
     * @brief The function contains the basic implementation of the collision analysis with blocks from the unifier.
     * @param mob Target object that is being processed.
     * @param algorithms Configured facade of necessary algorithms.
     * @param unifier Scene unifier.
     */
    template<class Type>
    void abscissaBlocksNaturalCollision(Type *object, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept {
        Obstacles::Block *block;
        if ((block = algorithms.getCollision().getMovingCollision().abscissaMoveAble(object, unifier->getBlocks())) != nullptr) {
            bool sameSign = object->getSpeed().xSpeed * block->getSpeed().xSpeed >= 0;
            float xSpeed = static_cast<int>(-1 * object->getSpeed().xSpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().xSpeed));
            object->setXSpeed((std::abs(xSpeed) == 1) ? 0 : xSpeed);
            if (object->getSpeed().ySpeed != block->getSpeed().ySpeed) {
                object->setYSpeed(static_cast<int>(object->getSpeed().ySpeed * block->getProperties().frictionCoefficient));
            }
        }
    }
}
#endif //FLASH_COLLISIONREDUCTION_H
