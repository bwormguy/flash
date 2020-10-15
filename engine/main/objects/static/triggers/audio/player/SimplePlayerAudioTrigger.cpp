//
// Created by roman on 15.10.2020.
//

#include "SimplePlayerAudioTrigger.h"

Triggers::SimplePlayerAudioTrigger::SimplePlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::SimplePlayerAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {

    for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {

        if (MathUtils::collision(*this, *player)) {
            if (m_audio->getStatus() != sf::SoundSource::Playing) {
                m_audio->setPlayingOffset(sf::Time());
                m_audio->play();
            }
        }
    }
    return ResultCodes::OK;
}
