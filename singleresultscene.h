#ifndef SINGLERESULTSCENE_H
#define SINGLERESULTSCENE_H
#include"Scene.h"
#include"selectsinglescene.h"

class singleResultScene : public Scene
{
public:
    singleResultScene(Game*, int);

    ~singleResultScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;
    QString scoretext;


    QRect ButtonNext;
    void clickButtonNext();

    QFont ScoreFont;
    QFont PointFont;
    int pre_score;
    int new_score;
    int pre_point;
    int new_point;

};

#endif // BASKETRESULTSCENE_H
