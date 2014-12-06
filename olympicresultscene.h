#ifndef OLYMPICRESULTSCENE_H
#define OLYMPICRESULTSCENE_H
#include "Scene.h"
#include"selectscene.h"

class OlympicResultScene : public Scene
{
public:
    OlympicResultScene(Game *, int[4]);

    ~OlympicResultScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;

    QRect ButtonNext;

    void clickButtonNext();
    QFont ScoreFont;
    QFont PointFont;
    enum School gold_receiver;
    enum School silver_receiver;
    enum School bronze_receiver;
    int scores[4];
    int pre_point;
    int new_point;
    void setMedalReceiver();
};

#endif // OLYMPICRESULTSCENE_H
