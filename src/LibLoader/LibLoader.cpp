/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Library loader
*/

#include "LibLoader.hpp"

Arcade::LibLoader::LibLoader() {
    _libGame = nullptr;
    _libGraphic = nullptr;
}

Arcade::LibLoader::~LibLoader() {
}

void Arcade::LibLoader::loadSharedLib(const std::string &fp)
{
    void *sharedLib = dlopen(fp.c_str(), RTLD_LAZY);
    LibType (*getLibType)();
    IGame *(*getLibGame)();
    IGraphic *(*getLibGraphic)();

    if (sharedLib) {
        getLibType = reinterpret_cast<LibType (*)()>(dlsym(sharedLib, "getLibType"));
        if (getLibType() == GRAPHIC) {
            getLibGraphic = reinterpret_cast<IGraphic * (*)()>(dlsym(sharedLib, "getLibGraphic"));
            _type = getLibType();
            _libGraphic = getLibGraphic();
        }
        if (getLibType() == GAME) {
            getLibGame = reinterpret_cast<IGame * (*)()>(dlsym(sharedLib, "getLibGame"));
            _type = getLibType();
            _libGame = getLibGame();

        }
    }
    else {
        std::cout << "dlopen failed: "<< dlerror() << std::endl;
    }
}

Arcade::IGame *Arcade::LibLoader::getLibGame() const {
    return _libGame;
}

Arcade::IGraphic *Arcade::LibLoader::getLibGraphic() const {
    return _libGraphic;
}

Arcade::LibType Arcade::LibLoader::getType() const {
    return _type;
}
