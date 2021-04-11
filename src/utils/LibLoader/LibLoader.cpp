/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Library loader
*/

#include <experimental/filesystem>
#include "LibLoader.hpp"

Arcade::LibLoader::LibLoader(): _loadedMenu(nullptr),
                                _loadedGraphics(nullptr),
                                _loadedGame(nullptr)
{
}

Arcade::LibLoader::~LibLoader()
{
    if (_loadedMenu)
        dlclose(_loadedMenu);
    if (_loadedGraphics)
        dlclose(_loadedGraphics);
    if (_loadedGame)
        dlclose(_loadedGame);
}

std::vector<std::pair<std::string, std::string>> Arcade::LibLoader::getLibAvailable(Arcade::LibType type)
{
    std::string name;
    std::vector<std::pair<std::string, std::string>> libs = std::vector<std::pair<std::string, std::string>>();
    LibType (*getLibType)();

    for (auto& p: std::experimental::filesystem::directory_iterator("./lib")) {
        void *sharedLib = dlopen(p.path().c_str(), RTLD_NOW);
        if (sharedLib) {
            getLibType = reinterpret_cast<LibType (*)()>(dlsym(sharedLib, "getLibType"));
            if (getLibType() == type && p.path().string().find(".so", 0) != std::string::npos) {
                std::pair<std::string, std::string> pathName;
                pathName.second = p.path().string();
                name = p.path().string().substr(p.path().string().find('_', 0) + 1);
                pathName.first = name.substr(0, name.find('.'));
                libs.push_back(pathName);
            }
            dlclose(sharedLib);
        }
    }
    return libs;
}

std::string Arcade::LibLoader::getNameLib(std::basic_string<char> fp)
{
    if (fp.find(".so", 0) != std::string::npos) {
        std::string name = fp.substr(fp.find('_', 0));
        name = name.substr(0, name.find('.'));
        return name;
    }
    return std::string();
}

Arcade::IGraphic *Arcade::LibLoader::loadNextGraphics(bool direction)
{
    std::string toLoad;
    std::vector<std::pair<std::string, std::string>> libs = getLibAvailable(Arcade::GRAPHIC);
    std::string name = _loadedGraphicsName;
    auto it = std::find_if(libs.begin(), libs.end(),
                        [&name](const std::pair<std::string, std::string>& element){ return element.second.find(name) != std::string::npos; });

    if (libs.empty() || it == libs.end()) {
        std::cout << "Failed to swap lib" << "it = " << it->first << std::endl;
        std::_Exit(0);
    }
    if (it - libs.begin() == libs.size() - 1 && direction)
        toLoad = libs[0].second;
    else if (direction)
        toLoad = (*(it + 1)).second;
    if (it - libs.begin() == 0 && !direction)
        toLoad = libs[libs.size() - 1].second;
    else if (!direction)
        toLoad = (*(it - 1)).second;
    return loadSharedLib<IGraphic>(toLoad, Arcade::GRAPHIC);
}

Arcade::IGame *Arcade::LibLoader::loadNextGame(bool direction)
{
    std::string toLoad;
    std::vector<std::pair<std::string, std::string>> libs = getLibAvailable(Arcade::GAME);
    std::string name = _loadedGameName;
    auto it = std::find_if(libs.begin(), libs.end(),
                           [&name](const std::pair<std::string, std::string>& element){ return element.second == name; });

    if (libs.empty() || it == libs.end()) {
        std::cout << "Failed to swap lib" << "it = " << it->first << std::endl;
        std::_Exit(0);
    }
    if (it - libs.begin() == libs.size() - 1 && direction)
        toLoad = libs[0].second;
    else if (direction)
        toLoad = (*(it + 1)).second;
    if (it - libs.begin() == 0 && !direction)
        toLoad = libs[libs.size() - 1].second;
    else if (!direction)
        toLoad = (*(it - 1)).second;
    return loadSharedLib<IGame>(toLoad, Arcade::GAME);
}

void Arcade::LibLoader::unloadAll()
{
    if (_loadedGame)
        dlclose(_loadedGame);
    if (_loadedGraphics)
        dlclose(_loadedGraphics);
    if (_loadedMenu)
        dlclose(_loadedMenu);
}
