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

    enum Dir {
        DIR_LEFT,
        DIR_RIGHT,
        DIR_UP,
        DIR_DOWN
    };

    class Snake : public IGame {
        public:
            Snake();
            virtual ~Snake();

            void initPlayerName(std::string playerName) override;
            void draw(IGraphic *lib) override;
            void getEvent(CommandType cmd, IGraphic *lib) override;
            void update(double timeElapsed) override;

            void checkApple();
            bool checkCoor(int x, int y);
            void checkEnd();
            void remake();

        private:
            std::string _playerName;
            std::vector<Pixel *> _snake;
            Pixel *_bg;
            Pixel *_map;
            bool _toAdd;
            Pixel *_apple;
            int _score;
            Text *_scoreText;
            Text *_name;
            Text *_title;
            double _dt;
            Dir _dir;
            Dir _nextDir;
            bool _lose;
    };
}

#endif /* SNAKE_HPP_ */
