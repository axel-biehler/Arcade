/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_PERSONNALTYPE_HPP
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_PERSONNALTYPE_HPP

namespace Arcade {
    enum CommandType {
        ESCAPE,
        KEYDOWN,
        KEYUP,
        SPACE,
        ENTER,
        RESIZE,
        NONE
    };

    enum LibType {
        GRAPHIC,
        GAME,
        MENU
    };

    enum Color {
        BLUE,
        RED,
        WHITE
    };

    enum MaxWindow {
        MYCOLS,
        MYLINES
    };

    enum Round {
        CEIL,
        TRUNC
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_PERSONNALTYPE_HPP
