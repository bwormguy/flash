//
// Created by roman on 02.10.2020.
//

#include "DirectivesAnalyzer.h"
#include "../generators/reduction/ElementaryReduction.h"

Creation::DirectivesAnalyzer::DirectivesAnalyzer(Creation::Pools::SourcePool &sourcePool) : m_sourcePool(sourcePool) {}

void Creation::DirectivesAnalyzer::analyze(const IniUtil::Analyzer::IniBlock &data, View::Window &window) {

    for (const auto &line : data) {
        if (line.first == "SET_TITLE") {
            window.getWindow().setTitle(line.second);
            continue;
        }
        if (line.first == "SET_RENDER_WIDTH") {
            window.getWindow().setSize(sf::Vector2<unsigned int>(std::atoi(line.second.c_str()), window.getWindow().getSize().y));
            continue;
        }
        if (line.first == "SET_RENDER_HEIGHT") {
            window.getWindow().setSize(sf::Vector2<unsigned int>(window.getWindow().getSize().x, std::atoi(line.second.c_str())));
            continue;
        }
        if (line.first == "SET_FPS") {
            window.setFramerateLimit(std::atoi(line.second.c_str()));
            continue;
        }
        if (line.first == "SET_BACK_COLOR") {
            window.setBackColor(RD::color(data, line.first));
            continue;
        }
        //..
        m_sourcePool.setVariable(line.first, line.second);
    }
}
