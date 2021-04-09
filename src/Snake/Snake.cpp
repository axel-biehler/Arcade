/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Snake
*/

#include "Snake.hpp"

extern "C" Arcade::IGame *getLib()
{
    return new Arcade::Snake();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GAME;
}

Arcade::Snake::Snake()
{
}

Arcade::Snake::~Snake()
{
}

void Arcade::Snake::initPlayerName(std::string playerName)
{
    _playerName = playerName;
}

void Arcade::Snake::draw(IGraphic *lib)
{
    Arcade::Pixel myBox(50, 50, Arcade::GREEN, 100);
    Arcade::Pixel myRedBox(50, 50, Arcade::RED, 30);

    lib->myClear();
    lib->drawPixel(&myBox);
    lib->drawPixel(&myRedBox);
}

Arcade::CommandType Arcade::Snake::getEvent(CommandType cmd, IGraphic *lib)
{
    return NO_EVENT;
}

void Arcade::Snake::update(double timeElapsed)
{

}
