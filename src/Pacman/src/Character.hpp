/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <vector>

namespace PacmanGame {

    enum dir {
        LEFT,
        RIGHT,
        DOWN,
        UP,
        NONE
    };

    class Character {
        public:
            Character();
            ~Character();

            int getPosX() const;
            int getPosY() const;
            void setPosX(int pos[2]);
            void setPosY(int pos[2]);
            int getLifePoint() const;
            void setLifePoint(int lifepoint);
            dir getDir() const;
            void setDir(dir direction);

        private:
            int _pos[2];
            int _lifePoint;
            dir _dir;
    };
}

#endif /* !CHARACTER_HPP_ */
