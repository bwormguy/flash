//
// Created by roman on 15.10.2020.
//

#include "ElementaryReduction.h"

Components::Point Creation::position(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> position = Computations::split(data.at(field), ':');
    return Components::Point(std::stof(position.at(0)), std::stof(position.at(1)));
}

Components::Size Creation::size(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> size = Computations::split(data.at(field), ':');
    return Components::Size(std::stof(size.at(0)), std::stof(size.at(1)));
}

Components::Speed Creation::speed(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> speed = Computations::split(data.at(field), ':');
    return Components::Speed(std::stof(speed.at(0)), std::stof(speed.at(1)));
}

sf::Color Creation::color(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> color = Computations::split(data.at(field), ':');
    sf::Uint8 r = std::atoi(color.at(0).c_str());
    sf::Uint8 g = std::atoi(color.at(1).c_str());
    sf::Uint8 b = std::atoi(color.at(2).c_str());
    sf::Uint8 alpha = std::atoi(color.at(3).c_str());
    return sf::Color(r, g, b, alpha);
}