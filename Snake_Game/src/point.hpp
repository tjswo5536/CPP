#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(int y = 0, int x = 0);
    Point(const Point& pos);

    Point& operator=(const Point& pos);
    bool operator==(const Point& pos);

    int getY() const;
    int getX() const;

private:
    int y, x;
};

#endif /* POINT_H */