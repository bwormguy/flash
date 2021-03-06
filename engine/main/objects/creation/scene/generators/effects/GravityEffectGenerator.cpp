//
// Created by roman on 30.09.2020.
//

#include "GravityEffectGenerator.h"
#include "../../../../static/effects/gravity/GravityEffect.h"

Creation::GravityEffectGenerator::GravityEffectGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::GravityEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addEffect(new Effects::GravityEffect(std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION"))));
}
