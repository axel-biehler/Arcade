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

static std::string menuLoop(Arcade::Core &core, Arcade::LibLoader loader, Arcade::IMenu *menu)
{
    Arcade::CommandType event = Arcade::NO_EVENT;
    int choices = 0;
    clock_t start_t;
    clock_t end_t;
    double current_time = 0.0f;
    double dt = 0.0f;

    menu->initLibAvailable(loader.getLibAvailable(Arcade::GAME), loader.getLibAvailable(Arcade::GRAPHIC));
    while (event != Arcade::ESC && event != Arcade::CLOSE_WINDOW && choices < 2) {
        start_t = clock();
        event = core.getGraphicLib()->getInput();
        menu->getEvent(event, core.getGraphicLib());
        choices += event == Arcade::ENTER ? 1 : 0;
        core.switchLib(loader, event);
        if (dt >= double(1.0f / 25.0f)) {
            menu->displayBackground(core.getGraphicLib());
            menu->displayText(core.getGraphicLib(), core.getScores());
            dt -= double(1.0f / 25.0f);
        }
        end_t = clock();
        current_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        dt += current_time;
    }
    if (choices < 2)
        return "";
    std::string name = core.playerNameLoop(loader, menu);
    delete core.getGraphicLib();
    core.setGraphicLib(loader.loadSharedLib<Arcade::IGraphic>(menu->getLibGraph(), Arcade::GRAPHIC));
    core.setGameLib(loader.loadSharedLib<Arcade::IGame>(menu->getLibGame(), Arcade::GAME));
    return name;
}

int main(int ac, char **av)
{
    Arcade::Core core;
    Arcade::LibLoader loader;
    std::string name = "Player";

    if (ac < 2) {
        print_usage();
        return 84;
    }
    auto *graphicLib = loader.loadSharedLib<Arcade::IGraphic>(av[1], Arcade::GRAPHIC);
    auto *menu = loader.loadSharedLib<Arcade::IMenu>("lib/arcade_menu.so", Arcade::MENU);
    if (!graphicLib || !menu) {
        std::cout << "Loading base library failed" << std::endl;
        return 84;
    }
    core.setGraphicLib(graphicLib);
    name = menuLoop(core, loader, menu);
    if (core.getGameLib())
        core.runGame(loader, name);
    delete menu;
    core.deleteLibs();
    loader.unloadAll();
    std::_Exit(0);
}