#include "gate.hpp"

Gate::Gate() : gateA(1, 0), gateB(0, 1) {
    srand((unsigned int)time(NULL));
}

void Gate::createGate(Stage& stage) {
    setGateA();
    while(stage.getStageInfo(gateA) != 3)
        setGateA();
    stage.setStageInfo(gateA, 5);

    setGateB();
    while(stage.getStageInfo(gateB) != 3)
        setGateB();
    stage.setStageInfo(gateB, 6);
}

void Gate::deleteGate(Stage& stage) {
    stage.setStageInfo(gateA, 3);
    mvaddch(gateA.getY() + 2, gateA.getX() + 2, '#');

    stage.setStageInfo(gateB, 3);
    mvaddch(gateB.getY() + 2, gateB.getX() + 2, '#');
}

void Gate::setGateA() {
    gateA = Point(rand() % 21, rand() % 21);
}

Point Gate::getGateA() const {
    return gateA;
}

void Gate::setGateB() {
    gateB = Point(rand() % 21, rand() % 21);
}

Point Gate::getGateB() const {
    return gateB;
}