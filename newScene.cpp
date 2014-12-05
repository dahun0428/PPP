#include "newScene.h"
#include "StartScene.h"
#include "qlabel.h"
#include "shopscene.h"
#include "olympicnanido.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "Game.h"
#include "historyscene.h"
#include "savescene.h"

NewScene::NewScene( Game* game) : Scene( game )
{

    nextScene = NULL;


    Button1 = QRect( 310, 240, 180, 80 );
    Button2 = QRect( 310, 340, 180, 80 );
    ShopButton = QRect ( 700, 50, 40, 40);
    BackButton = QRect ( 50, 50, 40, 40 );
    HistoryButton = QRect (310, 440, 180, 80);
    SaveButton = QRect (600, 50, 40, 40);
//	alertButton = QRect( 260, 270, 120, 100 );
}
NewScene::~NewScene()
{

}
Scene* NewScene::update()
{
    draw( 0, 0, "White.png" );


	if( Button1.contains( lastCursor ) )
        drawCenter( 400, 280, "Single.png" );
	else
        drawCenter( 400-2, 280-2, "Single.png" );

    if( Button2.contains( lastCursor ) )
        drawCenter( 400, 380, "Olympic.png" );
    else
        drawCenter( 400-2, 380-2, "Olympic.png" );

    if( ShopButton.contains( lastCursor ) )
        drawCenter( 720, 70, "Shop.png" );
    else
        drawCenter( 720-2, 70-2, "Shop.png" );

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    if( HistoryButton.contains( lastCursor ) )
        drawCenter( 400, 480, "Olympic.png" );
    else
        drawCenter( 400-2, 480-2, "Olympic.png" );

    if (SaveButton.contains( lastCursor ) )
        drawCenter( 620, 70, "Save.png");
    else
        drawCenter( 620-2, 70-2, "Save.png");


	return nextScene;
}
bool NewScene::mouseEvent( int x, int y, MouseFunction function )
{
	lastCursor.setX( x );
	lastCursor.setY( y );

    if(nextScene != NULL)
		return false;

	switch( function )
	{
		case MOUSE_CLICK:

			if( Button1.contains( x, y ) )
			{
				clickButton1();
				return true;
			}

			if( Button2.contains( x, y ) )
			{
				clickButton2();
				return true;
			}
            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }

            if( ShopButton.contains(x,y))
               {
                clickShop();
                return true;
            }

            if( HistoryButton.contains(x,y)) {
                clickHistoryButton();
                return true;
            }

            if( SaveButton.contains(x, y)) {
                clickSaveButton();
                return true;
            }

	}
	
	return false;
}
bool NewScene::keyEvent(QKeyEvent * input){

    if(nextScene !=NULL)
        return false;

    switch(input->key()){
        case Qt::Key_A:
     //       drawCenter( 100, 100, "Exit.png" );
            break;
    default:
        break;

    }
}
void NewScene::clickButton1()
{
	nextScene = new SelectSingleScene( getGameClass() );
}

void NewScene::clickButton2()
{
    nextScene = new OlympicNanido(getGameClass());
}

void NewScene::clickBackButton(){
    nextScene = new StartScene( getGameClass() );

}

void NewScene::clickShop(){
    nextScene = new ShopScene( getGameClass() );

}

void NewScene::clickHistoryButton() {
    nextScene = new HistoryScene( getGameClass() );
}

void NewScene::clickSaveButton() {
    nextScene = new SaveScene( getGameClass(), NEW);
}
