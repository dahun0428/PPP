#include "StartScene.h"
#include "qlabel.h"
#include "newScene.h"
#include "loadscene.h"
#include "Game.h"
#include "savescene.h"

StartScene::StartScene( Game* game) : Scene( game )
{

    nextScene = NULL;


    ButtonNew = QRect( 310, 200, 180, 80 );
    ButtonLoad = QRect( 310, 300, 180, 80 );
    ButtonExit = QRect( 310, 400, 180, 80 );
	alertButton = QRect( 260, 270, 120, 100 );
    lastKeyInput = NULL;
    lastKey = Qt::Key_unknown;
    testX=100;
    testY=100;
}
StartScene::~StartScene()
{

}
Scene* StartScene::update()
{
    draw( 0, 0, "White.png" );


    if( ButtonNew.contains( lastCursor ) )
        drawCenter( 400, 240, "NewGame.png" );
    else
        drawCenter( 400-2, 240-2, "NewGame.png" );

    if( ButtonLoad.contains( lastCursor ) )
        drawCenter( 400, 340, "Continue.png" );
	else
        drawCenter( 400-2, 340-2, "Continue.png" );

    if( ButtonExit.contains( lastCursor ) )
        drawCenter( 400, 440, "Exit.png" );
    else
        drawCenter( 400-2, 440-2, "Exit.png" );

            drawCenter( testX, testY, "Exit.png" );

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

            if( ButtonNew.contains( x, y ) )
			{
                clickButtonNew();
				return true;
			}

            if( ButtonLoad.contains( x, y ) )
			{
                clickButtonLoad();
				return true;
			}

            if( ButtonExit.contains( x, y ) )
            {
                clickButtonExit();
                return true;
            }
            drawCenter( 100, 100, "Exit.png" );
            break;
         default:
             break;
	}
	
	return false;
}
bool StartScene::keyEvent(QKeyEvent *input){
    lastKeyInput = input;
    lastKey = input->key();
    if(nextScene !=NULL)
        return false;

    switch(lastKey){
        case 'A':
            pressA();
            return true;

        case 'B':
            pressB();
            return true;
        case 0x01000015:
            pressDown();
            return true;
    default:
        break;

    }
    return false;
}

void StartScene::clickButtonNew()
{
    getGameClass()->initialize();
	nextScene = new NewScene( getGameClass() );
}

void StartScene::clickButtonLoad()
{
    nextScene = new LoadScene( getGameClass() );
}

void StartScene::clickButtonExit()
{
    exit(0);
}

void StartScene::pressA()
{
    testX += 2.0;
    testY += 2.0;
}

void StartScene::pressB(){
    testX -= 1.0;
    testY -= 1.5;
}

void StartScene::pressDown()
{
    testY += 2.0;
}

// oh my god, git hub is so difficult!


// i want to die

// gitgit
// for next test

