#include "olympicnanido.h"
#include "Scene.h"
#include "Game.h"
#include "qlabel.h"
#include "newScene.h"
#include "selectscene.h"
#include "OlympicData.h"
OlympicNanido::OlympicNanido(Game * game) : Scene(game)
{
    nextScene = NULL;

    ButtonEasy = QRect( 310, 200, 180, 80 );
    ButtonNormal = QRect( 310, 300, 180, 80 );
    ButtonHard = QRect( 310, 400, 180, 80 );
    BackButton = QRect ( 50, 50, 40, 40 );

    getGameClass()->setGamemode(OLYMPIC);
}
OlympicNanido::~OlympicNanido()
{

}
Scene* OlympicNanido::update()
{
    draw( 0, 0, "White.png" );


    if( ButtonEasy.contains( lastCursor ) )
        drawCenter( 400, 240, "Easy.png" );
    else
        drawCenter( 400-2, 240-2, "Easy.png" );

    if( ButtonNormal.contains( lastCursor ) )
        drawCenter( 400, 340, "Normal.png" );
    else
        drawCenter( 400-2, 340-2, "Normal.png" );

    if( ButtonHard.contains( lastCursor ) )
        drawCenter( 400, 440, "Hard.png" );
    else
        drawCenter( 400-2, 440-2, "Hard.png" );

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );



    return nextScene;
}
bool OlympicNanido::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:

            if( ButtonEasy.contains( x, y ) )
            {
                clickButtonEasy();
                return true;
            }

            if( ButtonNormal.contains( x, y ) )
            {
                clickButtonNormal();
                return true;
            }

            if( ButtonHard.contains(x,y))
               {
                clickButtonHard();
                return true;
            }
            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }



    }

    return false;
}
bool OlympicNanido::keyEvent(QKeyEvent * input){

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
void OlympicNanido::clickButtonEasy()
{
    getGameClass()->setOlympicDifficulty(EASY);
    if (getGameClass()->getOlympicCnt()==10) {
        getGameClass()->result_reset();
    }
    getGameClass()->getOlympicData(getGameClass()->getOlympicCnt())->setDiff(EASY);
    nextScene = new SelectScene(getGameClass());
}

void OlympicNanido::clickButtonNormal()
{
    getGameClass()->setOlympicDifficulty(NORMAL);
    if (getGameClass()->getOlympicCnt()==10) {
        getGameClass()->result_reset();
    }
    getGameClass()->getOlympicData(getGameClass()->getOlympicCnt())->setDiff(NORMAL);
    nextScene = new SelectScene(getGameClass());
}


void OlympicNanido::clickButtonHard()
{
    getGameClass()->setOlympicDifficulty(HARD);
    if (getGameClass()->getOlympicCnt()==10) {
        getGameClass()->result_reset();
    }
    getGameClass()->getOlympicData(getGameClass()->getOlympicCnt())->setDiff(HARD);
    nextScene = new SelectScene(getGameClass());
}

void OlympicNanido::clickBackButton(){
    nextScene = new NewScene( getGameClass() );

}

