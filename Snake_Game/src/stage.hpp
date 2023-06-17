#ifndef STAGE_H
#define STAGE_H

#include "point.hpp"
#include <vector>

class Stage {
public:
    Stage(int diff);
    
    void setStageInfo(const Point& pos, int value);
    int getStageInfo(const Point& pos) const;
    int getStageInfo(int y, int x) const;

    std::vector<std::vector<int>> getCurrentStage() const;

private:
    int currentDiff;
    std::vector<std::vector<std::vector<int>>> stageList;
    std::vector<std::vector<int>> currentStage;
};

#endif /* STAGE_H */