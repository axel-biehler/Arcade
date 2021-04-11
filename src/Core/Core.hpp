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
#include <map>
#include "../../includes/IGraphic.hpp"
#include "../../includes/IGame.hpp"
#include "../../includes/PersonnalType.hpp"
#include "../utils/LibLoader/LibLoader.hpp"
#include "../utils/Text/Text.hpp"
#include "../utils/Pixel/Pixel.hpp"
#include "../../includes/IMenu.hpp"

namespace Arcade {
    class Core {
    public:
        Core();
        ~Core();
        void setGraphicLib(IGraphic *lib);
        void setGameLib(IGame *lib);
        IGraphic *getGraphicLib() const;
        IGame *getGameLib() const;
        void switchLib(LibLoader &loader, CommandType event);
        bool runGame(LibLoader &loader, std::string &playerName);
        std::string playerNameLoop(Arcade::LibLoader &loader, Arcade::IMenu *menu);
        void storeScore(const std::string game, const std::string playerName, int score);
        std::vector<std::vector<std::string>> getScores() const;
        void deleteLibs();
        const std::string &get_game_name() const;
        void set_game_name(const std::string &game_name);
    private:
        IGraphic *_graphicLib;
        IGame *_gameLib;
        std::string _gameName;
        std::map<CommandType, int> Core_KEY {
            {A, 'a'},
            {B, 'b'},
            {C, 'c'},
            {D, 'd'},
            {E, 'e'},
            {F, 'f'},
            {G, 'g'},
            {H, 'h'},
            {I, 'i'},
            {J, 'j'},
            {K, 'k'},
            {L, 'l'},
            {M, 'm'},
            {N, 'n'},
            {O, 'o'},
            {P, 'p'},
            {Q, 'q'},
            {R, 'r'},
            {S, 's'},
            {T, 't'},
            {U, 'u'},
            {V, 'v'},
            {W, 'w'},
            {X, 'x'},
            {Y, 'y'},
            {Z, 'z'},
            {NUM0, '0'},
            {NUM1, '1'},
            {NUM2, '2'},
            {NUM3, '3'},
            {NUM4, '4'},
            {NUM5, '5'},
            {NUM6, '6'},
            {NUM7, '7'},
            {NUM8, '8'},
            {NUM9, '9'},
            {SPACE, ' '},
        };
    };
}


#endif //B_OOP_400_STG_4_1_ARCADE_MAXIME_FRECHARD_CORE_HPP
