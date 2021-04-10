/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Library loader header
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IMENU_HPP
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IMENU_HPP

#include <vector>
#include "../src/utils/Text/Text.hpp"
#include "../src/utils/Pixel/Pixel.hpp"
#include "IGraphic.hpp"

namespace Arcade {
    class IMenu {
    public:
        virtual void initLibAvailable(std::vector<std::pair<std::string, std::string>> libGame, std::vector<std::pair<std::string, std::string>> libGraph) = 0;
        virtual void displayText(IGraphic *lib, std::vector<std::vector<std::string>> scores) = 0;
        virtual void getEvent(Arcade::CommandType event, Arcade::IGraphic *lib) = 0;
        virtual std::string getLibGraph() const = 0;
        virtual std::string getLibGame() const = 0;
        virtual void setPlayerName(const std::string &name) = 0;
        virtual std::string getPlayerName() const = 0;
        virtual void initBackground(IGraphic *libGraph) = 0;
        virtual void displayBackground(IGraphic *libGraph) = 0;
        virtual void displayPlayerName(IGraphic *libGraph) = 0;
        virtual ~IMenu() {};
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IMENU_HPP

