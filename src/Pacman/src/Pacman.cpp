/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Pacman
*/

#include <fstream>
#include <iostream>
#include "Pacman.hpp"
#include "IGraphic.hpp"

Arcade::Pacman::Pacman(Arcade::Core core)
{
    _map = getMap("assets/map.txt");
    createGhost();
}

Arcade::Pacman::~Pacman()
{
}

std::vector<std::string> Arcade::Pacman::getMap(const std::string &path)
{
    std::vector<std::string> map;
    std::string line;
    std::ifstream file (path);

    if (file.is_open()) {
        while (getline(file, line)) {
            map.push_back(line);
        }
    }
    return map;
}

void Arcade::Pacman::draw()
{

}

void Arcade::Pacman::getEvent()
{

}

void Arcade::Pacman::remake()
{

}

void Arcade::Pacman::update(double timeElapsed)
{
    
}

std::vector<Ghost> Arcade::Pacman::createGhost()
{
    for (int i = 0; i < 4; i++) {
        Ghost ghost;
        _ghosts.push_back(ghost);
    }
}