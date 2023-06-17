#ifndef SCORE_H
#define SCORE_H

class Score {
public:
    Score();

    void setScore(int index, int size = 0);
    int getScore(int index) const;
    
private:
    /*
    -- scoreList[index] --
    0 : Current Snake Size
    1 : Max Snake Size
    2 : Growth Item Count
    3 : Poison Item Count
    4 : Gate Count
    */

    int scoreList[5] = {3, 3, 0, 0, 0};
};

#endif /* SCORE_H */