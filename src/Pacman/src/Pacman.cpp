/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Pacman
*/

#include <fstream>
#include <iostream>
#include <unistd.h>
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
    PacmanGame::Character charac;
    _pacman = charac;
    _map = getMap("src/Pacman/assets/map.txt");
    createGhost();
    _time = 0.0f;
    _nextDir = PacmanGame::NONE;
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

void Arcade::Pacman::moveGhost(double timeElapsed)
{
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        (*i).move(_map, timeElapsed);
    }
}

void Arcade::Pacman::draw(IGraphic *lib)
{
    Pixel wall = {0, 0, Color::BLUE, 2};
    Pixel orb = {0, 0, Color::WHITE, 1};
    Pixel maxOrb = {0, 0, Color::YELLOW, 1};
    Pixel player = {_pacman.getPosX(), _pacman.getPosY(), Arcade::YELLOW, 2};
    int pos[2] = {0, 0};

    for (auto i = _map.begin(); i != _map.end(); i++) {
        for (auto j = 0; (*i)[j]; ++j) {
            wall.setXPos(pos[0]);
            wall.setYPos(pos[1]);
            orb.setXPos(pos[0]);
            orb.setYPos(pos[1]);
            maxOrb.setXPos(pos[0]);
            maxOrb.setYPos(pos[1]);
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
                default:
                    drawGhost(lib);
                    lib->drawPixel(&player);
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
    if (cmd == CommandType::RIGHT)
        _nextDir = PacmanGame::dir::RIGHT;
    else if (cmd == CommandType::LEFT)
        _nextDir = PacmanGame::dir::LEFT;
    else if (cmd == CommandType::UP)
        _nextDir = PacmanGame::dir::UP;
    else if (cmd == CommandType::DOWN)
        _nextDir = PacmanGame::dir::DOWN;
    else if (cmd == CommandType::R)
        remake();

    if ((_nextDir == PacmanGame::LEFT) && _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2 - 1] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::RIGHT && _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2 + 1] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::UP && _map[_pacman.getPosY() / 2 - 1][_pacman.getPosX() / 2] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::DOWN && _map[_pacman.getPosY() / 2 + 1][_pacman.getPosX() / 2] != '1')
        _pacman.setDir(_nextDir);
    else if (_pacman.getDir() == PacmanGame::NONE)
        _pacman.setDir(_nextDir);
}

void Arcade::Pacman::update(double timeElapsed)
{
    _time += timeElapsed;
    if (_time >= double(1 / 5.0f)) {
        switch (_pacman.getDir())
        {
            case PacmanGame::dir::LEFT:
                if (_map[_pacman.getPosY() / 2][_pacman.getPosX() / 2 - 1] != '1') {
                    _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] = ' ';
                    _pacman.setPosX(_pacman.getPosX() - 2);
                }
                break;
            case PacmanGame::dir::RIGHT:
                if (_map[_pacman.getPosY() / 2][_pacman.getPosX() / 2 + 1] != '1') {
                    _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] = ' ';
                    _pacman.setPosX(_pacman.getPosX() + 2);
                }
                break;
            case PacmanGame::dir::DOWN:
                if (_map[_pacman.getPosY() / 2 + 1][_pacman.getPosX() / 2] != '1') {
                    _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] = ' ';
                    _pacman.setPosY(_pacman.getPosY() + 2);
                }
                break;
            case PacmanGame::dir::UP:
                if (_map[_pacman.getPosY() / 2 - 1][_pacman.getPosX() / 2] != '1') {
                    _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] = ' ';
                    _pacman.setPosY(_pacman.getPosY() - 2);
                }
                break;
            case PacmanGame::NONE:
                break;
        }
        moveGhost(timeElapsed);
        _time = 0;
    }
}

void Arcade::Pacman::createGhost()
{
    std::vector<Color> colors = {Color::GREEN, Color::CYAN, Color::RED, Color::WHITE};
    std::vector<PacmanGame::Ghost> ghosts;

    for (int i = 0; i < 4; i++) {
        PacmanGame::Ghost ghost(colors[i]);
        ghosts.push_back(ghost);
    }
    _ghosts = ghosts;
}

void Arcade::Pacman::initPlayerName(std::string playerName)
{
    _name = playerName;
}

void Arcade::Pacman::remake()
{
    
}