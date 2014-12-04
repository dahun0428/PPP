#pragma once
#include "Scene.h"
#include "OlympicData.h"

#ifndef HISTORYSCENE_H
#define HISTORYSCENE_H

class HistoryScene: public Scene {
public:
    HistoryScene( Game *);
    ~HistoryScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;

    QRect BackButton;
    QRect SingleHistoryButton;
    QRect OlympicHistoryButton;

    enum GameMode mode; // 0: single, 1: olympic
    QRect SingleEasyButton;
    QRect SingleNormalButton;
    QRect SingleHardButton;
    QRect OlympicButtons;

    void clickBackButton();
    void clickSingleEasyButton();
    void clickSingleNormalButton();
    void clickSingleHardButton();
    void clickOlympicButtons();

    enum Difficulty diff;
    int olympic_index;
    int olympic_cnt;

    void drawSingleEasy();
    void drawSingleNormal();
    void drawSingleHard();
    void drawOlympic(int index);

};

#endif // HISTORYSCENE_H
