#ifndef SINGLERESULTSCENE_H
#define SINGLERESULTSCENE_H
#include"Scene.h"
#include"selectsinglescene.h"

class singleResultScene : public Scene
{
public:
    singleResultScene(Game*);

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
    QString intToQString(int n);

    void clickButtonNext();

};

#endif // BASKETRESULTSCENE_H
