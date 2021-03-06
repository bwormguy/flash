//
// Created by roman on 17.10.2020.
//

#include "BackAudioEffectGenerator.h"
#include "../../../../static/effects/audio/back/BackAudioEffect.h"
#include "../reduction/CustomReduction.h"

Creation::BackAudioEffectGenerator::BackAudioEffectGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::BackAudioEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addEffect(new Effects::BackAudioEffect(RD::loadMusic(data, m_source)));
}
