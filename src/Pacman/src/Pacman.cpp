/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Pacman
*/

#include <fstream>
#include <iostream>
#include "Pacman.hpp"
#include "../../../includes/IGraphic.hpp"

Arcade::Pacman::Pacman()
{
    _map = getMap("assets/map.txt");
    createGhost();
    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
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

void Arcade::Pacman::drawGhost(Arcade::IGraphic *lib)
{
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        
    }
}

void Arcade::Pacman::draw(IGraphic *lib)
{
    Pixel wall = {0, 0, Color::BLUE, 2};
    Pixel orb = {0, 0, Color::WHITE, 1};
    Pixel maxOrb = {0, 0, Arcade::YELLOW, 1};
    Pixel player = {_pacman.getPosX(), _pacman.getPosY(), Arcade::YELLOW, 2};
    int pos[2] = {0, 0};

    for (auto i = _map.begin(); i != _map.end(); i++) {
        for (auto j = 0; (*i)[j]; ++j) {
            wall.setXPos(pos[0]);
            wall.setYPos(pos[1]);
            switch ((*i)[j])
            {
                case '0':
                    lib->drawPixel(&orb);
                    break;
                case '1':
                    lib->drawPixel(&wall);
                    break;
                case '2':
                    lib->drawPixel(&maxOrb);
                    break;
                case 'P':
                    lib->drawPixel(&player);
                    break;
                case 'G':
                    drawGhost(lib);
                default:
                    break;
            }
            pos[0] += 2;
        }
        pos[0] = 0;
        pos[1] += 2;
    }
}

Arcade::CommandType Arcade::Pacman::getEvent(Arcade::CommandType cmd, IGraphic *lib)
{
    

    return Arcade::CommandType::NO_EVENT;
}

void Arcade::Pacman::remake()
{

}

void Arcade::Pacman::update(double timeElapsed)
{
    if (timeElapsed >= double(1 / 60)) {
        switch (_pacman.getDir())
        {
            case PacmanGame::dir::LEFT:
                
                break;
            case PacmanGame::dir::RIGHT:

                break;
            case PacmanGame::dir::DOWN:

                break;
            case PacmanGame::dir::UP:

                break;
        }
    }
}

std::vector<PacmanGame::Ghost> Arcade::Pacman::createGhost()
{
    std::vector<Color> colors = {Color::GREEN, Color::CYAN, Color::RED, Color::WHITE};

    for (int i = 0; i < 4; i++) {
        PacmanGame::Ghost ghost(colors[i]);
        _ghosts.push_back(ghost);
    }
}

void Arcade::Pacman::initPlayerName(std::string playerName)
{
    _name = playerName;
}