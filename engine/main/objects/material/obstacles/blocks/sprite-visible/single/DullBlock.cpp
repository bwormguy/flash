//
// Created by roman on 11.09.2020.
//

#include "DullBlock.h"

Obstacles::DullBlock::DullBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::DullBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier); //Add other "self" methods if you need.
}

void Obstacles::DullBlock::selfMove(Unite::Unifier *unifier) {
    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
}

void Obstacles::DullBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}