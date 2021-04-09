/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#include "Character.hpp"

PacmanGame::Character::Character()
{
    _pos[0] = 17;
    _pos[1] = 19;
    _lifePoint = 3;
    _dir = NONE;
}

PacmanGame::Character::~Character()
{
}

int PacmanGame::Character::getPosX() const
{
    return _pos[0];
}

void PacmanGame::Character::setPosX(int pos[2])
{
    _pos[0] = pos[0];
}

int PacmanGame::Character::getPosY() const
{
    return _pos[1];
}

void PacmanGame::Character::setPosY(int pos[2])
{
    _pos[1] = _pos[1];
}

int PacmanGame::Character::getLifePoint() const
{
    return _lifePoint;
}

void PacmanGame::Character::setLifePoint(int lifepoint)
{
    _lifePoint = lifepoint;
}

PacmanGame::dir PacmanGame::Character::getDir() const
{
    return _dir;
}

void PacmanGame::Character::setDir(dir direction)
{
    _dir = direction;
}