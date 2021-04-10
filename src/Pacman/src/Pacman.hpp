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
#include "IGame.hpp"

namespace Arcade {
    class Pacman : public IGame{
        public:
            Pacman();
            virtual ~Pacman();

            void draw() override;
            void getEvent() override;
            void update(double timeElapsed) override;
            void remake() override;
            std::vector<std::string> getMap(const std::string &path);

        private:
            std::vector<std::string> _map;
    };
}

#endif /* !PACMAN_HPP_ */
