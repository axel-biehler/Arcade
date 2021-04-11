/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <string>
#include <vector>
#include "../../../includes/IGame.hpp"
#include "Character.hpp"
#include "Ghost.hpp"

namespace Arcade {
    class Pacman : public IGame{
        public:
            Pacman();
            virtual ~Pacman();

            void draw(IGraphic *lib) override;
            void getEvent(CommandType cmd, IGraphic *lib) override;
            void update(double timeElapsed) override;
            void initPlayerName(std::string playerName) override;

            void moveGhost(double timeElapsed);
            std::vector<std::string> getMap(const std::string &path);
            void createGhost();
            void drawGhost(Arcade::IGraphic *lib);
            void check_win();
            void remake();

        private:
            std::vector<std::string> _map;
            std::vector<PacmanGame::Ghost> _ghosts;
            PacmanGame::Character _pacman;
            std::string _name;
            int _score;
            double _time;
            PacmanGame::dir _nextDir;
            PacmanGame::dir _dir;
    };
}

#endif /* !PACMAN_HPP_ */
