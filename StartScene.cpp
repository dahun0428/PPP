#include "StartScene.h"
#include "qlabel.h"
#include "newScene.h"
#include "loadscene.h"

StartScene::StartScene( Game* game) : Scene( game )
{

    nextScene = NULL;


    Button1 = QRect( 310, 200, 180, 80 );
    Button2 = QRect( 310, 300, 180, 80 );
    Button3 = QRect( 310, 400, 180, 80 );
    alertButton = QRect( 100, 100, 120, 100 );
    testX= 120;
    testY= 120;
}
StartScene::~StartScene()
{

}
Scene* StartScene::update()
{
    draw( 0, 0, "White.png" );
    clickTest();



	if( Button1.contains( lastCursor ) )
        drawCenter( 400, 240, "NewGame.png" );
    else
        drawCenter( 400-2, 240-2, "NewGame.png" );

    if( Button2.contains( lastCursor ) )
        drawCenter( 400, 340, "Continue.png" );
	else
        drawCenter( 400-2, 340-2, "Continue.png" );

    if( Button3.contains( lastCursor ) )
        drawCenter( 400, 440, "Exit.png" );
    else
        drawCenter( 400-2, 440-2, "Exit.png" );

    if( alertButton.contains(lastCursor))
        drawCenter( testX, testY, "Test.png");
    else
        drawCenter( testX-2, testY-2, "Test.png");




	return nextScene;
}
bool StartScene::mouseEvent( int x, int y, MouseFunction function )
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

            if( Button3.contains( x, y ) )
            {
                clickButton3();
                return true;
            }






	}
	
	return false;
}
void StartScene::clickButton1()
{
	nextScene = new NewScene( getGameClass() );

}

void StartScene::clickButton2()
{
    nextScene = new LoadScene( getGameClass() );
}

void StartScene::clickButton3()
{
    exit(0);
}
void StartScene::TestMoving(){

    testX +=3.0;
    testY +=3.0;

}

void StartScene::clickTest(){


    TestMoving();
    Timer = new QTimer(this);
//    QObject::connect(Timer,SIGNAL(timeout()) ,SLOT(TestMoving()));

 //   QTimer::singleShot(1000,this, SLOT(Delete()));
  //  Timer->start(30);
}

void StartScene::Delete(){

    delete Timer;
}
