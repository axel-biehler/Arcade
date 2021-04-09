/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "Core.hpp"
#include <time.h>

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

void Arcade::Core::runGame(LibLoader &loader, std::string &playerName)
{
    Arcade::CommandType event;
    Arcade::CommandType cmd = NO_EVENT;
    int choices = 0;
    clock_t start_t;
    clock_t end_t;
    double current_time = 0.0f;
    double dt = 0.0f;

    _gameLib->initPlayerName(playerName);
    _isRunning = true;
    while (_isRunning || cmd == Arcade::CommandType::ESC) {
        start_t = clock();
        _graphicLib->myClear();
        cmd = _gameLib->getEvent(cmd, _graphicLib);
        _gameLib->draw(_graphicLib);
        if (dt >= double(1.0f / 60.0f)) {
            _gameLib->update(current_time);
            dt = 0.0f;
        }
        _graphicLib->myRefresh();
        end_t = clock();
        current_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        dt += current_time;
    }
}