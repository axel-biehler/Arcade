/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** libSDL
*/

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "LibSDL.hpp"

extern "C" Arcade::IGraphic *getLib()
{
    return new Arcade::LibSDL();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GRAPHIC;
}

static SDL_Color translateColor(Arcade::Color color)
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

Arcade::LibSDL::LibSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _font = TTF_OpenFont("src/utils/fonts/ARCADE_N.TTF", 19);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

Arcade::LibSDL::~LibSDL()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Arcade::LibSDL::drawPixel(Pixel *pixel)
{
    int rendererW = 0;
    int rendererH = 0;
    SDL_GetRendererOutputSize(_renderer, &rendererW, &rendererH);
    int sizeX = pixel->getSize() * rendererW / 100;
    int sizeY = pixel->getSize() * rendererH / 100;

    SDL_Rect rect{
        rendererW * pixel->getXPos() / 100 - sizeX / 2,
        rendererH * pixel->getYPos() / 100 - sizeY / 2,
        sizeX,
        sizeY
    };
    SDL_Color color = translateColor(pixel->getColor());
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
}

void Arcade::LibSDL::drawText(Text *text)
{
    SDL_Color color = translateColor(text->getColor());
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;
    SDL_Rect Message_rect;
    SDL_DisplayMode dm;
    int textW = 0;
    int textH = 0;
    int rendererW = 0;
    int rendererH = 0;

    TTF_SizeText(_font, text->getStr().c_str(), &textW, &textH);
    SDL_GetRendererOutputSize(_renderer, &rendererW, &rendererH);

    surfaceMessage = TTF_RenderText_Solid(_font, text->getStr().c_str(), color);
    Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_GetDesktopDisplayMode(0, &dm);
    Message_rect.x = rendererW * text->getXPos() / 100 - 0.5 * textW;
    Message_rect.y = rendererH * text->getYPos() / 100 - 0.5 * textH;
    Message_rect.w = textW;
    Message_rect.h = textH;
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

    if (SDL_PollEvent(&event) == 0)
        return Arcade::NO_EVENT;
    if (event.type == SDL_QUIT)
        return Arcade::ESC;
    if (event.type == SDL_KEYUP) {
        auto it = SDL_key.find(event.key.keysym.sym);
        return it == SDL_key.end() ? Arcade::NO_EVENT : it->second;
    } else
        return Arcade::NO_EVENT;
}