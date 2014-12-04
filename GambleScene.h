    #ifndef GAMBLESCENE_H
#define GAMBLESCENE_H
#include "Scene.h"

class GambleScene : public Scene
{
public:
    GambleScene( Game* );
    ~GambleScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;
    QString pointText;
    int gambleCost;

    QRect Button1;
    QRect BackButton;
    QRect alertButton;

    void clickButton1();
    void clickBackButton();

    QString intToQString(int n);        // move somewhere else?

};
#endif // GAMBLESCENE_H

// Git FUck
