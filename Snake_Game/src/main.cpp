#include "snakeGame.hpp"

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    SnakeGame game;
    game.startGame();

    endwin();
    
    return 0;
}