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
    SDL_Surface *surface;

    SDL_LockSurface(surface);
    std::vector<uint8_t> pixels(surface->h * surface->pitch, 0);

    int dy;
    int dx;
    int maxwidth = width * 3;
    for (dy = y; dy < height; dy++) {
        for (dx = x; dx < maxwidth; dx += 3) {
            pixels[dx + (dy * surface->pitch)] = 0;
            pixels[dx + (dy * surface->pitch) + 1] = 255;
            pixels[dx + (dy * surface->pitch) + 2] = 0;
        }
    }
    memcpy(surface->pixels, pixels.data(), surface->pitch * surface->h);

    SDL_UnlockSurface(surface);
}