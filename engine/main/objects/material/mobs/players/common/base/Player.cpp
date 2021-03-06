//
// Created by roman on 08.09.2020.
//

#include "Player.h"

Mobs::Player::Player(
        const Material::MaterialProperties &material_properties,
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite
) : Mobs::Mob(material_properties, properties, area, sprite) {}

void Mobs::Player::loadKeyMap(const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &keyMap) noexcept {
    m_keyMap = keyMap;
}

const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &Mobs::Player::getKeyMap() const noexcept {
    return m_keyMap;
}

void Mobs::Player::handleEventsList(Unite::Unifier *unifier) {
    for (const sf::Event &event : m_events) {
        this->handleEvent(event, unifier);
    }
    m_events.clear();
}

void Mobs::Player::update(const sf::Event &event, View::Window &sender) {
    m_events.push_back(event);
}
