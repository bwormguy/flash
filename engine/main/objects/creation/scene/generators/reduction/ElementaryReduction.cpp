//
// Created by roman on 15.10.2020.
//

#include "ElementaryReduction.h"

Components::Point Creation::RD::position(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> position = Calculations::split(data.at(field), ':');
    return Components::Point(std::stof(position.at(0)), std::stof(position.at(1)));
}

Components::Size Creation::RD::size(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> size = Calculations::split(data.at(field), ':');
    return Components::Size(std::stoi(size.at(0)), std::stoi(size.at(1)));
}

Components::Speed Creation::RD::speed(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> speed = Calculations::split(data.at(field), ':');
    return Components::Speed(std::stof(speed.at(0)), std::stof(speed.at(1)));
}

sf::Color Creation::RD::color(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> color = Calculations::split(data.at(field), ':');
    sf::Uint8 r = std::atoi(color.at(0).c_str());
    sf::Uint8 g = std::atoi(color.at(1).c_str());
    sf::Uint8 b = std::atoi(color.at(2).c_str());
    sf::Uint8 alpha = std::atoi(color.at(3).c_str());
    return sf::Color(r, g, b, alpha);
}

std::pair<float, float> Creation::RD::fpair(const IniUtil::Analyzer::IniBlock &data, const std::string &field) {
    std::vector<std::string> values = Calculations::split(data.at(field), ':');
    return std::make_pair(std::stof(values.at(0)), std::stof(values.at(1)));
}
