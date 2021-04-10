/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <vector>

class Character {
    public:
        Character();
        ~Character();

        std::vector<std::vector<int>> getPos() const;
        void setPos();

    private:
        std::vector<std::vector<int>> _pos;
        int _lifePoint;
};

#endif /* !CHARACTER_HPP_ */
