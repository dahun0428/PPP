#pragma once
#include "Scene.h"
#define SAVE_SLOTS 4

#ifndef SAVESCENE_H
#define SAVESCENE_H

class SaveScene : public Scene

{
public:
    SaveScene( Game *);


    ~SaveScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;


    QRect Button1;
    QRect Button2;
    QRect Button3;
    QRect Button4;
    QRect alertButton;
    QRect BackButton;

    // game slot click
    void clickButton1();
    void clickButton2();
    void clickButton3();
    void clickButton4();
    void clickBackButton();

    // load
    QString filename[SAVE_SLOTS];
};

#endif // SAVESCENE_H
