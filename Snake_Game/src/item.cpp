#include "item.hpp"

Item::Item() : growthItem(1, 1), poisonItem(1, 2) {
    srand((unsigned int)time(NULL));
}

void Item::createItem(Stage& stage, Snake& snake) {
    setGrowthItem();
    while((stage.getStageInfo(growthItem) != 0) && (!snake.isInSnake(growthItem)))
        setGrowthItem();
    stage.setStageInfo(growthItem, 1);

    setPoisonItem();
    while((stage.getStageInfo(poisonItem) != 0) && (!snake.isInSnake(poisonItem)))
        setPoisonItem();
    stage.setStageInfo(poisonItem, 2);
}

void Item::deleteItem(Stage& stage) {
    stage.setStageInfo(growthItem, 0);
    mvaddch(growthItem.getY() + 2, growthItem.getX() + 2, ' ');

    stage.setStageInfo(poisonItem, 0);
    mvaddch(poisonItem.getY() + 2, poisonItem.getX() + 2, ' ');
}

void Item::setGrowthItem() {
    growthItem = Point(rand() % 19 + 1, rand() % 19 + 1);
}

Point Item::getGrowthItem() const {
    return growthItem;
}

void Item::setPoisonItem() {
    poisonItem = Point(rand() % 19 + 1, rand() % 19 + 1);
}

Point Item::getPoisonItem() const {
    return poisonItem;
}