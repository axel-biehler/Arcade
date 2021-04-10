/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Snake
*/

#include <cstdlib> 
#include <ctime> 

#include "Snake.hpp"

extern "C" Arcade::IGame *getLib()
{
    return new Arcade::Snake();
}

extern "C" Arcade::LibType getLibType()
{
    return (Arcade::LibType)Arcade::GAME;
}

Arcade::Snake::Snake()
{
    _dt = 0.0f;
    _score = 0;
    _lose = false;
    _dir = Dir::DIR_RIGHT;
    _nextDir = Dir::DIR_RIGHT;
    _playerName = "FlexyMax";
    _bg = new Pixel(50, 50, Arcade::BLACK, 100);
    _map = new Pixel(50, 60, Arcade::WHITE, 74);
    _apple = new Pixel(68, 28, Arcade::RED, 2);
    _title = new Text(50, 10, "SNAKE", Arcade::MAGENTA);
    _name = new Text(15, 5, _playerName, Arcade::WHITE);
    _scoreText = new Text(85, 5, "score : 0", Arcade::WHITE);
    _snake.push_back(new Pixel(52, 50, Arcade::MAGENTA, 2));
    _snake.push_back(new Pixel(50, 50, Arcade::GREEN, 2));
    _snake.push_back(new Pixel(48, 50, Arcade::GREEN, 2));
    _snake.push_back(new Pixel(46, 50, Arcade::GREEN, 2));
}

Arcade::Snake::~Snake()
{
}

void Arcade::Snake::initPlayerName(std::string playerName)
{
    _playerName = playerName;
}

void Arcade::Snake::draw(IGraphic *lib)
{

    lib->drawPixel(_bg);
    lib->drawPixel(_map);
    lib->drawPixel(_apple);
    for (auto it = _snake.begin(); it != _snake.end(); it++) {
        lib->drawPixel(*(it));
    }
    lib->drawText(_name);
    lib->drawText(_title);
    lib->drawText(_scoreText);
}

void Arcade::Snake::getEvent(CommandType cmd, IGraphic *lib)
{
    if (cmd == CommandType::RIGHT && _dir != Dir::DIR_LEFT)
        _nextDir = Dir::DIR_RIGHT;
    else if (cmd == CommandType::LEFT && _dir != Dir::DIR_RIGHT)
        _nextDir = Dir::DIR_LEFT;
    else if (cmd == CommandType::UP && _dir != Dir::DIR_DOWN)
        _nextDir = Dir::DIR_UP;
    else if (cmd == CommandType::DOWN && _dir != Dir::DIR_UP)
        _nextDir = Dir::DIR_DOWN;
    else if (cmd == CommandType::R)
        remake();
}

void Arcade::Snake::update(double timeElapsed)
{
    _dt += timeElapsed;
    if (_dt >= double(1.0f / (5.0f + 0.1f * _score)) && !_lose) {
        _dir = _nextDir;
        _dt = 0;
        int baseX = _snake.front()->getXPos();
        int baseY = _snake.front()->getYPos();
        Pixel *tmp;
        if (_toAdd)
            tmp = new Pixel(_snake.back()->getXPos(), _snake.back()->getYPos(), Arcade::Color::GREEN, 2);
        for (size_t x = _snake.size() - 1; x > 0; x--) {
            _snake[x]->setXPos(_snake[x - 1]->getXPos());
            _snake[x]->setYPos(_snake[x - 1]->getYPos());
        }
        if (_toAdd) {
            _snake.push_back(tmp);
            _toAdd = false;
        }
        if (_dir == Dir::DIR_RIGHT)
            _snake.front()->setXPos(baseX + 2);
        else if (_dir == Dir::DIR_LEFT)
            _snake.front()->setXPos(baseX - 2);
        else if (_dir == Dir::DIR_UP)
            _snake.front()->setYPos(baseY - 2);
        else if (_dir == Dir::DIR_DOWN)
            _snake.front()->setYPos(baseY + 2);
        checkApple();
        checkEnd();
    }
}

void Arcade::Snake::checkEnd()
{
    if (_snake.front()->getXPos() < 14 || _snake.front()->getXPos() > 86 
        || _snake.front()->getYPos() < 24 || _snake.front()->getYPos() > 96)
        _lose = true;
    for (auto it = _snake.begin() + 1; it != _snake.end(); it++) {
        if (_snake.front()->getXPos()  == (*it)->getXPos() && _snake.front()->getYPos() == (*it)->getYPos())
            _lose = true;
    }
}

bool Arcade::Snake::checkCoor(int x, int y)
{
    for (auto it = _snake.begin(); it != _snake.end(); it++) {
        if (x == (*it)->getXPos() && y == (*it)->getYPos())
            return false;
    }
    return true;
}

void Arcade::Snake::checkApple()
{
    int x;
    int y;

    srand((unsigned)time(0)); 
    if (_snake.front()->getXPos() == _apple->getXPos() && _snake.front()->getYPos() == _apple->getYPos()) {
        do {
            x = (rand() % 73 ) + 14;
            y = (rand() % 73) + 24;
            if (x % 2 != 0) {
                if (x < 86)
                    x++;
                else
                    x--;
            }
            if (y % 2 != 0) {
                if (y < 86)
                    y++;
                else
                    y--;
            }
        } while (!checkCoor(x, y));
        _apple->setXPos(x);
        _apple->setYPos(y);
        _toAdd = true;
        _score += 1;
        _scoreText->setStr("score : " + std::to_string(_score));
    }
}

void Arcade::Snake::remake()
{
    _dt = 0.0f;
    _score = 0;
    _lose = false;
    _dir = Dir::DIR_RIGHT;
    _nextDir = Dir::DIR_RIGHT;
    _scoreText->setStr("score : " + std::to_string(_score));
    _snake.clear();
    _snake.push_back(new Pixel(52, 50, Arcade::MAGENTA, 2));
    _snake.push_back(new Pixel(50, 50, Arcade::GREEN, 2));
    _snake.push_back(new Pixel(48, 50, Arcade::GREEN, 2));
    _snake.push_back(new Pixel(46, 50, Arcade::GREEN, 2));
}