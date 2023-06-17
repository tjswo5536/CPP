#include "mission.hpp"

Mission::Mission(int currentDiff) {
    missionList = {
                  {5, 3, 1, 1},
                  {7, 5, 2, 2},
                  {10, 7, 4, 4},
                  {14, 10, 7, 7}};

    currentMission = missionList[currentDiff - 1];
}

int Mission::getCurrentMission(int index) const {
    return currentMission[index];
}

void Mission::setMissionClear(int index) {
    isMissionClear[index] = 'v';
}

char Mission::getMissionClear(int index) const {
    return isMissionClear[index];
}

bool Mission::isMissionAllClear() {
    for(int index = 0; index < 4; index++) {
        if(isMissionClear[index] != 'v')
            return false;
    }
    return true;
}