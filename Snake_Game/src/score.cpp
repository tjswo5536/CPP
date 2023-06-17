#include "score.hpp"

Score::Score() {}

void Score::setScore(int index, int size) {
    switch(index) {
    case 0:
        scoreList[index] = size;
        break;
    case 1:
        if(size > scoreList[index])
            scoreList[index] = size;
        break;
    case 2: case 3: case 4:
        scoreList[index]++;
        break;
    }
}

int Score::getScore(int index) const {
    return scoreList[index];
}