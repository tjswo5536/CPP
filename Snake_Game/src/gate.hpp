#ifndef GATE_H
#define GATE_H

#include "stage.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class Gate {
public:
    Gate();

    void createGate(Stage& stage);
    void deleteGate(Stage& stage);

    void setGateA();
    Point getGateA() const;

    void setGateB();
    Point getGateB() const;

private:
    Point gateA, gateB;
};

#endif /* GATE_H */