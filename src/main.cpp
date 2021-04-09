/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include <iostream>
#include "utils/LibLoader/LibLoader.hpp"
#include "Core/Core.hpp"
#include "../includes/IMenu.hpp"

static void print_usage()
{
    std::cout << "Usage:\n\t./arcade [path to graphic lib]\n" << "Example:\n\t./arcade lib/arcade_ncurses.so\n";
}

static void menuLoop(Arcade::Core &core, Arcade::LibLoader loader, Arcade::IMenu *menu)
{
    bool running = true;
    Arcade::CommandType event;
    int choices = 0;

    menu->initLibAvailable(loader.getLibAvailable(Arcade::GAME), loader.getLibAvailable(Arcade::GRAPHIC));
    while (running && choices < 2) {
        event = core.getGraphicLib()->getInput();
        menu->getEvent(event, core.getGraphicLib());

        if (event == Arcade::ESC || event == Arcade::CLOSE_WINDOW)
            running = false;
        choices += event == Arcade::ENTER ? 1 : 0;
        core.switchLib(loader, event);
        menu->displayBackground(core.getGraphicLib());
        menu->displayText(core.getGraphicLib());
    }
}

int main(int ac, char **av)
{
    Arcade::Core core;
    Arcade::LibLoader loader;
    std::string name = "FlexyMax";

    if (ac < 2) {
        print_usage();
        return 84;
    }
    auto *graphicLib = loader.loadSharedLib<Arcade::IGraphic>(av[1], Arcade::GRAPHIC);
    auto *menu = loader.loadSharedLib<Arcade::IMenu>("lib/arcade_menu.so", Arcade::MENU);
    auto *game = loader.loadSharedLib<Arcade::IGame>("lib/arcade_nibbler.so", Arcade::GAME);
    if (!graphicLib || !menu) {
        std::cout << "Loading base library failed" << std::endl;
        return 84;
    }
    core.setGraphicLib(graphicLib);
    core.setGameLib(game);
    menuLoop(core, loader, menu);
    core.runGame(loader, name);
    std::_Exit(0);
}