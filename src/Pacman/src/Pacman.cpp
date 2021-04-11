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

extern "C" Arcade::IGame *getLib()
{
    return new Arcade::Pacman();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GAME;
}

Arcade::Pacman::Pacman()
{
    _map = getMap("assets/map.txt");
    createGhost();
    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
    _time = 0.0f;
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
        Pixel pix = {(*i).getPosX(), (*i).getPosY(), (*i).getColor(), 2};
        lib->drawPixel(&pix);
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

void Arcade::Pacman::getEvent(Arcade::CommandType cmd, IGraphic *lib)
{
    (void)lib;
    if (cmd == CommandType::RIGHT && _dir != PacmanGame::dir::LEFT)
        _nextDir = PacmanGame::dir::RIGHT;
    else if (cmd == CommandType::LEFT && _dir != PacmanGame::dir::RIGHT)
        _nextDir = PacmanGame::dir::LEFT;
    else if (cmd == CommandType::UP && _dir != PacmanGame::dir::DOWN)
        _nextDir = PacmanGame::dir::UP;
    else if (cmd == CommandType::DOWN && _dir != PacmanGame::dir::UP)
        _nextDir = PacmanGame::dir::DOWN;
    else if (cmd == CommandType::R)
        remake();
}

void Arcade::Pacman::update(double timeElapsed)
{
    _time += timeElapsed;
    if (_time >= double(1 / 60)) {
        switch (_pacman.getDir())
        {
            case PacmanGame::dir::LEFT:
                if (_map[_pacman.getPosY()][_pacman.getPosX() + 1] != '1') {
                    _map[_pacman.getPosY()][_pacman.getPosX()] = ' ';
                    _pacman.setPosX(_pacman.getPosX() + 1);
                    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
                }
                break;
            case PacmanGame::dir::RIGHT:
                if (_map[_pacman.getPosY()][_pacman.getPosX() - 1] != '1') {
                    _map[_pacman.getPosY()][_pacman.getPosX()] = ' ';
                    _pacman.setPosX(_pacman.getPosX() - 1);
                    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
                }
                break;
            case PacmanGame::dir::DOWN:
                if (_map[_pacman.getPosY() + 1][_pacman.getPosX()] != '1') {
                    _map[_pacman.getPosY()][_pacman.getPosX()] = ' ';
                    _pacman.setPosX(_pacman.getPosX() + 1);
                    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
                }
                break;
            case PacmanGame::dir::UP:
                if (_map[_pacman.getPosY() - 1][_pacman.getPosX()] != '1') {
                    _map[_pacman.getPosY()][_pacman.getPosX()] = ' ';
                    _pacman.setPosX(_pacman.getPosX() - 1);
                    _map[_pacman.getPosY()][_pacman.getPosX()] = 'P';
                }
                break;
            case PacmanGame::NONE:
                break;
        }
    }
}

void Arcade::Pacman::createGhost()
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

void Arcade::Pacman::remake()
{
    
}