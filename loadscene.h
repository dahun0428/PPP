#pragma once
#include "Scene.h"
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

    void clickButton1();
    void clickButton2();
    void clickBackButton();
};

#endif // LOADSCENE_H
