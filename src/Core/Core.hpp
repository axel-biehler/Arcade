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
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "PersonnalType.hpp"
#include "../LibLoader/LibLoader.hpp"

namespace Arcade {
    class Core {
    public:
        Core();
        ~Core();
        void setGraphicLib(IGraphic *lib);
        void setGameLib(IGame *lib);
        IGraphic *getGraphicLib() const;
        IGame *getGameLib() const;
    private:
        IGraphic *_graphicLib;
        IGame *_gameLib;
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP