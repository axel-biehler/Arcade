/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libNcurses
*/

#include "../../includes/IGraphic.hpp"
#include <ncurses.h>

#pragma once

namespace Arcade {
    class libNcurses : public IGraphic
    {
    private:
        WINDOW *_window;
    public:
        libNcurses();
        ~libNcurses();

        void drawPixel(Pixel *pixel) override;
        void drawText(Text *text) override;
        void myClear() override;
        void myRefresh() override;
        Arcade::CommandType getInput() override;
    };

}