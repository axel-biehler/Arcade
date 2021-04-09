/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H

#include "IGraphic.hpp"

namespace Arcade {
    class IGame {
    public:
        virtual void initPlayerName(std::string playerName) = 0;
        virtual void draw(IGraphic *lib) = 0;
        virtual CommandType getEvent(CommandType cmd, IGraphic *lib) = 0; 
        virtual void update(double timeElapsed) = 0;
        virtual ~IGame() {};
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H
