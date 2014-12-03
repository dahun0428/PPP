#include "OlympicData.h"

OlympicData::OlympicData() {
    diff = NONE;
    for (int i=0; i<3; i++) {
        postech_result[i]=0;
        kaist_result[i]=0;
        unist_result[i]=0;
        gist_result[i]=0;
    }
}

OlympicData::~OlympicData() {
}

void OlympicData::setDiff(enum Difficulty _diff){
    diff = _diff;
}

void OlympicData::setPostechMedal(int gold, int silver, int bronze) {
    postech_result[0] = gold;
    postech_result[1] = silver;
    postech_result[2] = bronze;
}

void OlympicData::setKaistMedal(int gold, int silver, int bronze) {
    kaist_result[0] = gold;
    kaist_result[1] = silver;
    kaist_result[2] = bronze;
}

void OlympicData::setUnistMedal(int gold, int silver, int bronze) {
    unist_result[0] = gold;
    unist_result[1] = silver;
    unist_result[2] = bronze;
}

void OlympicData::setGistMedal(int gold, int silver, int bronze) {
    gist_result[0] = gold;
    gist_result[1] = silver;
    gist_result[2] = bronze;
}

void OlympicData::postechReceive(enum Medal _medal) {
    postech_result[_medal]++;
}

void OlympicData::kaistReceive(enum Medal _medal) {
    kaist_result[_medal]++;
}

void OlympicData::unistReceive(enum Medal _medal) {
    unist_result[_medal]++;
}

void OlympicData::gistReceive(enum Medal _medal) {
    gist_result[_medal]++;
}

enum Difficulty OlympicData::getDifficulty() {
    return diff;
}

int OlympicData::getPostechMedal(enum Medal _medal) {
    return posteh_result[_medal];
}

int OlympicData::getKaistMedal(enum Medal _medal) {
    return kaist_result[_medal];
}

int OlympicData::getUnistMedal(enum Medal _medal) {
    return unist_result[_medal];
}

int OlympicData::getGistMedal(enum Medal _medal) {
    return gist_result[_medal];
}

#endif // OLYMPICDATA_H
