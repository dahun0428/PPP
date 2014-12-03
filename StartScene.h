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

// animation test
    double testX;
    double testY;
    QTimer * Timer;


    QRect Button1;
    QRect Button2;
    QRect Button3;
	QRect alertButton;

	void clickButton1();
	void clickButton2();
    void clickButton3();
    void clickTest();

public slots:

     void TestMoving(); // TEST
     void Delete();

};
