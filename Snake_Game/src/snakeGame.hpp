#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "game.hpp"
#include <istream>

class SnakeGame {
public:
    SnakeGame();

    void startGame();
    
    void displayGameOver();
    void displayGameClear();
    void displayStageClear();

private:
    Game* player;
    int difficulty = 1;

    WINDOW* gameOverScreen;
    WINDOW* gameClearScreen;
    WINDOW* stageClearScreen;
};

#endif /* SNAKEGAME_H */