#pragma once
#include "Scene.h"



class NewScene : public Scene
{
public:
	NewScene( Game* );
	~NewScene();
protected:
	Scene* update();
	bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
	Scene* nextScene;
	QPoint lastCursor;


	QRect Button1;
	QRect Button2;
    QRect ShopButton;
    //QRect alertButton;
    QRect BackButton;
    QRect HistoryButton;
    QRect SaveButton;

	void clickButton1();
	void clickButton2();
    void clickShop();
    void clickBackButton();
    void clickHistoryButton();
    void clickSaveButton();

};
