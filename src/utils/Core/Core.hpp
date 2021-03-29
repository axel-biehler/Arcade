/*
** EPITECH PROJECT, 2021
** B_OOP_400_STG_4_1_arcade_maxime_frechard
** File description:
** Created by arthur,
*/

#ifndef B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP
#define B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP

#include <string>
#include <vector>
#include "../../../includes/IGraphic.hpp"
#include "../../../includes/IGame.hpp"
#include "../../../includes/PersonnalType.hpp"
#include "../../LibLoader/LibLoader.hpp"

namespace Arcade {
    class Core {
    public:
        Core();
        ~Core();
        void loadLibs(std::string const &path);
        std::vector<IGraphic *> getGraphicLibs() const;
        std::vector<std::string> getGraphicLibsNames() const;
        std::vector<IGame *> getGameLibs() const;
        std::vector<std::string> getGameLibsNames() const;

    private:
        std::vector<IGraphic *> _graphicLibs;
        std::vector<std::string> _graphicLibsNames;
        std::vector<IGame *> _gameLibs;
        std::vector<std::string> _gameLibsNames;
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP
