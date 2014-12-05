#ifndef SWIMSCENE_H
#define SWIMSCENE_H
#include "Scene.h"
#include "Character.h"
#include <QTime>

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
    int lastKey;
    QTime timer;
    int elapsedTime;
    int finishedCount;

    Difficulty diff;
    int numOfPlayers;
    Character** player;
    double* swimFactor;
    double* position;
    double finishPosition;

    int userSwimCount;
    int opponentSwimCount;
    int winnderIndex;

    QRect Button1;
    QRect BackButton;
    QRect alertButton;

    void userSwim();
    void clickBackButton();
    void opponentSwim();
    bool isFinished();

    QString doubleToQString(double n);
};


#endif // SWIMSCENE_H
