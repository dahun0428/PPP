#include "newScene.h"
#include "StartScene.h"
#include "qlabel.h"
#include "shopscene.h"
#include "olympicnanido.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "Game.h"

NewScene::NewScene( Game* game) : Scene( game )
{

    nextScene = NULL;


    Button1 = QRect( 310, 240, 180, 80 );
    Button2 = QRect( 310, 340, 180, 80 );
    ShopButton = QRect ( 700, 50, 40, 40);
    BackButton = QRect ( 50, 50, 40, 40 );
//	alertButton = QRect( 260, 270, 120, 100 );
}
NewScene::~NewScene()
{

}
Scene* NewScene::update()
{
    draw( 0, 0, "White.png" );
    draw( 0, 30, "White.png" );

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

	}
	
	return false;
}
void NewScene::clickButton1()
{
    getGameClass()->initialize();
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
