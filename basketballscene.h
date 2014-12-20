#ifndef BASKETBALLSCENE_H
#define BASKETBALLSCENE_H
#include "Global.h"
#include"Scene.h"
#include "StartScene.h"
#include "olympicnanido.h"
#include "Game.h"
#include <QTimer>
#include <QObject>

#define GRAV 1
#define BXE 450
#define BXN 550
#define BXH 700
#define BY 250
#define VMAX


class basketballscene : public Scene
{
public:
    basketballscene(Game* game);
    ~basketballscene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    int t,t2;
    int state,life;
    Scene* nextScene;
    QPoint lastCursor;
    QKeyEvent *lastKeyInput;
    int lastKey;
    QString scoretext;
    int score;
    bool updown,check;
    int bx0,bx,by,bv,bdir,bvx,bvy;

     QString intToQString(int n);


     enum GameMode mode;
     enum CharacterType character;
     enum Difficulty diff;


     QFont newFont;
     int Olympicscore[4];

};

#endif // BASKETBALLSCENE_H
