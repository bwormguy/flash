//
// Created by roman on 30.08.2020.
//

#include "CompositeSprite.h"

void Components::CompositeSprite::draw(sf::RenderTarget &target) const noexcept {
    for (const std::shared_ptr<ISprite> &sprite : m_sprites) {
        sprite->draw(target);
    }
}

void Components::CompositeSprite::move(float offsetX, float offsetY) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : m_sprites) {
        sprite->move(offsetX, offsetY);
    }
}

void Components::CompositeSprite::rotate(float angle) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : m_sprites) {
        sprite->rotate(angle);
    }
}

void Components::CompositeSprite::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::CompositeSprite::rotate(float angle, const Components::Point &point) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : m_sprites) {
        sprite->rotate(angle, point);
    }
}
