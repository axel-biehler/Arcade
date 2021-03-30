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
#include "../../includes/IGame.hpp"
#include "../../includes/IGraphic.hpp"
#include "../../includes/PersonnalType.hpp"
#include <vector>
#include <math.h>

namespace Arcade {
    class LibLoader {
    public:
        LibLoader();
        virtual ~LibLoader();

        template<typename T>
        T *loadSharedLib(std::string const &fp, T *)
        {
            void *sharedLib = dlopen(fp.c_str(), RTLD_LAZY);
            T *(*getLib)();

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
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_LIBLOADER_HPP
