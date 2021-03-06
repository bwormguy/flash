//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_AUDIOTRIGGER_H
#define FLASH_AUDIOTRIGGER_H

#include "../common/AreaTrigger.h"

namespace Triggers {

    class AudioTrigger : public AreaTrigger {
    public:
        AudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio) : AreaTrigger(area), m_audio(audio) {}

    protected:
        std::shared_ptr<sf::Music> m_audio;
    };
}

#endif //FLASH_AUDIOTRIGGER_H
