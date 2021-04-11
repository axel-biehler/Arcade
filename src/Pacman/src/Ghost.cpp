/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Ghost
*/

#include "Ghost.hpp"

PacmanGame::Ghost::Ghost(Arcade::Color color)
{
    _pos[0] = 38;
    _pos[1] = 34;
    _color = color;
    _isAffraid = false;
}

PacmanGame::Ghost::~Ghost()
{
}

int PacmanGame::Ghost::getPosX() const
{
    return _pos[0];
}

void PacmanGame::Ghost::setPosX(int pos)
{
    _pos[0] = pos;
}

int PacmanGame::Ghost::getPosY() const
{
    return _pos[1];
}

void PacmanGame::Ghost::setPosY(int pos)
{
    _pos[1] = pos;
}

Arcade::Color PacmanGame::Ghost::getColor() const
{
    return _color;
}

void PacmanGame::Ghost::setColor(Arcade::Color color)
{
    _color = color;
}

bool PacmanGame::Ghost::getIsAffraid() const
{
    return _color;
}

void PacmanGame::Ghost::setIsAffraid(bool isAffraid)
{
    _isAffraid = isAffraid;
}
