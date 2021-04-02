/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "../LibLoader/LibLoader.hpp"
#include "../../Core/Core.hpp"

void display_menu(Arcade::Core core, Arcade::LibLoader loader)
{
    auto graphics = loader.getLibAvailable(Arcade::GRAPHIC);
    auto games = loader.getLibAvailable(Arcade::GAME);
    auto renderer = core.getGraphicLib();
    Arcade::Text *text1 = new Arcade::Text(20, 20, graphics.data()->first);

    while (renderer->getInput() != Arcade::ESCAPE) {
        renderer->drawText(text1);
        renderer->myRefresh();
    }
}