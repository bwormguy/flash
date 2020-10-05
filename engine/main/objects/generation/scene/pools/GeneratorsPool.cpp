//
// Created by roman on 29.09.2020.
//

#include "GeneratorsPool.h"
#include "../analyze/GeneratorSelect.h"

Generate::Pools::GeneratorsPool::GeneratorsPool(SourcePool &pool, Screen::StateChangeable *context)
        : m_sourcePool(pool), m_context(context) {}

std::shared_ptr<Generate::Generator> Generate::Pools::GeneratorsPool::load(const std::string &alias) {
    if (m_generators[alias].get() == nullptr) {
        m_generators[alias] = std::shared_ptr<Generator>(Generate::selectGenerator(alias, m_sourcePool, m_context));
    }

    return m_generators[alias];
}
