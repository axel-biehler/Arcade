/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include "Core.hpp"

Arcade::Core::Core()
{
    _graphicLib = nullptr;
    _gameLib = nullptr;
}

Arcade::Core::~Core()
{
}

void Arcade::Core::setGraphicLib(Arcade::IGraphic *lib)
{
    _graphicLib = lib;
}

void Arcade::Core::setGameLib(Arcade::IGame *game_lib)
{
    _gameLib = game_lib;
}

Arcade::IGraphic *Arcade::Core::getGraphicLib() const
{
    return _graphicLib;
}

Arcade::IGame *Arcade::Core::getGameLib() const
{
    return _gameLib;
}
/*
static void delete_lib(Arcade::IGraphic *toDelete)
{
    if (dynamic_cast<Arcade::libSFML *>(toDelete))
        delete (Arcade::libSFML *)toDelete;
    else if (dynamic_cast<Arcade::LibSDL *>(toDelete))
        delete (Arcade::LibSDL *)toDelete;
}
*/
void Arcade::Core::switchLib(Arcade::LibLoader &loader, Arcade::CommandType event)
{
    Arcade::CommandType libEvent[] = {
        Arcade::NUM0,
        Arcade::NUM1,
        Arcade::NUM2,
        Arcade::NUM3
    };

    if (std::find(libEvent, libEvent + 4, event) == libEvent + 4)
        return;
    if (event == Arcade::CommandType::NUM0) {
        delete _graphicLib;
       // delete_lib(_graphicLib);
        this->setGraphicLib(loader.loadNextGraphics());
    }
}
