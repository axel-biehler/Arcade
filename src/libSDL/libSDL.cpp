/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libSDL
*/

#include "LibSDL.hpp"
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
        SDL_RENDERER_ACCELERATED,
    );
}

Arcade::LibSDL::~LibSDL()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

Arcade::LibSDL::drawPixel(Pixel *pixel)
{

}