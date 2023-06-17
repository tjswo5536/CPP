#ifndef GAME_H
#define GAME_H

#include "screen.hpp"

class Game {
public:
    Game(int diff);

    void newGame();

    void manageItem();
    void manageGate();
    void setDirection();

    void checkCurrentStatus();
    void checkRules();
    void checkMissionClear();
    void checkGameClear();

    bool getGameOver() const;
    bool getGameClear() const;

private:
    Gate gate;
    Item item;
    Snake snake;
    Stage stage;
    Score score;
    Screen screen;
    Mission mission;

    int key;
    int itemTimer = 20;
    int gateTimer = 25;
    int direction = KEY_LEFT;
    bool gameOver = false;
    bool gameClear = false;
};

#endif /* GAME_H */