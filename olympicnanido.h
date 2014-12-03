#pragma once

#include "Scene.h"
#ifndef OLYMPICNANIDO_H
#define OLYMPICNANIDO_H

class OlympicNanido : public Scene
{
public:
    OlympicNanido(Game*) ;

    ~OlympicNanido();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
private:
    Scene* nextScene;
    QPoint lastCursor;


    QRect ButtonEasy;
    QRect ButtonNormal;
    QRect ButtonHard;
    QRect BackButton;

    void clickButtonEasy();
    void clickButtonNormal();
    void clickButtonHard();
    void clickBackButton();
};

#endif // OLYMPICNANIDO_H
