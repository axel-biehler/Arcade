/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP
#define B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP

#include <string>
#include <vector>
#include "../../includes/IGraphic.hpp"
#include "../../includes/IGame.hpp"
#include "../../includes/PersonnalType.hpp"
#include "../utils/LibLoader/LibLoader.hpp"
#include "../utils/Text/Text.hpp"
#include "../utils/Pixel/Pixel.hpp"

namespace Arcade {
    class Core {
    public:
        Core();
        ~Core();
        void setGraphicLib(IGraphic *lib);
        void setGameLib(IGame *lib);
        IGraphic *getGraphicLib() const;
        IGame *getGameLib() const;
        void switchLib(LibLoader &loader, CommandType event);
        void runGame(LibLoader &loader, std::string &playerName);
    private:
        IGraphic *_graphicLib;
        IGame *_gameLib;
        bool _isRunning;
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP
