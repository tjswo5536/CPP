#include "game.hpp"

Game::Game(int diff) : stage(diff), mission(diff) {}

void Game::newGame() {
    clear();
    screen.display(stage);
    screen.display(snake);
    screen.display(score);
    screen.display(mission);

    while(!gameOver && !gameClear) {
        manageItem();
        manageGate();

        setDirection();
        snake.setDirecion(direction);
        snake.move();

        checkCurrentStatus();
        screen.display(snake);

        checkRules();
        checkMissionClear();
        checkGameClear();

        napms(200);
    }
}

void Game::manageItem() {
    if(itemTimer++ >= 25) {
        itemTimer = 0;
        item.deleteItem(stage);
        item.createItem(stage, snake);
        screen.display(item);
    }
}

void Game::manageGate() {
    if((gateTimer++ >= 40) && !(snake.isInSnake(gate.getGateA()) ||
                                snake.isInSnake(gate.getGateB()))) {
        gateTimer = 0;
        gate.deleteGate(stage);
        screen.display(stage);

        gate.createGate(stage);
        screen.display(gate);
    }
}

void Game::setDirection() {
    key = getch();
    
    switch(key) {
        case KEY_UP:
            if(direction != KEY_DOWN)
                direction = key;
            break;
        case KEY_DOWN:
            if(direction != KEY_UP)
                direction = key;
            break;
        case KEY_LEFT:
            if(direction != KEY_RIGHT)
                direction = key;
            break;
        case KEY_RIGHT:
            if(direction != KEY_LEFT)
                direction = key;
            break;
    }
}

void Game::checkCurrentStatus() {
    switch(stage.getStageInfo(snake.getHead())) {
    case 1:
        snake.growTail();
        score.setScore(0, snake.getSize());
        score.setScore(1, snake.getSize());
        score.setScore(2);
        screen.display(score);
        break;

    case 2:
        snake.removeTail();
        score.setScore(0, snake.getSize());
        score.setScore(3);
        screen.display(score);
        break;
    
    case 5:
        snake.enterTheGate(gate.getGateA(), gate.getGateB(), stage);
        direction = snake.getDirection();
        snake.move(gate.getGateB());
        score.setScore(4);
        screen.display(score);
        break;
    
    case 6:
        snake.enterTheGate(gate.getGateB(), gate.getGateA(), stage);
        direction = snake.getDirection();
        snake.move(gate.getGateA());
        score.setScore(4);
        screen.display(score);
        break;
    }
}

void Game::checkRules() {
    if(stage.getStageInfo(snake.getHead()) == 3)
        gameOver = true;
    else if(snake.getSize() < 3)
        gameOver = true;
    else if(snake.headCrash())
        gameOver = true;
}

void Game::checkMissionClear() {
    for(int index = 0; index < 4; index++) {
        if(score.getScore(index + 1) == mission.getCurrentMission(index)) {
            mission.setMissionClear(index);
            screen.display(mission);
        }
    }
}

void Game::checkGameClear() {
    if(mission.isMissionAllClear())
        gameClear = true;
}

bool Game::getGameOver() const {
    return gameOver;
}

bool Game::getGameClear() const {
    return gameClear;
}