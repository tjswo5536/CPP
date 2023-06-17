#ifndef MISSION_H
#define MISSION_H

#include <vector>

class Mission {
public:
    Mission(int currentDiff);
    
    int getCurrentMission(int index) const;

    void setMissionClear(int index);
    char getMissionClear(int index) const;

    bool isMissionAllClear();

private:
    /*
    -- missionList[index] --
    0 : Max Snake Size Mission
    1 : Growth Item Mission
    2 : Poision Item Mission
    3 : Gate Count Mission
    */

    std::vector<std::vector<int>> missionList;
    std::vector<int> currentMission;
    char isMissionClear[4] = {' ', ' ', ' ', ' '};
};

#endif /* MISSION_H */