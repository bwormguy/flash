//
// Created by roman on 08.10.2020.
//

#include "GravityPointEffect.h"

Effects::GravityPointEffect::GravityPointEffect(const Components::Point &point, float acceleration)
        : m_point(point), ACCELERATION(acceleration) {}

void Effects::GravityPointEffect::applyEffect(Unite::Unifier *unifier) {

    for (const std::shared_ptr<Mobs::Mob> &mob : unifier->getMobs()) {

        float mobX = mob->getPosition().x + mob->getSize().width;
        if (mobX > m_point.x) {
            mob->addSpeed(-ACCELERATION, 0);
        } else if (mobX < m_point.x) {
            mob->addSpeed(ACCELERATION, 0);
        }

        float mobY = mob->getPosition().y + mob->getSize().height;
        if (mobY > m_point.y) {
            mob->addSpeed(0, -ACCELERATION);
        } else if (mobY < m_point.y) {
            mob->addSpeed(0, ACCELERATION);
        }
    }

    for (Obstacles::Block *block : unifier->getBlocks()) {
        if (!block->getProperties().isFixed) {

            float obstacleX = block->getPosition().x + block->getSize().width;
            if (obstacleX > m_point.x) {
                block->addSpeed(-ACCELERATION, 0);
            } else if (obstacleX < m_point.x) {
                block->addSpeed(ACCELERATION, 0);
            }

            float obstacleY = block->getPosition().y + block->getSize().height;
            if (obstacleY > m_point.y) {
                block->addSpeed(0, -ACCELERATION);
            } else if (obstacleY < m_point.y) {
                block->addSpeed(0, ACCELERATION);
            }
        }
    }
}

void Effects::GravityPointEffect::move(float offsetX, float offsetY) noexcept {
    m_point.x += offsetX;
    m_point.y += offsetY;
}

const Components::Point &Effects::GravityPointEffect::getPoint() const {
    return m_point;
}

void Effects::GravityPointEffect::setPoint(const Components::Point &point) noexcept {
    m_point = point;
}

void Effects::GravityPointEffect::setPoint(float x, float y) noexcept {
    m_point.x = x;
    m_point.y = y;
}

