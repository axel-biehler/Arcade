/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#include "Character.hpp"

Character::Character()
{
    _pos = {17, 19};
    _lifePoint = 3;
    _dir = NONE;
}

Character::~Character()
{
}

std::vector<int> Character::getPos() const
{
    return _pos;
}

void Character::setPos(std::vector<int> pos)
{
    _pos = pos;
}

int Character::getLifePoint() const
{
    return _lifePoint;
}

void Character::setLifePoint(int lifepoint)
{
    _lifePoint = lifepoint;
}

dir Character::getDir() const
{
    return _dir;
}

void Character::setDir(dir direction)
{
    _dir = direction;
}