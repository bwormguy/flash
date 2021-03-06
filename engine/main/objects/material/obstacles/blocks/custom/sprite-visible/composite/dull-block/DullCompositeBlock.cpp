//
// Created by roman on 11.09.2020.
//

#include "DullCompositeBlock.h"

Obstacles::DullCompositeBlock::DullCompositeBlock(
        const Material::MaterialProperties &material_properties,
        const ObstacleProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISprite> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : CompositeSpriteBlock(material_properties, properties, area, sprite, algorithms) {}

void Obstacles::DullCompositeBlock::selfAction(Unite::Unifier *unifier) {
    //..
}
