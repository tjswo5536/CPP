#include "snake.hpp"

Snake::Snake() {
    head = Point(10, 9);
    snake.push_back(head);
    
    snake.push_back(Point(10, 10));

    tail = Point(10, 11);
    trail = tail;
    snake.push_back(tail);
}

Point Snake::getHead() const {
    return head;
}

Point Snake::getBody(int index) const {
    return snake[index];
}

int Snake::getSize() const {
    return snake.size();
}

bool Snake::isInSnake(const Point& pos) {
    for(unsigned int body = 0; body < snake.size(); body++) {
        if(snake[body] == pos)
            return true;
    }
    return false;
}

bool Snake::headCrash() {
    for(unsigned int body = 1; body < snake.size(); body++) {
        if(snake[body] == head)
            return true;
    }
    return false;
}

void Snake::growTail() {
    snake.push_back(trail);
    tail = trail;
}

void Snake::removeTail() {
    mvaddch(tail.getY() + 2, tail.getX() + 2, ' ');

    trail = tail;
    snake.pop_back();
    tail = snake.back();
}

void Snake::setDirecion(int direc) {
    direction = direc;
    switch(direc) {
        case KEY_UP:
            dy = -1; dx = 0;
            break;
        case KEY_DOWN:
            dy = 1; dx = 0;
            break;
        case KEY_LEFT:
            dy = 0; dx = -1;
            break;
        case KEY_RIGHT:
            dy = 0; dx = 1;
            break;
    }
}

int Snake::getDirection() const {
    return direction;
}

void Snake::move() {
    head = Point(head.getY() + dy, head.getX() + dx);
    snake.push_front(head);
    removeTail();
}

void Snake::move(const Point& pos) {
    head = Point(pos.getY() + dy, pos.getX() + dx);
    snake.push_front(head);
    snake.erase(snake.begin() + 1);
}

void Snake::enterTheGate(const Point& inGate, const Point& outGate, const Stage& stage) {
    if(outGate.getY() == 0) setDirecion(KEY_DOWN);
    else if(outGate.getY() == 20) setDirecion(KEY_UP);
    else if(outGate.getX() == 0) setDirecion(KEY_RIGHT);
    else if(outGate.getX() == 20) setDirecion(KEY_LEFT);
    else if((inGate.getY() > 0 && inGate.getY() < 21) && (inGate.getX() > 0 && inGate.getX() < 21)) {
        if(stage.getStageInfo(outGate.getY() - 1, outGate.getX()) >= 3 &&
           stage.getStageInfo(outGate.getY() + 1, outGate.getX()) >= 3) {
            switch(direction) {
            case KEY_DOWN: case KEY_LEFT:
                setDirecion(KEY_LEFT);
                break;
            case KEY_UP: case KEY_RIGHT:
                setDirecion(KEY_RIGHT);
                break;
            }
        }
        else if(stage.getStageInfo(outGate.getY(), outGate.getX() - 1) >= 3 &&
                stage.getStageInfo(outGate.getY(), outGate.getX() + 1) >= 3) {
            switch(direction) {
            case KEY_UP: case KEY_LEFT:
                setDirecion(KEY_UP);
                break;
            case KEY_DOWN: case KEY_RIGHT:
                setDirecion(KEY_DOWN);
                break;
            }
        }
    }
}