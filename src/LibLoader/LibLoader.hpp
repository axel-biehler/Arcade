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

namespace Arcade {
    class LibLoader {
    public:
        LibLoader();
        virtual ~LibLoader();
        void loadSharedLib(std::string const &fp);
        IGame *getLibGame() const;
        IGraphic *getLibGraphic() const;
        LibType getType() const;

    private:
        LibType _type;
        IGame *_libGame;
        IGraphic *_libGraphic;
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_NICOLAS_SCHNEIDER_LIBLOADER_HPP
