#ifndef SOCCERSCENE_H
#define SOCCERSCENE_H
#include"Scene.h"

#include "StartScene.h"
#include "olympicnanido.h"
class soccerscene : public Scene
{
public:
    soccerscene( Game* game);
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);

private:
    int t;
    int state;
    int keeper;
    Scene* nextScene;
    QPoint lastCursor;
    QString scoretext;
    int score,life;
    enum Difficulty Diff;
    int Dir;

    enum GameMode mode;
    bool enable;

    QString intToQString(int n);       // move somewhere else?R


    QRect Button1;
    QRect Button2;
    QRect Button3;
    QRect Button4;
    QRect Button5;
    //QRect alertButton;
    QRect BackButton;

    void clickButton1();
    void clickButton2();
    void clickButton3();
    void clickButton4();
    void clickButton5();
    void clickBackButton();
};

#endif // SOCCERSCENE_H
