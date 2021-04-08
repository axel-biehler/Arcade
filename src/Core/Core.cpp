/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "Core.hpp"

Arcade::Core::Core()
{
    _graphicLib = nullptr;
    _gameLib = nullptr;
}

Arcade::Core::~Core()
{
}

void Arcade::Core::setGraphicLib(Arcade::IGraphic *lib)
{
    _graphicLib = lib;
}

void Arcade::Core::setGameLib(Arcade::IGame *game_lib)
{
    _gameLib = game_lib;
}

Arcade::IGraphic *Arcade::Core::getGraphicLib() const
{
    return _graphicLib;
}

Arcade::IGame *Arcade::Core::getGameLib() const
{
    return _gameLib;
}

void Arcade::Core::switchLib(Arcade::LibLoader &loader, Arcade::CommandType event)
{
    Arcade::CommandType libEvent[] = {
        Arcade::NUM0,
        Arcade::NUM1,
        Arcade::NUM2,
        Arcade::NUM3
    };

    if (std::find(libEvent, libEvent + 4, event) == libEvent + 4)
        return;
    if (event == Arcade::CommandType::NUM0) {
        delete _graphicLib;
        this->setGraphicLib(loader.loadNextGraphics(true));
    } else if (event == Arcade::CommandType::NUM1) {
        delete _graphicLib;
        this->setGraphicLib(loader.loadNextGraphics(false));
    } else if (event == Arcade::CommandType::NUM2) {
        delete _gameLib;
        this->setGameLib(loader.loadNextGame(true));
    } else if (event == Arcade::CommandType::NUM3) {
        delete _gameLib;
        this->setGameLib(loader.loadNextGame(false));
    }
}