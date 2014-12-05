#ifndef QUIZSCENE_H
#define QUIZSCENE_H

#include "Scene.h"
#include "Character.h"

class QuizScene : public Scene
{
public:
    QuizScene( Game* );
    ~QuizScene();
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

    QRect Button1;
    QRect BackButton;
    QRect alertButton;

    void clickButton1();
    void clickBackButton();
    void opponentSwim();
    bool isFinished();
};

#endif // QUIZSCENE_H
