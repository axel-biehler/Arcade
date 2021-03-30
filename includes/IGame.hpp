/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H

namespace Arcade {
    class IGame {
    public:
        virtual void draw() = 0;
        virtual void getEvent() = 0;
        virtual void update(double timeElapsed) = 0;
        virtual void remake() = 0;
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGAME_H
