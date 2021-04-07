/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP
#define B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include "../../includes/IGraphic.hpp"
#include "../utils/Pixel/Pixel.hpp"
#include "../utils/Text/Text.hpp"
#include "../../includes/PersonnalType.hpp"

namespace Arcade {
    class libSFML: public IGraphic {
    public:
        libSFML();
        ~libSFML() override;
        void drawPixel(Pixel *pixel) override;
        void drawText(Text *text) override;
        void myClear() override;
        void myRefresh() override;
        Arcade::CommandType getInput() override;
    private:
        sf::RenderWindow _window;
    };
    IGraphic *getLib();
    LibType getLibType();

    std::map<int, CommandType> SFML_key {
        {sf::Keyboard::A,      A},
        {sf::Keyboard::B,      B},
        {sf::Keyboard::C,      C},
        {sf::Keyboard::D,      D},
        {sf::Keyboard::E,      E},
        {sf::Keyboard::F,      F},
        {sf::Keyboard::G,      G},
        {sf::Keyboard::H,      H},
        {sf::Keyboard::I,      I},
        {sf::Keyboard::J,      J},
        {sf::Keyboard::K,      K},
        {sf::Keyboard::L,      L},
        {sf::Keyboard::M,      M},
        {sf::Keyboard::N,      N},
        {sf::Keyboard::O,      O},
        {sf::Keyboard::P,      P},
        {sf::Keyboard::Q,      Q},
        {sf::Keyboard::R,      R},
        {sf::Keyboard::S,      S},
        {sf::Keyboard::T,      T},
        {sf::Keyboard::U,      U},
        {sf::Keyboard::V,      V},
        {sf::Keyboard::W,      W},
        {sf::Keyboard::X,      X},
        {sf::Keyboard::Y,      Y},
        {sf::Keyboard::Z,      Z},
        {sf::Keyboard::Num0,   NUM0},
        {sf::Keyboard::Num1,   NUM1},
        {sf::Keyboard::Num2,   NUM2},
        {sf::Keyboard::Num3,   NUM3},
        {sf::Keyboard::Num4,   NUM4},
        {sf::Keyboard::Num5,   NUM5},
        {sf::Keyboard::Num6,   NUM6},
        {sf::Keyboard::Num7,   NUM7},
        {sf::Keyboard::Num8,   NUM8},
        {sf::Keyboard::Num9,   NUM9},
        {sf::Keyboard::Left,   LEFT},
        {sf::Keyboard::Right,  RIGHT},
        {sf::Keyboard::Up,     UP},
        {sf::Keyboard::Down,   DOWN},
        {sf::Keyboard::Enter,  ENTER},
        {sf::Keyboard::Space,  SPACE},
        {sf::Keyboard::Delete, BACKSPACE},
        {sf::Keyboard::Escape, ESC},
        {sf::Keyboard::F1,     F1},
        {sf::Keyboard::F2,     F2},
        {sf::Keyboard::F3,     F3},
        {sf::Keyboard::F4,     F4},
        {sf::Keyboard::F5,     F5},
        {sf::Keyboard::F6,     F6},
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP
