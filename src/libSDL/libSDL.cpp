/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libSDL
*/

#include "LibSDL.hpp"
#include <SDL/SDL_ttf.h>
#include "../../includes/IGraphic.hpp"

extern "C" Arcade::IGraphic *getLib()
{
    return new Arcade::LibSDL();
}

Arcade::LibSDL::LibSDL()
{
    _window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_OPENGL
    );
    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
}

Arcade::LibSDL::~LibSDL()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Arcade::LibSDL::drawPixel(Pixel *pixel)
{
    SDL_Rect rect{pixel->getXPos(), pixel->getYPos(), pixel->getSize(), pixel->getSize()};

    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(_renderer, &rect);
}

void Arcade::LibSDL::drawText(Text *text)
{
    TTF_Font *font = TTF_OpenFont("../utils/fonts/ARCADE_N.TTF");
    SDL_Color front = SDL_BLUE;
}