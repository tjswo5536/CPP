#ifndef SNAKE_H
#define SNAKE_H

#include "stage.hpp"
#include <ncurses.h>
#include <deque>

class Snake {
public:
    Snake();

    Point getHead() const;
    Point getBody(int index) const;
    
    int getSize() const;

    bool isInSnake(const Point& pos);
    bool headCrash();

    void growTail();
    void removeTail();

    void setDirecion(int direc);
    int getDirection() const;

    void move();
    void move(const Point& pos);
    void enterTheGate(const Point& inGate, const Point& outGate, const Stage& stage);

private:
    std::deque<Point> snake;
    Point head, tail, trail;

    int direction;
    int dy, dx;
};

#endif /* SNAKE_H */