/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libNcurses
*/

#include <ncurses.h>
#include <map>
#include "../../includes/IGraphic.hpp"

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

    std::map<int, CommandType> NCURSES_key {
        {'a', A},
        {'b', B},
        {'c', C},
        {'d', D},
        {'e', E},
        {'f', F},
        {'g', G},
        {'h', H},
        {'i', I},
        {'j', J},
        {'k', K},
        {'l', L},
        {'m', M},
        {'n', N},
        {'o', O},
        {'p', P},
        {'q', Q},
        {'r', R},
        {'s', S},
        {'t', T},
        {'u', U},
        {'v', V},
        {'w', W},
        {'x', X},
        {'y', Y},
        {'z', Z},
        {0, NUM0},
        {1, NUM1},
        {2, NUM2},
        {3, NUM3},
        {4, NUM4},
        {5, NUM5},
        {6, NUM6},
        {7, NUM7},
        {8, NUM8},
        {9, NUM9},
        {260, LEFT},
        {261, RIGHT},
        {259, UP},
        {258, DOWN},
        {10, ENTER},
        {' ', SPACE},
        {0407, BACKSPACE},
        {27, ESC},
        {265, F1},
        {266, F2},
        {267, F3},
        {268, F4},
        {269, F5},
        {270, F6}
    };
}