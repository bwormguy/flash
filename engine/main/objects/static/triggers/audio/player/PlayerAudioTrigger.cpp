//
// Created by roman on 15.10.2020.
//

#include "PlayerAudioTrigger.h"

Triggers::PlayerAudioTrigger::PlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::PlayerAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    if (m_audio->getStatus() == sf::SoundSource::Playing) return ResultCodes::OK;

    for (Mobs::Player *player: unifier->getPlayers()) {

        if (Material::OptimizedCollision<Possibilities::MaterialRectangle, Mobs::Player>(*this, *player)) {
            m_audio->setPlayingOffset(sf::Time());
            m_audio->play();
            break;
        }
    }
    return ResultCodes::OK;
}
