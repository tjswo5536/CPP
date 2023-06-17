#include "snakeGame.hpp"

SnakeGame::SnakeGame() {
    // GAME OVER
    gameOverScreen = newwin(12, 30, 6, 5);

    // GAME CLEAR
    gameClearScreen = newwin(12, 30, 6, 5);
    
    // STAGE CLEAR
    stageClearScreen = newwin(12, 30, 6, 5);

    std::string title[] = {
            "  _____  _   _            _   __  _____ ", 
            " / ____|| \\ | |    /\\    | | / / |  ___|", 
            "| (___  |  \\| |   /  \\   | |/ /  | |__  ", 
            " \\___ \\ |     |  / /\\ \\  |   |   |  __|  ", 
            " ____) || |\\  | / ____ \\ | |\\ \\  | |___ ",  
            "|_____/ |_| \\_|/_/    \\_\\|_| \\_\\ |_____|", 
            "    _____            _       _  _____",
            "   / ____|    /\\    | \\     / ||  ___|",
            "  | |  __    /  \\   |  \\   /  || |__", 
            "  | | |_ |  / /\\ \\  |   \\_/   ||  __|", 
            "  | |__| | / ____ \\ | |\\   /| || |___", 
            "   \\_____//_/    \\_\\|_| \\_/ |_||_____|"};

    attron(A_BOLD);
    for(int line = 0; line < 12; line++)
        mvprintw(line, 0, "%s", title[line].data());
    attroff(A_BOLD);

    attron(A_BLINK);
    mvprintw(18, 6, "PRESS ANY KEY TO START GAME!");
    attroff(A_BLINK);
    refresh();
    getch();

    nodelay(stdscr, TRUE);
    player = new Game(difficulty);
}

void SnakeGame::startGame() {
    while(difficulty <= 4) {
        player->newGame();

        if(player->getGameOver()) {
            displayGameOver();
            delete player;
            break;
        }
        else if(difficulty == 4) {
            displayGameClear();
            delete player;
            break;
        }
        else {
            displayStageClear();
            delete player;
            difficulty++;
            player = new Game(difficulty);
        }
    }
}

void SnakeGame::displayGameOver() {
    box(gameOverScreen, 0, 0);

    wattron(gameOverScreen, A_BOLD);
    mvwprintw(gameOverScreen, 4, 10, "GAME  OVER");
    wattroff(gameOverScreen, A_BOLD);

    wattron(gameOverScreen, A_BLINK);
    mvwprintw(gameOverScreen, 7, 3, "PRESS ANY KEY TO EXIT...");
    wattroff(gameOverScreen, A_BLINK);

    wrefresh(gameOverScreen);
    wgetch(gameOverScreen);
}

void SnakeGame::displayGameClear() {
    box(gameClearScreen, 0, 0);

    wattron(gameClearScreen, A_BOLD);
    mvwprintw(gameClearScreen, 4, 9, "GAME CLEAR!");
    mvwprintw(gameClearScreen, 6, 7, "CONGRATULATION!");
    wattroff(gameClearScreen, A_BOLD);

    wattron(gameClearScreen, A_BLINK);
    mvwprintw(gameClearScreen, 9, 3, "PRESS ANY KEY TO EXIT...");
    wattroff(gameClearScreen, A_BLINK);

    wrefresh(gameClearScreen);
    wgetch(gameClearScreen);
}

void SnakeGame::displayStageClear() {
    box(stageClearScreen, 0, 0);

    wattron(stageClearScreen, A_BOLD);
    mvwprintw(stageClearScreen, 4, 8, "%s""%d""%s", "STAGE:", difficulty, " CLEAR");
    wattroff(stageClearScreen, A_BOLD);

    wattron(stageClearScreen, A_BLINK);
    mvwprintw(stageClearScreen, 7, 1, "PRESS ANY KEY TO CONTINUE...");
    wattroff(stageClearScreen, A_BLINK);

    wrefresh(stageClearScreen);
    wgetch(stageClearScreen);
}