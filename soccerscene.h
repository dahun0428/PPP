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
private:
    int t;
    int state;
    int keeper;
    Scene* nextScene;
    QPoint lastCursor;
    QString scoretext;
    int score;


    QRect Button1;
    QRect Button2;
    QRect Button3;
    //QRect alertButton;
    QRect BackButton;

    void clickButton1();
    void clickButton2();
    void clickButton3();
    void clickBackButton();
};

#endif // SOCCERSCENE_H
