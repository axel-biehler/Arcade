/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "../utils/LibLoader/LibLoader.hpp"
#include "../Core/Core.hpp"
#include "Menu.hpp"

extern "C" Arcade::IMenu *getLib()
{
    return new Arcade::Menu();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::MENU;
}

Arcade::Menu::Menu(): _gameChoice(""), _graphChoice(""), _playerName(""), _cursor(0), _row(false)
{
}

Arcade::Menu::~Menu()
{
}

std::string Arcade::Menu::getLibGraph() const
{
    return _graphChoice;
}

std::string Arcade::Menu::getLibGame() const
{
    return _gameChoice;
}

void Arcade::Menu::setPlayerName(const std::string &name)
{
    _playerName = name;
}

std::string Arcade::Menu::getPlayerName() const
{
    return _playerName;
}

void Arcade::Menu::initLibAvailable(std::vector<std::pair<std::string, std::string>> libGame, std::vector<std::pair<std::string, std::string>> libGraph)
{
    _libGames = libGame;
    _libGraphics = libGraph;
}

void Arcade::Menu::displayText(IGraphic *lib, std::vector<std::vector<std::string>> scores)
{
    Arcade::Text libs(50, 5, "Libraries", Arcade::BLACK);
    Arcade::Text titleGraph(25, 12, "Graphics :", Arcade::BLACK);
    Arcade::Text titleGame(75, 12, "Games :", Arcade::BLACK);
    Arcade::Text highscores(50, 55, "Highscores", Arcade::BLACK);
    Arcade::Text titleNibbler(25, 62, "Nibbler :", Arcade::BLACK);
    Arcade::Text titlePacman(75, 62, "Pacman :", Arcade::BLACK);
    int i = 0;

    lib->drawText(&titleGraph);
    lib->drawText(&titleGame);
    lib->drawText(&libs);
    lib->drawText(&highscores);
    lib->drawText(&titleNibbler);
    lib->drawText(&titlePacman);
    for (auto & graphic : _libGraphics) {
        Arcade::Text text(25, 20 + (6 * i), graphic.first, Arcade::BLACK);
        if (i++ == _cursor && !_row)
            text.setColor(Arcade::WHITE);
        lib->drawText(&text);
    }
    i = 0;
    for (auto & game : _libGames) {
        Arcade::Text text(75, 20 + (6 * i), game.first, Arcade::BLACK);
        if (i++ == _cursor && _row)
            text.setColor(Arcade::WHITE);
        lib->drawText(&text);
    }
    i = 0;
    for (auto & nibblerIt : scores[0]) {
        Arcade::Text text(25, 70 + (6 * i++), nibblerIt, Arcade::BLACK);
        lib->drawText(&text);
    }
    i = 0;
    for (auto & pacmanIt : scores[1]) {
        Arcade::Text text(75, 70 + (6 * i++), pacmanIt, Arcade::BLACK);
        lib->drawText(&text);
    }
    lib->myRefresh();
}

void Arcade::Menu::getEvent(Arcade::CommandType event, Arcade::IGraphic *lib)
{
    int selectLen = _row ? _libGames.size() : _libGraphics.size();

    if (event == Arcade::DOWN && _cursor <= selectLen - 2) {
        _cursor++;
    } else if (event == Arcade::DOWN && _cursor >= selectLen - 1) {
        _cursor = 0;
    } else if (event == Arcade::UP && _cursor > 0) {
        _cursor--;
    } else if (event == Arcade::UP && _cursor <= 0) {
        _cursor = selectLen - 1;
    } else if (event == Arcade::ENTER && !_row) {
        _graphChoice = _libGraphics[_cursor].second;
        _cursor = 0;
        _row = !_row;
    } else if (event == Arcade::ENTER && _row) {
        _gameChoice = _libGames[_cursor].second;
        _row = false;
    }
    (void)lib;
}

void Arcade::Menu::initBackground(IGraphic *libGraph)
{
    (void)libGraph;
}

void Arcade::Menu::displayBackground(IGraphic *libGraph)
{
    Arcade::Pixel libsBox(50, 0, Arcade::GREEN, 100);
    Arcade::Pixel scoresBox(50, 100, Arcade::CYAN, 100);

    libGraph->myClear();
    libGraph->drawPixel(&libsBox);
    libGraph->drawPixel(&scoresBox);
}

void Arcade::Menu::displayPlayerName(Arcade::IGraphic *libGraph)
{
    Arcade::Text titleGraph(50, 20, "Enter player name", Arcade::BLACK);
    Arcade::Text titleGame(50, 30, "Finish with ENTER", Arcade::BLACK);
    Arcade::Text playerName(50, 50, _playerName, Arcade::BLACK);

    libGraph->drawText(&titleGraph);
    libGraph->drawText(&titleGame);
    libGraph->drawText(&playerName);
    libGraph->myRefresh();
}
