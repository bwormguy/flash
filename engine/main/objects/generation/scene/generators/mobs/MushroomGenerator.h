//
// Created by roman on 01.10.2020.
//

#ifndef FLASH_MUSHROOMGENERATOR_H
#define FLASH_MUSHROOMGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class MushroomGenerator : public Generator {
    public:
        MushroomGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_MUSHROOMGENERATOR_H
