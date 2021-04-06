/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include <experimental/filesystem>
#include "libSFML.hpp"

extern "C" Arcade::IGraphic *getLib()
{
    return new Arcade::libSFML();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GRAPHIC;
}

static sf::Color translateColor(Arcade::Color color)
{
    switch (color) {
        case Arcade::Color::YELLOW:
            return sf::Color::Yellow;
        case Arcade::Color::RED:
            return sf::Color::Red;
        case Arcade::Color::BLUE:
            return sf::Color::Blue;
        case Arcade::Color::WHITE:
            return sf::Color::White;
        case Arcade::Color::BLACK:
            return sf::Color::Black;
        case Arcade::Color::CYAN:
            return sf::Color::Cyan;
        case Arcade::Color::GREEN:
            return sf::Color::Green;
        case Arcade::Color::MAGENTA:
            return sf::Color::Magenta;
        case Arcade::Color::TRANSPARENT:
            return sf::Color::Transparent;
    }
    return sf::Color::Black;
}

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
    sf::RectangleShape toDraw;
    sf::FloatRect textRect;
    float sizeX = (float)pixel->getSize() * (float)_window.getSize().x / 100;
    float sizeY = (float)pixel->getSize() * (float)_window.getSize().y / 100;

    toDraw.setSize(sf::Vector2f(sizeX, sizeY));
    textRect = toDraw.getLocalBounds();
    toDraw.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
    toDraw.setPosition(_window.getSize().x * (float)pixel->getXPos() / 100, _window.getSize().y * (float)pixel->getYPos() / 100);
    toDraw.setFillColor(translateColor(pixel->getColor()));
    _window.draw(toDraw);
}

void Arcade::libSFML::drawText(Arcade::Text *text)
{
    sf::Text toDraw;
    sf::Font font;
    sf::FloatRect textRect;

    font.loadFromFile("src/font/Gameplay.ttf");
    toDraw.setFont(font);
    toDraw.setCharacterSize(text->getSize() * 20);
    toDraw.setString(text->getStr());
    textRect = toDraw.getLocalBounds();
    toDraw.setOrigin(textRect.width / 2.0f,textRect.top  + textRect.height / 2.0f);
    toDraw.setPosition(_window.getSize().x * (float)text->getXPos() / 100, _window.getSize().y * (float)text->getYPos() / 100);
    toDraw.setFillColor(translateColor(text->getColor()));
    _window.draw(toDraw);
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
    event.type = sf::Event::MouseLeft;

    _window.pollEvent((sf::Event &)event);
    if (event.type == sf::Event::Closed) {
        return Arcade::CLOSE_WINDOW;
    }
    if (event.type == sf::Event::KeyReleased) {
        auto it = SFML_key.find(event.key.code);
        return it == SFML_key.end() ? Arcade::NO_EVENT : it->second;
    } else {
        return Arcade::NO_EVENT;
    }
}
