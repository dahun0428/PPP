#include "selectsinglescene.h"
#include "Game.h"
#include "qlabel.h"
#include "newScene.h"
#include "CharacterScene.h"
#include "soccerscene.h"
#include "basketballscene.h"
#include "SwimScene.h"

SelectSingleScene::SelectSingleScene(Game * game) : Scene(game)
{
    nextScene = NULL;

    ButtonSwim = QRect( 50, 200, 140, 140 );
    ButtonBasket = QRect( 300, 200, 140, 140 );
    ButtonSoccer = QRect( 550, 200, 140, 140 );
    BackButton = QRect ( 50, 50, 40, 40 );

    ButtonEasy = QRect( 300, 70, 40, 60 );
    ButtonNormal = QRect( 400, 70, 50, 60 );
    ButtonHard = QRect( 500, 70, 50, 60 );


    getGameClass()->setGamemode(SINGLE);
    getGameClass()->setDifficulty(NONE);
}
SelectSingleScene::~SelectSingleScene()
{

}
Scene* SelectSingleScene::update()
{
    draw( 0, 0, "White.png" );



    if( ButtonEasy.contains( lastCursor ) ){
        if( getGameClass()->getDifficulty() == EASY)
                    drawCenter (320, 90, "SelectedSingleE.png");
        else
            drawCenter( 320, 90, "SingleE.png" );
    }
    else if( getGameClass()->getDifficulty() == EASY)
            drawCenter (320-2, 90-2, "SelectedSingleE.png");
    else
        drawCenter( 320-2, 90-2, "SingleE.png" );

    if( ButtonNormal.contains( lastCursor ) ){
        if( getGameClass()->getDifficulty() == NORMAL)
                    drawCenter (420, 90, "SelectedSingleN.png");
        else
            drawCenter( 420, 90, "SingleN.png" );
    }
    else if( getGameClass()->getDifficulty() == NORMAL)
            drawCenter (420-2, 90-2, "SelectedSingleN.png");
    else
        drawCenter( 420-2, 90-2, "SingleN.png" );

    if( ButtonHard.contains( lastCursor ) ){
        if( getGameClass()->getDifficulty() == HARD)
            drawCenter( 520, 90, "SelectedSingleH.png" );
        else drawCenter( 520, 90, "SingleH.png" );
    }
    else if( getGameClass()->getDifficulty() == HARD)
            drawCenter (520-2, 90-2, "SelectedSingleH.png");
    else
        drawCenter( 520-2, 90-2, "SingleH.png" );

    if (getGameClass()->getDifficulty() == NONE)
        drawCenter( 400,550, "YouShouldChoose.png");

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
bool SelectSingleScene::keyEvent(QKeyEvent * input){

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
bool SelectSingleScene::mouseEvent( int x, int y, MouseFunction function )
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


                if( ButtonSwim.contains( x, y ) )
                {
                    if(getGameClass()->getDifficulty() == NONE) return false;
                    clickButtonSwim();
                    return true;
                }

                if( ButtonBasket.contains( x, y ) )
                {
                    if(getGameClass()->getDifficulty() == NONE) return false;
                    clickButtonBasket();
                    return true;
                }

                if( ButtonSoccer.contains(x,y))
                   {
                    if(getGameClass()->getDifficulty() == NONE) return false;
                    clickButtonSoccer();
                    return true;
                }




        }

        return false;
}

void SelectSingleScene::clickButtonEasy()
{
    getGameClass()->setDifficulty(EASY);
}
void SelectSingleScene::clickButtonNormal()
{
    getGameClass()->setDifficulty(NORMAL);
}
void SelectSingleScene::clickButtonHard()
{
    getGameClass()->setDifficulty(HARD);
}

void SelectSingleScene::clickButtonSwim()
{
    nextScene = new CharacterScene( getGameClass() );
}

void SelectSingleScene::clickButtonBasket()
{
    nextScene= new basketballscene(getGameClass());
}


void SelectSingleScene::clickButtonSoccer()
{
    nextScene= new soccerscene(getGameClass());
}

void SelectSingleScene::clickBackButton(){
    nextScene = new NewScene( getGameClass() );

}

