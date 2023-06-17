#ifndef SCREEN_H
#define SCREEN_H

#include "gate.hpp"
#include "item.hpp"
#include "mission.hpp"
#include "score.hpp"

class Screen {
public:
    Screen();

    void initColor();

    void display(const Gate& gate);
    void display(const Item& item);
    void display(const Mission& mission);
    void display(const Score& score);
    void display(const Snake& snake);
    void display(const Stage& stage);

private:
    enum colors {RED = 1, GREEN = 2, BLUE = 3, MAGENTA = 4, WHITE = 5};
    
    WINDOW* scoreBoard;
    WINDOW* missionBoard;
};

#endif /* SCREEN_H */