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
/*
static translateColor(Arcade::Color color)
{
    switch (color) {
        case Arcade::Color::YELLOW:
            return SDL_YELLOW;
        case Arcade::Color::RED:
            return SDL_RED;
        case Arcade::Color::BLUE:
            return SDL_BLUE;
        case Arcade::Color::WHITE:
            return SDL_WHITE;
        case Arcade::Color::BLACK:
            return SDL_BLACK;
        case Arcade::Color::CYAN:
            return SDL_CYAN;
        case Arcade::Color::GREEN:
            return SDL_GREEN;
        case Arcade::Color::MAGENTA:
            return SDL_MAGENTA;
        case Arcade::Color::TRANSPARENT:
            return SDL_TRANSPARENT;
    }
    return SDL_BLACK;
}
*/
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
    Arcade::CommandType cmd = NO_EVENT;

    if (ch < 0)
        return cmd;
    auto it = NCURSES_key.find(ch);
    return it == NCURSES_key.end() ? Arcade::NO_EVENT : it->second;
}
