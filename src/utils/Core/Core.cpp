/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#include <experimental/filesystem>
#include "Core.hpp"

Arcade::Core::Core()
{
}

Arcade::Core::~Core()
{
}

void Arcade::Core::loadLibs(const std::string &path)
{
    Arcade::LibLoader loader;
    std::string name;

    for (auto& p: std::experimental::filesystem::directory_iterator(path)) {
        if (p.path().string().find(".so", 0) != std::string::npos) {
            loader.loadSharedLib(p.path().string());
            if (loader.getType() == Arcade::GAME) {
                _gameLibs.push_back(loader.getLibGame());
                name = p.path().string().substr(p.path().string().find('_', 0));
                name = name.substr(0, name.find('.'));
                _gameLibsNames.push_back(name);
            }
            else if (loader.getType() == Arcade::GRAPHIC)
                _graphicLibs.push_back(loader.getLibGraphic());
                name = p.path().string().substr(p.path().string().find('_', 0));
                name = name.substr(0, name.find('.'));
            _graphicLibsNames.push_back(name);
        }
    }
}

std::vector<Arcade::IGraphic *> Arcade::Core::getGraphicLibs() const
{
    return _graphicLibs;
}

std::vector<std::string> Arcade::Core::getGraphicLibsNames() const
{
    return _graphicLibsNames;
}

std::vector<Arcade::IGame *> Arcade::Core::getGameLibs() const
{
    return _gameLibs;
}

std::vector<std::string> Arcade::Core::getGameLibsNames() const
{
    return _gameLibsNames;
}