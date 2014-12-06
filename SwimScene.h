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

    enum Difficulty diff;
    int numOfPlayers;
    Character* player;
    double* swimFactor;
    int* swimmerShapeCount;
    double* position;
    QByteArray* characterImgName;
    double finishPosition;
    int userSwimCount;
    int opponentSwimCount;

    // For olympic mode
    int finishedPlayerCount;
    int score[4];   // Each entry stores the corresponding School's score.
                    // As defined in enum School in "global.h", index means
                    // 0: POSTECH, 1: KAIST, 2: UNIST, 3: GIST.
    void userSwim();
    void opponentSwim();
    void clickBackButton();
    bool isFinished();
    void sendResult();

    QString doubleToQString(double n);
};

#endif // SWIMSCENE_H
