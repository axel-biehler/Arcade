/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "../LibLoader/LibLoader.hpp"
#include "../../Core/Core.hpp"

bool handle_menu_event(int &select, bool &row, Arcade::CommandType command, int lenGraph, int lenGames)
{
    if (command == Arcade::NONE)
        return true;
    else if (command == Arcade::ESCAPE)
        return false;
    int selectLen = row ? lenGames : lenGraph;
    if (command == Arcade::KEYDOWN && select <= selectLen - 2) {
        select++;
    } else if (command == Arcade::KEYDOWN && select >= selectLen - 1) {
        select = 0;
    } else if (command == Arcade::KEYUP && select > 0) {
        select--;
    } else if (command == Arcade::KEYUP && select <= 0) {
        select = selectLen - 1;
    } else if (command == Arcade::ENTER && !row) {
        row = !row;
    } else if (command == Arcade::ENTER && row) {
        return false;
    }
    return true;
}

void display_menu(Arcade::Core core, Arcade::LibLoader loader)
{
    Arcade::Text titleGraph(25, 10, "Graphical libraries");
    Arcade::Text titleGame(75, 10, "Games");
    auto renderer = core.getGraphicLib();
    int i = 0;
    int select = 0;
    bool row = false;
    auto graphics = loader.getLibAvailable(Arcade::GRAPHIC);
    auto games = loader.getLibAvailable(Arcade::GAME);
    bool lastVal;
    std::pair<std::string, std::string> libraries;
    Arcade::Pixel myBox(25, 25, Arcade::RED, 40);

    while (handle_menu_event(select, row, renderer->getInput(), graphics.size(), games.size())) {
        graphics = loader.getLibAvailable(Arcade::GRAPHIC);
        games = loader.getLibAvailable(Arcade::GAME);
        renderer->myClear();
        renderer->drawPixel(&myBox);
        renderer->drawText(&titleGraph);
        renderer->drawText(&titleGame);
        if (lastVal != row && !lastVal)
            libraries.first = graphics[select].second;
        for (auto & graphic : graphics) {
            Arcade::Text text(25, 20 + (8 * i), graphic.first);
            if (i++ == select && !row)
                text.setColor(Arcade::BLUE);
            renderer->drawText(&text);
        }
        i = 0;
        for (auto & game : games) {
            Arcade::Text text(75, 20 + (8 * i), game.first);
            if (i++ == select && row)
                text.setColor(Arcade::BLUE);
            renderer->drawText(&text);
        }
        i = 0;
        renderer->myRefresh();
        lastVal = row;
    }
    //libraries.second = games[select].second;
}