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
    srand(time(nullptr));
    _defeat = false;
    _win = false;
    _offset = 10;
    _score = 0;
    _level = 1;
    _stored = false;
    _timeAffraid = 0.0f;
    _isAffrayed = false;
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
        Pixel pix = {(*i).getPosX() + _offset, (*i).getPosY() + _offset, (*i).getColor(), 2};
        lib->drawPixel(&pix);
    }
}

void Arcade::Pacman::moveGhost(double timeElapsed)
{
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        (*i).move(_map, timeElapsed);
    }
}

static void storeScore(const std::string game, const std::string playerName, int score)
{
    std::ofstream myfile(game + ".txt");
    if (myfile.is_open()) {
        myfile << playerName << ": " << score << "\n";
        myfile.close();
    } else
        std::cout << "Unable to store score" << std::endl;
}

void Arcade::Pacman::draw(IGraphic *lib)
{
    Pixel wall = {0, 0, Color::BLUE, 2};
    Pixel orb = {0, 0, Color::WHITE, 1};
    Pixel maxOrb = {0, 0, Color::YELLOW, 1};
    Pixel player = {_pacman.getPosX() + _offset, _pacman.getPosY() + _offset, Arcade::YELLOW, 2};
    Pixel back = {50, 50, Arcade::BLACK, 100};
    Text win = {90, 5, "Level " + std::to_string(_level), Arcade::WHITE};
    Text lose = {50, 50, "You lose", Arcade::WHITE, 6};
    Text score = {10, 5, "Score: " + std::to_string(_score)};
    Text name = {50, 5, _name};
    int pos[2] = {_offset, _offset};

    lib->drawPixel(&back);
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
                    break;
            }
            pos[0] += 2;
        }
        pos[0] = _offset;
        pos[1] += 2;
    }
    drawGhost(lib);
    lib->drawPixel(&player);
    lib->drawText(&win);
    if (_defeat)
        lib->drawText(&lose);
    if ((_win || _defeat) && !_stored) {
        storeScore("Pacman", _name, _score);
        _stored = true;
    }
    lib->drawText(&score);
    lib->drawText(&name);
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

    if ((_nextDir == PacmanGame::LEFT) && _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 - 1 ] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::RIGHT && _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 + 1 ] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::UP && _map[_pacman.getPosY() / 2 - 1 ][_pacman.getPosX() / 2 ] != '1')
        _pacman.setDir(_nextDir);
    else if (_nextDir == PacmanGame::DOWN && _map[_pacman.getPosY() / 2 + 1 ][_pacman.getPosX() / 2 ] != '1')
        _pacman.setDir(_nextDir);
    else if (_pacman.getDir() == PacmanGame::NONE)
        _pacman.setDir(_nextDir);
}

void Arcade::Pacman::ghostAffraid()
{
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        (*i).setIsAffraid(true);
        (*i).setColor(Arcade::Color::GREEN);
    }
}

void Arcade::Pacman::update(double timeElapsed)
{
    _time += timeElapsed;
    if (_isAffrayed)
        _timeAffraid += timeElapsed;
    if (_time >= double(1 / 5.0f) && !_win && !_defeat) {
        switch (_pacman.getDir())
        {
            case PacmanGame::dir::LEFT:
                if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 - 1] != '1') {
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '0')
                        _score += 1;
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '2') {
                        _score += 50;
                        _isAffrayed = true;
                        ghostAffraid();
                    }
                    _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] = ' ';
                    _pacman.setPosX(_pacman.getPosX() - 2);
                }
                break;
            case PacmanGame::dir::RIGHT:
                if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 + 1 ] != '1') {
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '0')
                        _score += 1;
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '2') {
                        _score += 50;
                        _isAffrayed = true;
                        ghostAffraid();
                    }
                    _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 ] = ' ';
                    _pacman.setPosX(_pacman.getPosX() + 2);
                }
                break;
            case PacmanGame::dir::DOWN:
                if (_map[_pacman.getPosY() / 2 + 1][_pacman.getPosX() / 2 ] != '1') {
                    if (_map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] == '0')
                        _score += 1;
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '2') {
                        _score += 50;
                        _isAffrayed = true;
                        ghostAffraid();
                    }
                    _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 ] = ' ';
                    _pacman.setPosY(_pacman.getPosY() + 2);
                }
                break;
            case PacmanGame::dir::UP:
                if (_map[_pacman.getPosY() / 2 - 1 ][_pacman.getPosX() / 2 ] != '1') {
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '0' || _map[_pacman.getPosY() / 2][_pacman.getPosX() / 2] == '2')
                        _score += 1;
                    if (_map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2] == '2') {
                        _score += 50;
                        _isAffrayed = true;
                        ghostAffraid();
                    }
                    _map[_pacman.getPosY() / 2 ][_pacman.getPosX() / 2 ] = ' ';
                    _pacman.setPosY(_pacman.getPosY() - 2);
                }
                break;
            case PacmanGame::NONE:
                break;
        }
        moveGhost(timeElapsed);
        checkContactGhost();
        check_win();
        _time = 0;
        if (_win) {
            nextLevel();
            _win = false;
        }
    }
    if (_timeAffraid >= 20.0f && _isAffrayed) {
        int j = 0;
        _isAffrayed = false;
        std::vector<Color> colors = {Color::GREEN, Color::CYAN, Color::RED, Color::WHITE};
        for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
            (*i).setIsAffraid(false);
            (*i).setColor(colors[j]);
            j++;
        }
        _timeAffraid = 0;
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

void Arcade::Pacman::check_win()
{
    int count = 0;

    for (auto i = _map.begin(); i != _map.end(); i++) {
        for (auto j = 0; (*i)[j]; ++j) {
            if ((*i)[j] == '0' || (*i)[j] == '2')
                count++;
        }
    }
    if (count == 0)
        _win = true;
}

void Arcade::Pacman::checkContactGhost()
{
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        if ((*i).getPosX() == _pacman.getPosX() && (*i).getPosY() == _pacman.getPosY() && !_isAffrayed) {
            _defeat = true;
        } else if ((*i).getPosX() == _pacman.getPosX() && (*i).getPosY() == _pacman.getPosY() && _isAffrayed) {
            (*i).setPosX(38);
            (*i).setPosY(28);
            _score += 100;
        }
    }
}

void Arcade::Pacman::remake()
{
    _ghosts.clear();
    _map.clear();
    PacmanGame::Character charac;
    _pacman = charac;
    _map = getMap("src/Pacman/assets/map.txt");
    createGhost();
    _time = 0.0f;
    _nextDir = PacmanGame::NONE;
    srand(time(nullptr));
    _score = 0;
    _level = 0;
    _defeat = false;
    _win = false;
    _stored = true;
}

void Arcade::Pacman::nextLevel()
{
    _level += 1;
    _pacman.setPosX(40);
    _pacman.setPosY(64);
    for (auto i = _ghosts.begin(); i != _ghosts.end(); i++) {
        (*i).setPosX(38);
        (*i).setPosY(28);
    }
    _win = false;
    _map = getMap("src/Pacman/assets/map.txt");
}