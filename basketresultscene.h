#ifndef BASKETRESULTSCENE_H
#define BASKETRESULTSCENE_H
#include"Scene.h"
#include"selectsinglescene.h"

class basketResultScene : public Scene
{
public:
    basketResultScene(Game*);

    ~basketResultScene();
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

    QFont Font1;

};

#endif // BASKETRESULTSCENE_H
