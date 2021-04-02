/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libNcurses
*/

#include <cstring>
#include <iostream>
#include "libNcurses.hpp"
#include "PersonnalType.hpp"

extern "C" Arcade::IGraphic *getLib()
{
    return new Arcade::libNcurses();
}

Arcade::libNcurses::libNcurses()
{
    initscr();
    cbreak();
    noecho();
    start_color();
    _window = newwin(800, 600, 0, 0);
    wrefresh(_window);
    init_pair(Arcade::Color::BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(Arcade::Color::RED, COLOR_RED, COLOR_BLACK);
    init_pair(Arcade::Color::WHITE, COLOR_WHITE, COLOR_BLACK);
}

Arcade::libNcurses::~libNcurses()
{
}

void Arcade::libNcurses::drawPixel(Pixel *pixel)
{
    char pix = '*';

    attron(COLOR_PAIR(pixel->getColor()));
    for (int i = 0; i < pixel->getSize(); i++) {
        for (int j = 0; j < pixel->getSize(); j++)
            mvaddch(pixel->getYPos() + i, pixel->getXPos() + j, pix);
    }
    attroff(COLOR_PAIR(pixel->getColor()));
}

void Arcade::libNcurses::drawText(Text *text)
{
    attron(COLOR_PAIR(text->getColor()));
    mvaddstr(text->getYPos(), text->getXPos(), text->getStr().c_str());
    attroff(COLOR_PAIR(text->getColor()));
}

void Arcade::libNcurses::myClear()
{
    clear();
}

void Arcade::libNcurses::myRefresh()
{
    refresh();
}

Arcade::CommandType Arcade::libNcurses::getInput()
{
    int ch = getch();
    Arcade::CommandType cmd = NONE;

    if (ch < 0)
        return cmd;
    switch (ch)
    {
    case 27:
        cmd = ESCAPE;
        break;
    case KEY_DOWN:
        cmd = KEYDOWN;
        break;
    case KEY_UP:
        cmd = KEYUP;
        break;
    case KEY_ENTER:
        cmd = ENTER;
        break;
    case ' ':
        cmd = SPACE;
        break;
    }
    return cmd;
}
