#include "Global.h"

#ifndef OLYMPICDATA_H
#define OLYMPICDATA_H

class OlympicData {
private:
    OlympicData();
    ~OlympicData();
    enum Difficulty diff;
    int postech_result[3]; // 0: gold, 1: silver, 2:bronze
    int kaist_result[3];
    int unist_result[3];
    int gist_result[3];

public:
    void setDiff(enum Difficulty _diff);
    // these functions will be used in loadGame function
    void setPostechMedal(int gold, int silver, int bronze);
    void setKaistMedal(int gold, int silver, int bronze);
    void setUnistMedal(int gold, int silver, int bronze);
    void setGistMedal(int gold, int silver, int bronze);

    void postechReceive(enum Medal _medal);
    void kaistReceive(enum Medal _medal);
    void unistReceive(enum Medal _medal);
    void gistReceive(enum Medal _medal);
    enum Difficulty getDifficulty();
    int getPostechMedal(enum Medal _medal);
    int getKaistMedal(enum Medal _medal);
    int getUnistMedal(enum Medal _medal);
    int getGistMedal(enum Medal _medal);
};

#endif // OLYMPICDATA_H
