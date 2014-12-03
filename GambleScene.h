#ifndef GAMBLESCENE_H
#define GAMBLESCENE_H
#include "Scene.h"

class GambleScene : public Scene
{
public:
    GambleScene( Game* );
    ~GambleScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
private:
    Scene* nextScene;
    QPoint lastCursor;
    QString pointText;
    int gambleCost;
    int spinSlot[3];
    QString spinSlotShapeName[3];

    int spinCount;

    QRect Button1;
    QRect BackButton;
    QRect alertButton;

    void clickButton1();
    void clickBackButton();
    void startOneRound();
    void finishOneRound();
    void showGambleResult();

    QString intToQString(int n);        // move somewhere else?

};
#endif // GAMBLESCENE_H

// Git FUck
