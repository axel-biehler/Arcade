/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Library loader header
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_LIBLOADER_HPP
#define B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_LIBLOADER_HPP

#include <iostream>
#include <dlfcn.h>
#include "../../../includes/IGame.hpp"
#include "../../../includes/IGraphic.hpp"
#include "../../../includes/PersonnalType.hpp"
#include <vector>
#include <math.h>

namespace Arcade {
    class LibLoader {
    public:
        LibLoader();
        virtual ~LibLoader();

        template<typename T>
        T *loadSharedLib(std::string const &fp, LibType type)
        {
            void *sharedLib = dlopen(fp.c_str(), RTLD_NOW);
            T *(*getLib)();

            if (type == MENU) {
                if (_loadedMenu)
                    dlclose(_loadedMenu);
                _loadedMenu = dlopen(fp.c_str(), RTLD_NOW);
                sharedLib = _loadedMenu;
            } else if (type == GRAPHIC) {
                if (_loadedGraphics)
                    dlclose(_loadedGraphics);
                _loadedGraphics = dlopen(fp.c_str(), RTLD_NOW);
                _loadedGraphicsName = std::string(fp);
                sharedLib = _loadedGraphics;
            } else if (type == GAME) {
                if (_loadedGame)
                    dlclose(_loadedGame);
                _loadedGame = dlopen(fp.c_str(), RTLD_NOW);
                _loadedGameName = std::string(fp);
                sharedLib = _loadedGame;
            }
            if (sharedLib) {
                getLib = reinterpret_cast<T * (*)()>(dlsym(sharedLib, "getLib"));
                return getLib();
            }
            else {
                std::cout << "dlopen failed: "<< dlerror() << std::endl;
                return nullptr;
            }
        }
        std::vector<std::pair<std::string, std::string>> getLibAvailable(Arcade::LibType);
        std::string getNameLib(std::string &fp);
        IGraphic *loadNextGraphics(bool direction);
        IGame *loadNextGame(bool direction);
        void unloadAll();
    private:
        void *_loadedMenu;
        void *_loadedGraphics;
        std::string _loadedGraphicsName;
        void *_loadedGame;
        std::string _loadedGameName;
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_LIBLOADER_HPP
