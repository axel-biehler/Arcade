//
// Created by jeanningros on 3/22/21.
//

#include "Text.hpp"

extern "C" Arcade::Text::Text(int xPos, int yPos, const std::string &str, Color color, int size) :  _xPos(xPos), _yPos(yPos) {
    _size = size;
    _str = str;
    _highlight = false;
    _color = color;
}

extern "C" Arcade::Text::~Text() {
}

extern "C" bool Arcade::Text::getHighlight() const {
    return _highlight;
}

extern "C" void Arcade::Text::setHighlight(bool highlight) {
    _highlight = highlight;
}

extern "C" int Arcade::Text::getXPos() const {
    return _xPos;
}

extern "C" void Arcade::Text::setXPos(int xPos) {
    _xPos = xPos;
}

extern "C" int Arcade::Text::getYPos() const {
    return _yPos;
}

extern "C" void Arcade::Text::setYPos(int yPos) {
    _yPos = yPos;
}

extern "C" int Arcade::Text::getSize() const {
    return _size;
}

extern "C" void Arcade::Text::setSize(int size) {
    _size = size;
}

extern "C" const std::string &Arcade::Text::getStr() const {
    return _str;
}

extern "C" void Arcade::Text::setStr(const std::string &str) {
    _str = str;
}

extern "C" Arcade::Color Arcade::Text::getColor() const {
    return _color;
}

extern "C" void Arcade::Text::setColor(Arcade::Color color) {
    _color = color;
}
