/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGRAPHIC_H
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGRAPHIC_H

#include <iostream>
#include "PersonnalType.hpp"
#include "../src/utils/Text/Text.hpp"
#include "../src/utils/Pixel/Pixel.hpp"

namespace Arcade {
    class IGraphic {
    public:
        virtual void drawPixel(Pixel *pixel) = 0;
        virtual void drawText(Text *text) = 0;
        virtual void myClear() = 0;
        virtual void myRefresh() = 0;
        virtual Arcade::CommandType getInput() = 0;
        virtual int convertToDisplay(int size, int max, Round round) = 0;
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_IGRAPHIC_H
