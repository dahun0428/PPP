#pragma once
#include "Scene.h"
#include <QTimer>
#include <QObject>

class StartScene : public Scene
{



public:
    StartScene( Game* );
    ~StartScene();
protected:
	Scene* update();
	bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
	Scene* nextScene;
	QPoint lastCursor;
    QKeyEvent *lastKeyInput;
    int lastKey;
    double testX;
    double testY;




    QRect ButtonNew;
    QRect ButtonLoad;
    QRect ButtonExit;
	QRect alertButton;

    void clickButtonNew();
    void clickButtonLoad();
    void clickButtonExit();
    void clickTest();
    void pressA();
    void pressB();
    void pressDown();
};
