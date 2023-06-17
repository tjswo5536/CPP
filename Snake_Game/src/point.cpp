#include "point.hpp"

Point::Point(int y, int x) : y(y), x(x) {}

Point::Point(const Point& pos) : y(pos.y), x(pos.x) {}

Point& Point::operator=(const Point& pos) {
    this->y = pos.y;
    this->x = pos.x;
    return *this;
}

bool Point::operator==(const Point& pos) {
    return (y == pos.y) && (x == pos.x);
}

int Point::getY() const {
    return y;
}

int Point::getX() const {
    return x;
}