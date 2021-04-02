/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include <iostream>
#include "utils/LibLoader/LibLoader.hpp"
#include "Core/Core.hpp"
#include "utils/Menu/menu.hpp"

static void print_usage()
{
    std::cout << "Usage:\n\t./arcade [path to graphic lib]\n" << "Example:\n\t./arcade lib/arcade_ncurses.so\n";
}

int main(int ac, char **av)
{
    if (ac < 2) {
        print_usage();
        return 84;
    }
    Arcade::Core core;
    Arcade::LibLoader loader;
    auto *graphicLib = loader.loadSharedLib<Arcade::IGraphic>(av[1]);
    if (!graphicLib) {
        std::cout << "Loading base library failed" << std::endl;
        return 84;
    }
    core.setGraphicLib(graphicLib);
    display_menu(core, loader);
}