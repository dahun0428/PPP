#include "selectsinglescene.h"
#include "Game.h"
#include "qlabel.h"
#include "newScene.h"
#include "CharacterScene.h"
#include "soccerscene.h"
#include "basketballscene.h"
#include "SwimScene.h"
#include "savescene.h"

SelectSingleScene::SelectSingleScene(Game * game) : Scene(game)
{
    nextScene = NULL;


    ButtonSwim = QRect( 78, 168, 140, 140 );
    ButtonBasket = QRect( 201, 310, 140, 140 );
    ButtonSoccer = QRect( 453, 304, 140, 140 );
    ButtonQuiz = QRect ( 576, 166, 140, 140);


    BackButton = QRect ( 50, 50, 40, 40 );


    ButtonEasy = QRect( 300, 70, 40, 60 );
    ButtonNormal = QRect( 400, 70, 50, 60 );
    ButtonHard = QRect( 500, 70, 50, 60 );

    SaveButton = QRect ( 650, 50, 40, 40);


    getGameClass()->setGamemode(SINGLE);
    getGameClass()->setSingleDifficulty(NONE);
}
SelectSingleScene::~SelectSingleScene()
{

}
Scene* SelectSingleScene::update()
{
    draw( 0, 0, "White.png" );



    if( ButtonEasy.contains( lastCursor ) ){
        if( getGameClass()->getSingleDifficulty() == EASY)
                    drawCenter (296, 90, "SelectedSingleE.png");
        else
            drawCenter( 296, 90, "SingleE.png" );
    }
    else if( getGameClass()->getSingleDifficulty() == EASY)
            drawCenter (296-2, 90-2, "SelectedSingleE.png");
    else
        drawCenter( 296-2, 90-2, "SingleE.png" );

    if( ButtonNormal.contains( lastCursor ) ){
        if( getGameClass()->getSingleDifficulty() == NORMAL)
                    drawCenter (396, 90, "SelectedSingleN.png");
        else
            drawCenter( 396, 90, "SingleN.png" );
    }
    else if( getGameClass()->getSingleDifficulty() == NORMAL)
            drawCenter (396-2, 90-2, "SelectedSingleN.png");
    else
        drawCenter( 396-2, 90-2, "SingleN.png" );

    if( ButtonHard.contains( lastCursor ) ){
        if( getGameClass()->getSingleDifficulty() == HARD)
            drawCenter( 496, 90, "SelectedSingleH.png" );
        else drawCenter( 496, 90, "SingleH.png" );
    }
    else if( getGameClass()->getSingleDifficulty() == HARD)
            drawCenter (496-2, 90-2, "SelectedSingleH.png");
    else
        drawCenter( 496-2, 90-2, "SingleH.png" );



        if( ButtonSwim.contains( lastCursor ) )
            drawCenter( 148, 238, "Swim.png" );
        else
            drawCenter( 148-2, 238-2, "Swim.png" );

        if( ButtonBasket.contains( lastCursor ) )
            drawCenter( 271, 380, "Basket.png" );
        else
            drawCenter( 271-2, 380-2, "Basket.png" );

        if( ButtonSoccer.contains( lastCursor ) )
            drawCenter( 523, 374, "Soccer.png" );
        else
            drawCenter( 523-2, 374-2, "Soccer.png" );

        if( ButtonQuiz.contains( lastCursor ) )
            drawCenter( 646, 236, "Quiz.png" );
        else
            drawCenter( 646-2, 236-2, "Quiz.png" );

        if (getGameClass()->getSingleDifficulty() == NONE)
            drawCenter( 400,380, "YouShouldChoose.png");

<<<<<<< HEAD


=======
>>>>>>> quiz

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    if( SaveButton.contains( lastCursor ) )
        drawCenter( 670-2, 70, "Save.png" );
    else
        drawCenter( 670-3, 70-1, "Save.png" );



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
                    if(getGameClass()->getSingleDifficulty() == NONE) return false;
                    clickButtonSwim();
                    return true;
                }

                if( ButtonBasket.contains( x, y ) )
                {
                    if(getGameClass()->getSingleDifficulty() == NONE) return false;
                    clickButtonBasket();
                    return true;
                }

                if( ButtonSoccer.contains(x,y))
                   {
                    if(getGameClass()->getSingleDifficulty() == NONE) return false;
                    clickButtonSoccer();
                    return true;
                }

                if( ButtonQuiz.contains(x,y))
                   {
                    if(getGameClass()->getSingleDifficulty() == NONE) return false;
                    clickButtonSoccer();
                    return true;
                }

                if( SaveButton.contains(x, y)) {
                    clickSaveButton();
                    return true;
                }




        }

        return false;
}

void SelectSingleScene::clickButtonEasy()
{
    getGameClass()->setSingleDifficulty(EASY);
}
void SelectSingleScene::clickButtonNormal()
{
    getGameClass()->setSingleDifficulty(NORMAL);
}
void SelectSingleScene::clickButtonHard()
{
    getGameClass()->setSingleDifficulty(HARD);
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

void SelectSingleScene::clickButtonQuiz()
{

    nextScene= new soccerscene(getGameClass()); // quizscene

}

void SelectSingleScene::clickBackButton(){
    nextScene = new NewScene( getGameClass() );

}

void SelectSingleScene::clickSaveButton(){
    nextScene = new SaveScene( getGameClass(), SINGLESELECT);
}


