/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Ghost
*/

#include "Ghost.hpp"
#include <iostream>

PacmanGame::Ghost::Ghost(Arcade::Color color)
{
    _pos[0] = 38;
    _pos[1] = 34;
    _color = color;
    _isAffraid = false;
    _dir = PacmanGame::UP;
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

PacmanGame::dir PacmanGame::Ghost::changeDir(std::vector<std::string> map)
{
    srand (time(NULL));
    int dir = rand() % 4;

    if (dir == PacmanGame::dir::DOWN && map[_pos[1] / 2 + 1][_pos[0] / 2 ] != '1')
        return (PacmanGame::dir)dir;
    else if (dir == PacmanGame::dir::UP && map[_pos[1] / 2 - 1][_pos[0] / 2] != '1')
        return (PacmanGame::dir)dir;
    else if (dir == PacmanGame::dir::RIGHT && map[_pos[1] / 2][_pos[0] / 2 + 1] != '1')
        return (PacmanGame::dir)dir;
    else if (dir == PacmanGame::dir::LEFT && map[_pos[1] / 2][_pos[0] / 2 - 1] != '1')
        return (PacmanGame::dir)dir;
    return NONE;
}

void PacmanGame::Ghost::move(std::vector<std::string> map, double timeElapsed)
{
    (void)timeElapsed;
    switch (_dir)
    {
        case PacmanGame::dir::LEFT:
            if (map[_pos[1] / 2][_pos[0] / 2 - 1 ] != '1') {
                map[_pos[1] / 2 ][_pos[0] / 2 ] = ' ';
                _pos[0] = (_pos[0] - 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::RIGHT:
            if (map[_pos[1] / 2 ][_pos[0] / 2 + 1 ] != '1') {
                map[_pos[1] / 2 ][_pos[0] / 2 ] = ' ';
                _pos[0] = (_pos[0] + 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::DOWN:
            if (map[_pos[1] / 2 + 1 ][_pos[0] / 2 ] != '1') {
                map[_pos[1] / 2 ][_pos[0] / 2 ] = ' ';
                _pos[1] = (_pos[1] + 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::UP:
            if (map[_pos[1] / 2 - 1 ][_pos[0] / 2 ] != '1') {
                map[_pos[1] / 2 ][_pos[0] / 2 ] = ' ';
                _pos[1] = (_pos[1] - 2);
            } else
                _dir = NONE;
            break;
        default:
            while (_dir == NONE)
                _dir = changeDir(map);
            break;
    }
}
