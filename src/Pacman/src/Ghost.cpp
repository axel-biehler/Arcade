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
    _pos[1] = 28;
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
    if (map[_pos[1] / 2 + 1][_pos[0] / 2] != '1')
        return (PacmanGame::dir)DOWN;
    else if (map[_pos[1] / 2][_pos[0] / 2 + 1] != '1')
        return (PacmanGame::dir)RIGHT;
    else if (map[_pos[1] / 2 - 1][_pos[0] / 2] != '1')
        return (PacmanGame::dir)UP;
    else if (map[_pos[1] / 2][_pos[0] / 2 - 1] != '1')
        return (PacmanGame::dir)LEFT;
    return NONE;
}

static PacmanGame::dir chooseWay(std::vector<std::string> map, int *pos, PacmanGame::dir actualDir)
{
    bool chance = random() % 2;
    int doubleChance = (int)(random() % 4);

    if (!((map[pos[1] / 2 + 1][pos[0] / 2] != '1' || map[pos[1] / 2 - 1][pos[0] / 2] != '1') && (map[pos[1] / 2][pos[0] / 2 - 1] != '1' || map[pos[1] / 2][pos[0] / 2 + 1] != '1')))
        return actualDir;
    else if ((actualDir == PacmanGame::UP || actualDir == PacmanGame::DOWN) && map[pos[1] / 2][pos[0] / 2 + 1] != '1' && chance)
        return PacmanGame::RIGHT;
    else if ((actualDir == PacmanGame::UP || actualDir == PacmanGame::DOWN) && map[pos[1] / 2][pos[0] / 2 - 1] != '1' && chance)
        return PacmanGame::LEFT;
    else if ((actualDir == PacmanGame::RIGHT || actualDir == PacmanGame::LEFT) && map[pos[1] / 2 + 1][pos[0] / 2] != '1' && chance)
        return PacmanGame::DOWN;
    else if ((actualDir == PacmanGame::RIGHT || actualDir == PacmanGame::LEFT) && map[pos[1] / 2 - 1][pos[0] / 2] != '1' && chance)
        return PacmanGame::UP;
    if (doubleChance == 0)
        return PacmanGame::UP;
    else if (doubleChance == 1)
        return PacmanGame::DOWN;
    else if (doubleChance == 2)
        return PacmanGame::LEFT;
    else if (doubleChance == 3)
        return PacmanGame::RIGHT;
    return chance ? PacmanGame::LEFT : PacmanGame::RIGHT;
}

void PacmanGame::Ghost::move(std::vector<std::string> map, double timeElapsed)
{
    (void)timeElapsed;
    _dir = chooseWay(map, _pos, _dir);
    switch (_dir)
    {
        case PacmanGame::dir::LEFT:
            if (map[_pos[1] / 2][_pos[0] / 2 - 1] != '1') {
                map[_pos[1] / 2][_pos[0] / 2] = ' ';
                _pos[0] = (_pos[0] - 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::RIGHT:
            if (map[_pos[1] / 2][_pos[0] / 2 + 1] != '1') {
                map[_pos[1] / 2][_pos[0] / 2] = ' ';
                _pos[0] = (_pos[0] + 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::DOWN:
            if (map[_pos[1] / 2 + 1][_pos[0] / 2] != '1') {
                map[_pos[1] / 2][_pos[0] / 2] = ' ';
                _pos[1] = (_pos[1] + 2);
            } else
                _dir = NONE;
            break;
        case PacmanGame::dir::UP:
            if (map[_pos[1] / 2 - 1][_pos[0] / 2] != '1') {
                map[_pos[1] / 2][_pos[0] / 2] = ' ';
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