#ifndef ITEM_H
#define ITEM_H

#include "snake.hpp"
#include "stage.hpp"
#include <cstdlib>
#include <ctime>

class Item {
public:
    Item();

    void createItem(Stage& stage, Snake& snake);
    void deleteItem(Stage& stage);

    void setGrowthItem();
    Point getGrowthItem() const;
    
    void setPoisonItem();
    Point getPoisonItem() const;

private:
    Point growthItem, poisonItem;
};

#endif /* ITEM_H */