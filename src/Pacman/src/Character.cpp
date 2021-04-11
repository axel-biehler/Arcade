/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Character
*/

#include "Character.hpp"

PacmanGame::Character::Character()
{
    _pos[0] = 40;
    _pos[1] = 64;
    _dir = NONE;
}

PacmanGame::Character::~Character()
{
}

int PacmanGame::Character::getPosX() const
{
    return _pos[0];
}

void PacmanGame::Character::setPosX(int pos)
{
    _pos[0] = pos;
}

int PacmanGame::Character::getPosY() const
{
    return _pos[1];
}

void PacmanGame::Character::setPosY(int pos)
{
    _pos[1] = pos;
}

PacmanGame::dir PacmanGame::Character::getDir() const
{
    return _dir;
}

void PacmanGame::Character::setDir(dir direction)
{
    _dir = direction;
}

void PacmanGame::Character::operator=(PacmanGame::Character &c)
{
    _pos[0] = c.getPosX();
    _pos[1] = c.getPosY();
    _dir = c.getDir();
}
