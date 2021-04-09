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
            CommandType getEvent(CommandType cmd, IGraphic *lib) override;
            void update(double timeElapsed) override;
            void remake() override;
            void initPlayerName(std::string playerName) override;
            std::vector<std::string> getMap(const std::string &path);
            std::vector<PacmanGame::Ghost> createGhost();
            void drawGhost(Arcade::IGraphic *lib);

        private:
            std::vector<std::string> _map;
            std::vector<PacmanGame::Ghost> _ghosts;
            PacmanGame::Character _pacman;
            std::string _name;
            double _time;
    };
}

#endif /* !PACMAN_HPP_ */
