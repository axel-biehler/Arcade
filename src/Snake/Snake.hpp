/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-maxime.frechard
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <string>
#include <vector>
#include "../../includes/IGame.hpp"
#include "../../includes/IGraphic.hpp"

namespace Arcade {
    class Snake : public IGame {
        public:
            Snake();
            virtual ~Snake();

        void initPlayerName(std::string playerName) override;
        void draw(IGraphic *lib) override;
        void getEvent(CommandType cmd, IGraphic *lib) override;
        void update(double timeElapsed) override;

        private:
            std::string _playerName;
    };
}

#endif /* SNAKE_HPP_ */
