/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <vector>

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

        std::vector<int> getPos() const;
        void setPos(std::vector<int> pos);
        int getLifePoint() const;
        void setLifePoint(int lifepoint);
        dir getDir() const;
        void setDir(dir direction);

    private:
        std::vector<int> _pos;
        int _lifePoint;
        dir _dir;
};

#endif /* !CHARACTER_HPP_ */
