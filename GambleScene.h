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
    bool keyEvent(QKeyEvent *);
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
    QRect hiddenButton;
    QRect alertButton;

    void clickButton1();
    void clickBackButton();
    void clickHiddenButton();
    void startOneRound();
    void finishOneRound();
    void showGambleResult();

    QString intToQString(int n);        // move somewhere else?
    QFont newFont;

};
#endif // GAMBLESCENE_H
