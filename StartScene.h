#pragma once
#include "Scene.h"
#include <QTimer>
#include <QObject>

class StartScene : public Scene , public QObject
{



public:
    StartScene( Game* );
    ~StartScene();
protected:
	Scene* update();
	bool mouseEvent( int x, int y, MouseFunction );
private:
	Scene* nextScene;
	QPoint lastCursor;




    QRect ButtonNew;
    QRect ButtonLoad;
    QRect ButtonExit;
	QRect alertButton;

    void clickButtonNew();
    void clickButtonLoad();
    void clickButtonExit();
    void clickTest();


};
