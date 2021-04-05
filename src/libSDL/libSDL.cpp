/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libSDL
*/

#include "LibSDL.hpp"
#include <SDL2/SDL_ttf.h>
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
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Arcade::LibSDL::drawPixel(Pixel *pixel)
{
    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);
    float sizeX = pixel->getSize() * dm.w / 100;
    float sizeY = pixel->getSize() * dm.h / 100;
    SDL_Rect rect{
        dm.w * pixel->getXPos() / 100,
        dm.h * pixel->getYPos() / 100,
        (int)sizeX,
        (int)sizeY
    };

    if (pixel->getColor() == BLUE)
        SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
    if (pixel->getColor() == RED)
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    if (pixel->getColor() == WHITE)
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &rect);
}

void Arcade::LibSDL::drawText(Text *text)
{
    TTF_Font *font = TTF_OpenFont("../utils/fonts/ARCADE_N.TTF", 16);
    SDL_Color color = SDL_BLUE;
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;
    SDL_Rect Message_rect;
    SDL_DisplayMode dm;

    if (text->getColor() == Arcade::BLUE)
        color = SDL_BLUE;
    else if (text->getColor() == Arcade::RED)
        color = SDL_RED;
    else if (text->getColor() == Arcade::WHITE)
        color = SDL_WHITE;
    surfaceMessage = TTF_RenderText_Solid(font, text->getStr().c_str(), color);
    Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_GetDesktopDisplayMode(0, &dm);
    Message_rect.x = dm.w * text->getXPos() / 100 - 0.5 * dm.w;
    Message_rect.y = dm.h * text->getYPos() / 100 - 0.5 * dm.h;
    Message_rect.w = dm.w;
    Message_rect.h = dm.h;
    SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void Arcade::LibSDL::myClear()
{
    SDL_RenderClear(_renderer);
}

void Arcade::LibSDL::myRefresh()
{
    SDL_RenderPresent(_renderer);
}

Arcade::CommandType Arcade::LibSDL::getInput()
{
    SDL_Event event;

    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        return Arcade::ESCAPE;
    else if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
            return Arcade::RESIZE;
    } else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                return Arcade::SPACE;
            case SDLK_UP:
                return Arcade::KEYUP;
            case SDLK_DOWN:
                return Arcade::KEYDOWN;
            case SDLK_ESCAPE:
                return Arcade::ESCAPE;
            case SDLK_KP_ENTER:
                return Arcade::ENTER;
            default:
                return Arcade::NONE;
        }
    }
    return Arcade::CommandType::NONE;
}