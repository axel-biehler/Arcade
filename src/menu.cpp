/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include <iostream>
#include <vector>
#include "LibLoader/LibLoader.hpp"
#include "utils/Text/Text.hpp"

static std::vector<std::string> get_graphic()
{

}

static std::vector<Arcade::Text *> get_games();

void render_menu(Arcade::IGraphic *renderer)
{
    std::vector<std::string> graphicEntries = get_graphic();
 //   std::vector<Arcade::Text *> gamesEntries = get_games();

 //   renderer->initWindow("Arcade");
}