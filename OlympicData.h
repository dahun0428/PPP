#include "Global.h"

#ifndef OLYMPICDATA_H
#define OLYMPICDATA_H

class OlympicData {
private:
    enum Difficulty diff;
    int result[4][3];
    // row: 0: postech, 1: kaist, 2: unist, 3:gist
    // column: 0: gold, 1: silver, 2:bronze

public:
    OlympicData();
    ~OlympicData();
    void setDiff(enum Difficulty _diff);
    enum Difficulty getDifficulty();

    // these functions will be used in loadGame function
    void setMedal(enum School _school, int _gold, int _silver, int _bronze);

    void goldReceive(enum School _school);
    void silverReceive(enum School _school);
    void bronzeReceive(enum School _school);
    int getSchoolMedal(enum School _school, enum Medal _medal);
};

#endif // OLYMPICDATA_H
