//
// Created by roman on 12.10.2020.
//

#include "TextGenerator.h"
#include "../reduction/ElementaryReduction.h"

Creation::TextGenerator::TextGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

static sf::Text::Style style(const std::string &style) noexcept;

void Creation::TextGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    using namespace Components;
    Text *text = new Text(data.at("STRING"), m_source.getFont(data.at("FONT")));
    Point point = RD::position(data, "POSITION");
    text->getText().setPosition(point.x, point.y);
    text->getText().rotate(std::stof(data.at("ANGLE").c_str()));
    text->getText().setCharacterSize(std::atoi(data.at("CHARACTER_SIZE").c_str()));
    text->getText().setOutlineColor(RD::color(data, "OUTLINE_COLOR"));
    text->getText().setFillColor(RD::color(data, "FILL_COLOR"));
    text->getText().setLetterSpacing(std::stof(data.at("LETTER_SPACING").c_str()));
    text->getText().setLineSpacing(std::stof(data.at("LINE_SPACING").c_str()));
    text->getText().setOutlineThickness(std::stof(data.at("OUTLINE_THICKNESS").c_str()));
    text->getText().setStyle(style(data.at("STYLE")));
    unifier.addText(text);
}

static sf::Text::Style style(const std::string &style) noexcept {
    if (style == "Bold")
        return sf::Text::Style::Bold;
    if (style == "Italic")
        return sf::Text::Style::Italic;
    if (style == "Underlined")
        return sf::Text::Style::Underlined;
    if (style == "StrikeThrough")
        return sf::Text::Style::StrikeThrough;
    return sf::Text::Style::Regular;
}