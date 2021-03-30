/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "libSFML.hpp"

Arcade::libSFML::libSFML()
{
    _window.create(sf::VideoMode(800, 600), "Arcade");
    _window.setFramerateLimit(40);
    _window.setKeyRepeatEnabled(true);
}

Arcade::libSFML::~libSFML()
{
    _window.close();
}

void Arcade::libSFML::drawPixel(Arcade::Pixel *pixel)
{
}

void Arcade::libSFML::drawText(Arcade::Text *text)
{
}

void Arcade::libSFML::myClear()
{
    _window.clear(sf::Color(0, 0, 0, 255));
}

void Arcade::libSFML::myRefresh()
{
    _window.display();
}

Arcade::CommandType Arcade::libSFML::getInput()
{

    return Arcade::SPACE;
}

int Arcade::libSFML::convertToDisplay(int size, int max, Arcade::Round round)
{
    return 0;
}