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
        void displayText(IGraphic *lib, std::vector<std::vector<std::string>> scores) override;
        void getEvent(Arcade::CommandType event, Arcade::IGraphic *lib) override;
        std::string getLibGraph() const override;
        std::string getLibGame() const override;
        void setPlayerName(const std::string &name) override;
        std::string getPlayerName() const override;
        void initBackground(IGraphic *libGraph) override;
        void displayBackground(IGraphic *libGraph) override;
        void displayPlayerName(IGraphic *libGraph) override;
    private:
        std::vector<std::pair<std::string, std::string>> _libGames;
        std::vector<std::pair<std::string, std::string>> _libGraphics;
        std::string _gameChoice;
        std::string _graphChoice;
        std::string _playerName;
        int _cursor;
        bool _row;
    };
}

void display_menu(Arcade::Core core, Arcade::LibLoader loader);

#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_MENU_HPP