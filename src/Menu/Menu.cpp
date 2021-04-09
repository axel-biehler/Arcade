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

Arcade::Menu::Menu(): _gameChoice(""), _graphChoice(""), _cursor(0), _row(false)
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

void Arcade::Menu::initLibAvailable(std::vector<std::pair<std::string, std::string>> libGame, std::vector<std::pair<std::string, std::string>> libGraph)
{
    _libGames = libGame;
    _libGraphics = libGraph;
}

void Arcade::Menu::displayText(IGraphic *lib)
{
    Arcade::Text titleGraph(25, 10, "Graphical libraries", Arcade::BLACK);
    Arcade::Text titleGame(75, 10, "Games", Arcade::BLACK);
    int i = 0;

    lib->drawText(&titleGraph);
    lib->drawText(&titleGame);
    for (auto & graphic : _libGraphics) {
        Arcade::Text text(25, 20 + (8 * i), graphic.first, Arcade::BLACK);
        if (i++ == _cursor && !_row)
            text.setColor(Arcade::WHITE);
        lib->drawText(&text);
    }
    i = 0;
    for (auto & game : _libGames) {
        Arcade::Text text(75, 20 + (8 * i), game.first, Arcade::BLACK);
        if (i++ == _cursor && _row)
            text.setColor(Arcade::WHITE);
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
    Arcade::Pixel myBox(50, 50, Arcade::GREEN, 100);
    Arcade::Pixel myRedBox(50, 50, Arcade::RED, 30);

    libGraph->myClear();
    libGraph->drawPixel(&myBox);
    libGraph->drawPixel(&myRedBox);
}
std::string Arcade::Menu::getPlayerName(Arcade::IGraphic *libGraph)
{
    (void)libGraph;
    return std::string();
}
