#include "screen.hpp"

Screen::Screen() {
    initColor();
    
    scoreBoard = newwin(10, 13, 2, 25);
    box(scoreBoard, 0, 0);

    missionBoard = newwin(10, 13, 13, 25);
    box(missionBoard, 0, 0);
}

void Screen::initColor() {
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
}

void Screen::display(const Gate& gate) {
    attron(COLOR_PAIR(MAGENTA));
    mvaddch(gate.getGateA().getY() + 2, gate.getGateA().getX() + 2, 'A');
    mvaddch(gate.getGateB().getY() + 2, gate.getGateB().getX() + 2, 'B');
    attroff(COLOR_PAIR(MAGENTA));
}

void Screen::display(const Item& item) {
    attron(COLOR_PAIR(GREEN));
    mvaddch(item.getGrowthItem().getY() + 2, item.getGrowthItem().getX() + 2, '@');
    attroff(COLOR_PAIR(GREEN));

    attron(COLOR_PAIR(RED));
    mvaddch(item.getPoisonItem().getY() + 2, item.getPoisonItem().getX() + 2, '!');
    attroff(COLOR_PAIR(RED));
}

void Screen::display(const Mission& mission) {
    mvwprintw(missionBoard, 2, 3, "Mission");
    mvwprintw(missionBoard, 4, 3, "B :%2d (%c)", mission.getCurrentMission(0), mission.getMissionClear(0));
    mvwprintw(missionBoard, 5, 3, "+ :%2d (%c)", mission.getCurrentMission(1), mission.getMissionClear(1));
    mvwprintw(missionBoard, 6, 3, "- :%2d (%c)", mission.getCurrentMission(2), mission.getMissionClear(2));
    mvwprintw(missionBoard, 7, 3, "G :%2d (%c)", mission.getCurrentMission(3), mission.getMissionClear(3));
    wrefresh(missionBoard);
}

void Screen::display(const Score& score) {
    mvwprintw(scoreBoard, 2, 1, "Score Board");
    mvwprintw(scoreBoard, 4, 3, "B :%2d/%d", score.getScore(0), score.getScore(1));
    mvwprintw(scoreBoard, 5, 3, "+ :%2d", score.getScore(2));
    mvwprintw(scoreBoard, 6, 3, "- :%2d", score.getScore(3));
    mvwprintw(scoreBoard, 7, 3, "G :%2d", score.getScore(4));
    wrefresh(scoreBoard);
}

void Screen::display(const Snake& snake) {
    attron(COLOR_PAIR(BLUE));
    for(int body = 0; body < snake.getSize(); body++)
        mvaddch(snake.getBody(body).getY() + 2, snake.getBody(body).getX() + 2, '$');
    attroff(COLOR_PAIR(BLUE));
    refresh();
}

void Screen::display(const Stage& stage) {
    attron(COLOR_PAIR(WHITE));
    for(int y = 0; y < 21; y++) {
        for(int x = 0; x < 21; x++) {
            if(stage.getStageInfo(y, x) >= 3)
                mvaddch(y + 2, x + 2, '#');
        }
    }
    attroff(COLOR_PAIR(WHITE));
    refresh();
}