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
    sf::Vector2u winSize = _window.getSize();
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
    sf::Event event;

    _window.pollEvent((sf::Event &)event);
    if (event.type == sf::Event::Resized)
        return Arcade::RESIZE;
    if (event.type == sf::Event::Closed)
        return Arcade::ESCAPE;
    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::Space:
                return Arcade::SPACE;
            case sf::Keyboard::Up:
                return Arcade::KEYUP;
            case sf::Keyboard::Down:
                return Arcade::KEYDOWN;
            case sf::Keyboard::Escape:
                return Arcade::ESCAPE;
            case sf::Keyboard::Enter:
                return Arcade::ENTER;
            default:
                return Arcade::NONE;
        }
    } else {
        return Arcade::NONE;
    }
}