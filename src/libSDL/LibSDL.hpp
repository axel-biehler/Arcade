/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard [WSL: Ubuntu-20.04]
** File description:
** LibSDL
*/

#pragma once

#include <SDL2/SDL.h>
#include "../../includes/IGraphic.hpp"

#define SDL_BLUE SDL_Color{0, 0, 255, 255}
#define SDL_WHITE SDL_Color{255, 255, 255, 255}
#define SDL_RED SDL_Color{255, 0, 0, 255}

namespace Arcade {
    class LibSDL : public IGraphic{
        public:
            LibSDL();
            ~LibSDL();

            void drawPixel(Pixel *pixel) override;
            void drawText(Text *text) override;
            void myClear() override;
            void myRefresh() override;
            Arcade::CommandType getInput() override;

            IGraphic *getLib();
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
    };
}
