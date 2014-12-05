#include "selectscene.h"
#include "Game.h"
#include "qlabel.h"
#include "olympicnanido.h"
#include "soccerscene.h"
SelectScene::SelectScene(Game * game) : Scene(game)
{
    nextScene = NULL;

    ButtonSwim = QRect( 50, 200, 140, 140 );
    ButtonBasket = QRect( 300, 200, 140, 140 );
    ButtonSoccer = QRect( 550, 200, 140, 140 );
    BackButton = QRect ( 50, 50, 40, 40 );

    getGameClass()->setGamemode(OLYMPIC);
}
SelectScene::~SelectScene()
{

}
Scene* SelectScene::update()
{
    draw( 0, 0, "White.png" );


    if( ButtonSwim.contains( lastCursor ) )
        drawCenter( 120, 270, "Swim.png" );
    else
        drawCenter( 120-2, 270-2, "Swim.png" );

    if( ButtonBasket.contains( lastCursor ) )
        drawCenter( 370, 270, "Basket.png" );
    else
        drawCenter( 370-2, 270-2, "Basket.png" );

    if( ButtonSoccer.contains( lastCursor ) )
        drawCenter( 620, 270, "Soccer.png" );
    else
        drawCenter( 620-2, 270-2, "Soccer.png" );

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );



    return nextScene;
}
bool SelectScene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:

            if( ButtonSwim.contains( x, y ) )
            {
                clickButtonSwim();
                return true;
            }

            if( ButtonBasket.contains( x, y ) )
            {
                clickButtonBasket();
                return true;
            }

            if( ButtonSoccer.contains(x,y))
               {
                clickButtonSoccer();
                return true;
            }
            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }



    }

    return false;
}
bool SelectScene::keyEvent(QKeyEvent * input){

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
void SelectScene::clickButtonSwim()
{


}

void SelectScene::clickButtonBasket()
{

}


void SelectScene::clickButtonSoccer()
{

}

void SelectScene::clickBackButton(){
    nextScene = new OlympicNanido( getGameClass() );

}
