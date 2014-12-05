#include "historyscene.h"
#include "newScene.h"
#include "Game.h"
#include "Global.h"

HistoryScene::HistoryScene( Game* game) : Scene( game ) {
    nextScene = NULL;

    BackButton = QRect(50, 50, 40, 40);
    SingleHistoryButton = QRect(175, 75, 150, 50);
    OlympicHistoryButton = QRect(475, 75, 150, 50);

    mode = SINGLE;
    olympic_index = 0;
    olympic_cnt = getGameClass()->getOlympicCnt();
    diff = EASY;

    SingleEasyButton = QRect(100, 170, 150, 60);
    SingleNormalButton = QRect(325, 170, 150, 60);
    SingleHardButton = QRect(550, 170, 150, 60);
    OlympicButtons = QRect(0, 170, 800, 60);
}

HistoryScene::~HistoryScene() {

}

Scene* HistoryScene::update() {
    draw( 0, 0, "White.png" );
    draw( 0, 30, "White.png" );

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    if (SingleHistoryButton.contains(lastCursor))
        drawCenter( 250, 100, "Single_history.png");
    else
        drawCenter( 250-2, 100-2, "Single_history.png");

    if (OlympicHistoryButton.contains(lastCursor))
        drawCenter( 550, 100, "Olympic_history.png");
    else
        drawCenter( 550-2, 100-2, "Olympic_history.png");

    if (mode == SINGLE) {
        drawCenter( 175, 200, "Easy_history.png");
        drawCenter( 400, 200, "Normal_history.png");
        drawCenter( 625, 200, "Hard_history.png");
        if (diff == SINGLE)
            drawSingleEasy();
        if (diff == NORMAL)
            drawSingleNormal();
        if (diff == HARD)
            drawSingleHard();
    }
    if (mode == OLYMPIC) {
        drawCenter(400, 200, "Olympic_buttons.png");
        drawOlympic(olympic_index);
    }

    return nextScene;
}

bool HistoryScene::mouseEvent(int x, int y, MouseFunction function) {
    lastCursor.setX(x);
    lastCursor.setY(y);

    if(nextScene != NULL)
        return false;

    switch(function) {
        case MOUSE_CLICK:
            if (BackButton.contains(x, y)) {
                clickBackButton();
                return true;
            }
            if (SingleHistoryButton.contains(x, y)) {
                mode = SINGLE;
                return true;
            }
            if (OlympicHistoryButton.contains(x, y)) {
                mode = OLYMPIC;
                return true;
            }

            if (mode == SINGLE && SingleEasyButton.contains(x, y)) {
                diff = EASY;
                return true;
            }

            if (mode == SINGLE && SingleNormalButton.contains(x, y)) {
                diff = NORMAL;
                return true;
            }

            if (mode == SINGLE && SingleHardButton.contains(x, y)) {
                diff = HARD;
                return true;
            }

            if (mode == OLYMPIC && OlympicButtons.contains(x, y)) {
                olympic_index = (int)(x/80);
                return true;
            }

    }

    return false;
}

bool HistoryScene::keyEvent(QKeyEvent * input){

    if(nextScene !=NULL)
        return false;

    switch(input->key()){
        case Qt::Key_A:
     //       drawCenter( 100, 100, "Exit.png" );
            break;
    default:
        break;

    }
}

void HistoryScene::clickBackButton() {
    nextScene = new NewScene( getGameClass() );
}

void HistoryScene::drawSingleEasy() {

}

void HistoryScene::drawSingleNormal() {

}

void HistoryScene::drawSingleHard() {

}

void HistoryScene::drawOlympic(int index) {

    int postech_x = 50;
    int kaist_x = 50;
    int unist_x = 450;
    int gist_x = 450;
    int postech_y = 340;
    int unist_y = 340;
    int kaist_y = 480;
    int gist_y = 480;
    drawCenter(postech_x, postech_y, "postech.png");
    drawCenter(kaist_x, kaist_y, "kaist.png");
    drawCenter(unist_x, unist_y, "unist.png");
    drawCenter(gist_x, gist_y, "gist.png");

    if (index >= olympic_cnt) {
        drawCenter(400, 400, "notyet.png");
        return;
    }

    int postech_gold = getGameClass()->getOlympicData(index)->getSchoolMedal(POSTECH, GOLD);
    int postech_silver = getGameClass()->getOlympicData(index)->getSchoolMedal(POSTECH, SILVER);
    int postech_bronze = getGameClass()->getOlympicData(index)->getSchoolMedal(POSTECH, BRONZE);
    int kaist_gold = getGameClass()->getOlympicData(index)->getSchoolMedal(KAIST, GOLD);
    int kaist_silver = getGameClass()->getOlympicData(index)->getSchoolMedal(KAIST, SILVER);
    int kaist_bronze = getGameClass()->getOlympicData(index)->getSchoolMedal(KAIST, BRONZE);
    int unist_gold = getGameClass()->getOlympicData(index)->getSchoolMedal(UNIST, GOLD);
    int unist_silver = getGameClass()->getOlympicData(index)->getSchoolMedal(UNIST, SILVER);
    int unist_bronze = getGameClass()->getOlympicData(index)->getSchoolMedal(UNIST, BRONZE);
    int gist_gold = getGameClass()->getOlympicData(index)->getSchoolMedal(GIST, GOLD);
    int gist_silver = getGameClass()->getOlympicData(index)->getSchoolMedal(GIST, SILVER);
    int gist_bronze = getGameClass()->getOlympicData(index)->getSchoolMedal(GIST, BRONZE);

    // postech medal draw
    int x_pos = 130;
    for (int i=0; i<postech_gold; i++) {
        drawCenter(x_pos, postech_y, "Gold_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<postech_silver; i++) {
        drawCenter(x_pos, postech_y, "Silver_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<postech_bronze; i++) {
        drawCenter(x_pos, postech_y, "Bronze_medal.png");
        x_pos+=60;
    }

    // kaist medal draw
    x_pos = 130;
    for (int i=0; i<kaist_gold; i++) {
        drawCenter(x_pos, kaist_y, "Gold_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<kaist_silver; i++) {
        drawCenter(x_pos, kaist_y, "Silver_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<kaist_bronze; i++) {
        drawCenter(x_pos, kaist_y, "Bronze_medal.png");
        x_pos+=60;
    }

    // unist medal draw
    x_pos = 530;
    for (int i=0; i<unist_gold; i++) {
        drawCenter(x_pos, unist_y, "Gold_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<unist_silver; i++) {
        drawCenter(x_pos, unist_y, "Silver_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<unist_bronze; i++) {
        drawCenter(x_pos, unist_y, "Bronze_medal.png");
        x_pos+=60;
    }

    // gist medal draw
    x_pos = 530;
    for (int i=0; i<gist_gold; i++) {
        drawCenter(x_pos, gist_y, "Gold_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<gist_silver; i++) {
        drawCenter(x_pos, gist_y, "Silver_medal.png");
        x_pos+=60;
    }
    for (int i=0; i<gist_bronze; i++) {
        drawCenter(x_pos, gist_y, "Bronze_medal.png");
        x_pos+=60;
    }

}
