#include "OlympicData.h"

OlympicData::OlympicData() {
    diff = NONE;
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++)
            result[i][j] = 0;
    }
}

OlympicData::~OlympicData() {
}

void OlympicData::setDiff(enum Difficulty _diff){
    diff = _diff;
}

void OlympicData::setMedal(enum School _school, int gold, int silver, int bronze) {
    result[_school][0] = gold;
    result[_school][1] = silver;
    result[_school][2] = bronze;
}

void OlympicData::goldReceive(enum School _school) {
    result[_school][GOLD]++;
}

void OlympicData::silverReceive(enum School _school) {
    result[_school][SILVER]++;
}

void OlympicData::bronzeReceive(enum School _school) {
    result[_school][BRONZE]++;
}

enum Difficulty OlympicData::getDifficulty() {
    return diff;
}

int OlympicData::getSchoolMedal(enum School _school, enum Medal _medal) {
    return result[_school][_medal];
}
