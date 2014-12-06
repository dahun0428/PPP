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
    QRect BackButton;
    QRect alertButton;

    Difficulty diff;
    int numOfPlayers;
    Character* player;
    double* swimFactor;
    int* swimmerShapeCount;
    double* position;    
    double finishPosition;

    int userSwimCount;
    int opponentSwimCount;

    void userSwim();
    void opponentSwim();
    void clickBackButton();
    bool isFinished();
    void storeResult();

    QString doubleToQString(double n);
};

#endif // SWIMSCENE_H
