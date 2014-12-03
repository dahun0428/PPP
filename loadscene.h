#pragma once
#include "Scene.h"
#define SAVE_SLOTS 4

#ifndef LOADSCENE_H
#define LOADSCENE_H

class LoadScene : public Scene

{
public:
    LoadScene( Game *);


    ~LoadScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
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
    bool load[SAVE_SLOTS];
};

#endif // LOADSCENE_H
