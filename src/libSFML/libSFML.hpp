/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP
#define B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP

#include <SFML/Graphics.hpp>
#include "../../includes/IGraphic.hpp"
#include "../utils/Pixel/Pixel.hpp"
#include "../utils/Text/Text.hpp"

namespace Arcade {
    class libSFML: public IGraphic {
    public:
        libSFML();
        ~libSFML();
        void drawPixel(Pixel *pixel) override;
        void drawText(Text *text) override;
        void myClear() override;
        void myRefresh() override;
        Arcade::CommandType getInput() override;
        int convertToDisplay(int size, int max, Round round) override;
    private:
        sf::RenderWindow _window;
    };
}

#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_LIBSFML_HPP
