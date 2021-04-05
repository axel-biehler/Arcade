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

    toDraw.setSize(sf::Vector2f(pixel->getSize(), pixel->getSize()));
    textRect = toDraw.getLocalBounds();
    toDraw.setOrigin(textRect.left + textRect.width/2.0f,
                textRect.top  + textRect.height/2.0f);
    toDraw.setPosition(sf::VideoMode::getDesktopMode().width / (float)pixel->getXPos() * 100,
                sf::VideoMode::getDesktopMode().width / (float)pixel->getYPos() * 100);
    sf::Color color = sf::Color::Black;
    if (pixel->getColor() == Arcade::BLUE)
        color = sf::Color::Blue;
    else if (pixel->getColor() == Arcade::RED)
        color = sf::Color::Red;
    else if (pixel->getColor() == Arcade::WHITE)
        color = sf::Color::White;
    toDraw.setFillColor(color);
    _window.draw(toDraw);
}

void Arcade::libSFML::drawText(Arcade::Text *text)
{
    sf::Text toDraw = sf::Text();
    sf::Font font = sf::Font();
    sf::FloatRect textRect;

    font.loadFromFile("src/font/Gameplay.ttf");
    toDraw.setFont(font);
    toDraw.setCharacterSize(text->getSize() * 20);
    toDraw.setString(text->getStr());
    textRect = toDraw.getLocalBounds();
    toDraw.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
    toDraw.setPosition(sf::VideoMode::getDesktopMode().width / (float)text->getXPos() * 100,
                sf::VideoMode::getDesktopMode().width / (float)text->getYPos() * 100);
    sf::Color color = sf::Color::Black;
    if (text->getColor() == Arcade::BLUE)
        color = sf::Color::Blue;
    else if (text->getColor() == Arcade::RED)
        color = sf::Color::Red;
    else if (text->getColor() == Arcade::WHITE)
        color = sf::Color::White;
    toDraw.setFillColor(color);
    _window.draw(toDraw);
    _window.display();
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
    if (event.type == sf::Event::Resized)
        return Arcade::RESIZE;
    if (event.type == sf::Event::Closed) {
        return Arcade::ESCAPE;
    }
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
