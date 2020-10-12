//
// Created by roman on 30.08.2020.
//

#include "SpriteBox.h"
#include "../../../../../../utils/math/RectangleMath.h"

Components::SpriteBox::SpriteBox(const Components::Area &area, const std::shared_ptr<sf::Texture> &texture)
        : ISpriteBox(texture, new sf::Sprite()), m_area(area) {

    m_sprite->setTexture(*texture.get(), true);
    m_sprite->setPosition(m_area.m_point.x, m_area.m_point.y);
    m_sprite->setScale(static_cast<float>(m_area.m_size.width) / m_texture->getSize().x,
                       static_cast<float>(m_area.m_size.height) / m_texture->getSize().y);
    m_sprite->rotate(m_area.m_angle);
}

void Components::SpriteBox::draw(sf::RenderTarget &target) const noexcept {
    target.draw(*m_sprite.get(), sf::RenderStates::Default);
}

void Components::SpriteBox::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Components::SpriteBox::rotate(float angle) noexcept {
    m_area.rotate(angle);
    m_sprite->rotate(angle);
}

void Components::SpriteBox::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::SpriteBox::rotate(float angle, const Components::Point &point) noexcept {
    this->setPosition(MathUtils::pointToPointRotation(this->getPosition(), angle, point));
    this->rotate(angle);
}

void Components::SpriteBox::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Components::SpriteBox::setPosition(float x, float y) noexcept {
    m_area.setPosition(x, y);
    m_sprite->setPosition(x, y);
}

void Components::SpriteBox::setSize(const Components::Size &size) noexcept {
    m_area.setSize(size);
    m_sprite->setScale(static_cast<float>(m_area.m_size.width) / m_texture->getSize().x,
                       static_cast<float>(m_area.m_size.height) / m_texture->getSize().y);
}

void Components::SpriteBox::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
    m_sprite->setRotation(angle);
}

float Components::SpriteBox::getRotation() const noexcept {
    return m_sprite->getRotation();
}

const Components::Point &Components::SpriteBox::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Components::SpriteBox::getSize() const noexcept {
    return m_area.m_size;
}
