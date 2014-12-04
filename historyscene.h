#pragma once
#include "Scene.h"

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

    QRect ExerciseHistoryButton;
    QRect OlympicHistoryButton;

    bool mode;
    QRect ExerciseEasyButton;
    QRect ExerciseNormalButton;
    QRect ExerciseHardButton;

    QRect OlympicButton[10];

};

#endif // HISTORYSCENE_H
