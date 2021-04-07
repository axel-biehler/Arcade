/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_MENU_HPP
#define B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_MENU_HPP

#include "../../includes/IMenu.hpp"

namespace Arcade {
    class Menu: public IMenu {
    public:
        Menu();
        ~Menu();
        void initLibAvailable(std::vector<std::pair<std::string, std::string>> libGame, std::vector<std::pair<std::string, std::string>> libGraph) override;
        void displayText(IGraphic *lib) override;
        void getEvent(Arcade::CommandType event, Arcade::IGraphic *lib) override;
        std::string getLib(std::vector<std::pair<std::string, std::string>> libGame) override;
        void initBackground(IGraphic *libGraph) override;
        void displayBackground(IGraphic *libGraph) override;
    private:
        std::vector<std::pair<std::string, std::string>> _libGames;
        std::vector<std::pair<std::string, std::string>> _libGraphics;
        int _cursor;
        bool _row;
    };
}

void display_menu(Arcade::Core core, Arcade::LibLoader loader);

#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_MENU_HPP