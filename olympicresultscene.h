#ifndef OLYMPICRESULTSCENE_H
#define OLYMPICRESULTSCENE_H
#include "Scene.h"
#include"selectscene.h"

class OlympicResultScene : public Scene
{
public:
    OlympicResultScene(Game *);

    ~OlympicResultScene();
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
    QFont Font1,Font2;
};

#endif // OLYMPICRESULTSCENE_H
