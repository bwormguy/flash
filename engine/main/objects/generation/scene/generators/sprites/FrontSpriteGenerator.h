//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_FRONTSPRITEGENERATOR_H
#define FLASH_FRONTSPRITEGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class FrontSpriteGenerator : public Generator {
    public:
        FrontSpriteGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_FRONTSPRITEGENERATOR_H