#ifndef SWIMSCENE_H
#define SWIMSCENE_H
#include "Scene.h"
#include "Character.h"

class SwimScene : public Scene
{
public:
    SwimScene( Game* );
    ~SwimScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent* input);
private:
    Scene* nextScene;
    QPoint lastCursor;
    //QKeyEvent* lastKeyInput;
    int lastKey;
    int numOfPlayers;
    Character** player;

    double* swimFactor;
    double* position;
    double finishPosition;

    int opponentSwimCount;
    int winnderIndex;

    QRect Button1;
    QRect BackButton;
    QRect alertButton;

    void clickButton1();
    void clickBackButton();
    void opponentSwim();
    bool isFinished();
};


#endif // SWIMSCENE_H
