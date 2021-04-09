/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Ghost
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "../../../includes/PersonnalType.hpp"

namespace PacmanGame {
    class Ghost {
        public:
            Ghost(Arcade::Color color);
            ~Ghost();

            void setColor(Arcade::Color color);
            Arcade::Color getColor() const;
            void setPosX(int pos);
            int getPosX() const;
            void setPosY(int pos);
            int getPosY() const;
            void setIsAffraid(bool b);
            bool getIsAffraid() const;

        private:
            int _pos[2];
            Arcade::Color _color;
            bool _isAffraid;
    };
}

#endif /* !GHOST_HPP_ */
