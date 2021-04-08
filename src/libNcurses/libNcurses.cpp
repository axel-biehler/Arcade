/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libNcurses
*/

#include <cstring>
#include <iostream>
#include "libNcurses.hpp"
#include "../../includes/PersonnalType.hpp"

extern "C" Arcade::IGraphic *getLib()
{
    return new Arcade::libNcurses();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GRAPHIC;
}

static int translateColor(Arcade::Color color, bool txt)
{
    switch (color) {
        case Arcade::Color::YELLOW:
            if (txt)
                return NCT_YELLOW;
            else
                return NCS_YELLOW;
        case Arcade::Color::RED:
            if (txt)
                return NCT_RED;
            else
                return NCS_RED;
        case Arcade::Color::BLUE:
            if (txt)
                return NCT_BLUE;
            else
                return NCS_BLUE;
        case Arcade::Color::WHITE:
            if (txt)
                return NCT_WHITE;
            else
                return NCS_WHITE;
        case Arcade::Color::BLACK:
            if (txt)
                return NCT_BLACK;
            else
                return NCS_BLACK;
        case Arcade::Color::CYAN:
            if (txt)
                return NCT_CYAN;
            else
                return NCS_CYAN;
        case Arcade::Color::GREEN:
            if (txt)
                return NCT_GREEN;
            else
                return NCS_GREEN;
        case Arcade::Color::MAGENTA:
            if (txt)
                return NCT_MAGENTA;
            else
                return NCS_MAGENTA;
        case Arcade::Color::TRANSPARENT:
            if (txt)
                return NCT_BLACK;
            else
                return NCS_BLACK;
    }
    return NCS_BLACK;
}

Arcade::libNcurses::libNcurses()
{
    _window = initscr();
    cbreak();
    noecho();
    nodelay(_window, true);
    start_color();
    keypad(stdscr, TRUE);
    init_pair(NCT_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(NCT_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(NCT_RED, COLOR_RED, COLOR_BLACK);
    init_pair(NCT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(NCT_BLACK, COLOR_BLACK, COLOR_WHITE);
    init_pair(NCT_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(NCT_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(NCT_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(NCS_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(NCS_WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(NCS_RED, COLOR_RED, COLOR_RED);
    init_pair(NCS_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(NCS_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(NCS_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(NCS_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(NCS_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
}

Arcade::libNcurses::~libNcurses()
{
    endwin();
}

void Arcade::libNcurses::drawPixel(Pixel *pixel)
{
    char pix = ' ';
    int x = COLS * pixel->getXPos() / 100 - 0.5 * pixel->getSize();
    int y = LINES * pixel->getYPos() / 100 - 0.5 * pixel->getSize();

    attron(COLOR_PAIR(translateColor(pixel->getColor(), false)));
    for (int i = 0; i < pixel->getSize(); i++) {
        for (int j = 0; j < pixel->getSize(); j++)
            mvaddch(y + i, x + j, pix);
    }
    attroff(COLOR_PAIR(translateColor(pixel->getColor(), false)));
}

void Arcade::libNcurses::drawText(Text *text)
{
    int x = COLS * text->getXPos() / 100 - 0.5 * strlen(text->getStr().c_str());
    int y = LINES * text->getYPos() / 100 - 0.5 * 1;

    attron(COLOR_PAIR(translateColor(text->getColor(), true)));
    mvprintw(y, x, "%s", text->getStr().c_str());
    attroff(COLOR_PAIR(translateColor(text->getColor(), true)));
}

void Arcade::libNcurses::myClear()
{
    //clear();
}

void Arcade::libNcurses::myRefresh()
{
    refresh();
}

Arcade::CommandType Arcade::libNcurses::getInput()
{
    int ch = getch();
    Arcade::CommandType cmd = NO_EVENT;

    if (ch < 0)
        return cmd;
    auto it = NCURSES_key.find(ch);
    return it == NCURSES_key.end() ? Arcade::NO_EVENT : it->second;
}
