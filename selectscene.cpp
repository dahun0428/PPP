#include "selectscene.h"
#include "Game.h"
#include "qlabel.h"
#include "olympicnanido.h"
#include "soccerscene.h"
#include "basketballscene.h"
#include "CharacterScene.h"
#include "savescene.h"

SelectScene::SelectScene(Game * game) : Scene(game)
{
    nextScene = NULL;


    ButtonSwim = QRect( 78, 168, 140, 140 );
    ButtonBasket = QRect( 201, 310, 140, 140 );
    ButtonSoccer = QRect( 453, 304, 140, 140 );
    ButtonQuiz = QRect ( 576, 166, 140, 140);

    BackButton = QRect ( 50, 50, 40, 40 );
    SaveButton = QRect ( 650, 50, 40, 40);
    getGameClass()->setGamemode(OLYMPIC);
}
SelectScene::~SelectScene()
{

}
Scene* SelectScene::update()
{
    draw( 0, 0, "White.png" );


    if( ButtonSwim.contains( lastCursor ) ) {
        drawCenter( 148, 238, "Swim.png" );
        if (getGameClass()->getPlayed(SWIMMING))
            drawCenter(198, 188, "check.png", 0.25);
    }
    else {
        drawCenter( 148-2, 238-2, "Swim.png" );
        if (getGameClass()->getPlayed(SWIMMING))
            drawCenter(198-2, 188-2, "check.png", 0.25);
    }

    if( ButtonBasket.contains( lastCursor ) ) {
        drawCenter( 271, 380, "Basket.png" );
        if (getGameClass()->getPlayed(BASKETBALL))
            drawCenter(321, 330, "check.png", 0.25);
    }
    else {
        drawCenter( 271-2, 380-2, "Basket.png" );
        if (getGameClass()->getPlayed(BASKETBALL))
            drawCenter(321-2, 330-2, "check.png", 0.25);
    }

    if( ButtonSoccer.contains( lastCursor ) ) {
        drawCenter( 523, 374, "Soccer.png" );
        if (getGameClass()->getPlayed(SOCCER))
            drawCenter(573, 324, "check.png", 0.25);
    }
    else {
        drawCenter( 523-2, 374-2, "Soccer.png" );
        if (getGameClass()->getPlayed(SOCCER))
            drawCenter(573-2, 324-2, "check.png", 0.25);
    }

    if( ButtonQuiz.contains( lastCursor ) ) {
        drawCenter( 646, 236, "Quiz.png" );
        if (getGameClass()->getPlayed(QUIZ))
            drawCenter(696, 186, "check.png", 0.25);
    }
    else {
        drawCenter( 646-2, 236-2, "Quiz.png" );
        if (getGameClass()->getPlayed(QUIZ))
            drawCenter(696-2, 186-2, "check.png", 0.25);
    }

    if( SaveButton.contains( lastCursor ) )
        drawCenter( 670-2, 70, "Save.png" );

    else
        drawCenter( 670-3, 70-1, "Save.png" );


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

            if( ButtonQuiz.contains(x, y))
            {
                clickButtonQuiz();
                return true;
            }

            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }

            if( SaveButton.contains(x,y))
               {
                clickSaveButton();
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
    if (!getGameClass()->getPlayed(SWIMMING)) {
        getGameClass()->setGametype(SWIMMING);
        nextScene = new CharacterScene( getGameClass() );
    }
}

void SelectScene::clickButtonBasket()
{
    if (!getGameClass()->getPlayed(BASKETBALL)) {
        getGameClass()->setGametype(BASKETBALL);
        nextScene = new CharacterScene( getGameClass() );
    }
}


void SelectScene::clickButtonSoccer()
{
    if (!getGameClass()->getPlayed(SOCCER)) {
        getGameClass()->setGametype(SOCCER);
        nextScene = new CharacterScene( getGameClass() );
    }
}

void SelectScene::clickButtonQuiz()
{
    if (!getGameClass()->getPlayed(QUIZ)) {
        getGameClass()->setGametype(QUIZ);
        nextScene = new CharacterScene( getGameClass() );
    }
}

void SelectScene::clickBackButton(){
    nextScene = new OlympicNanido( getGameClass() );

}

void SelectScene::clickSaveButton(){
    nextScene = new SaveScene( getGameClass(), OLYMPICSELECT );
}
