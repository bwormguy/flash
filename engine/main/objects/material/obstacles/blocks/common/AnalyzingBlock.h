//
// Created by roman on 08.11.2020.
//

#ifndef FLASH_ANALYZINGBLOCK_H
#define FLASH_ANALYZINGBLOCK_H

#include "Block.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Obstacles {

    class AnalyzingBlock : public Block {
    public:
        AnalyzingBlock(
                const Material::MaterialProperties &material_properties,
                const ObstacleProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Material::Algorithms> &algorithms
        ) : Block(material_properties, properties, area), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_ANALYZINGBLOCK_H
