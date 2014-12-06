#include "CharacterScene.h"
#include "qlabel.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "SwimScene.h"
#include "basketballscene.h"
#include "soccerscene.h"
#include "quizscene.h"
#include "Game.h"

CharacterScene::CharacterScene(Game * game) : Scene(game)
{
    nextScene = NULL;
    for(int i=0; i<3; i++)
        CharacterButton[i] = QRect( 40+150*i, 190, 120, 120);
    for(int i=3; i<6; i++)
        CharacterButton[i] = QRect( 40+150*(i-3), 340, 120, 120);
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
}
CharacterScene::~CharacterScene()
{

}

Scene* CharacterScene::update()
{
    draw( 0, 0, "White.png" );

    if( CharacterButton[0].contains( lastCursor ) )
        drawCenter( 100, 250, "DefaultCharacter.png");
    else
        drawCenter( 100-2, 250-2, "DefaultCharacter.png");

    if(CharacterButton[1].contains( lastCursor ) )
        drawCenter( 250, 250, "Pobba.png" );
    else
        drawCenter( 250-2, 250-2, "Pobba.png" );

    if( CharacterButton[2].contains( lastCursor ) )
        drawCenter( 400, 250, "Kaiser.png" );
    else
        drawCenter( 400-2, 250-2, "Kaiser.png" );

    if( CharacterButton[3].contains( lastCursor ) )
        drawCenter( 100, 400, "Swimmer.png" );
    else
        drawCenter( 100-2, 400-2, "Swimmer.png" );

    if( CharacterButton[4].contains( lastCursor ) )
        drawCenter( 250, 400, "Physics.png" );
    else
        drawCenter( 250-2, 400-2, "Physics.png" );

    if( CharacterButton[5].contains( lastCursor ) )
        drawCenter( 400, 400, "DeptTop.png" );
    else
        drawCenter( 400-2, 400-2, "DeptTop.png" );

    if( BackButton.contains( lastCursor ) )
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    return nextScene;
}
bool CharacterScene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:
            for(int i=0; i<6; i++) {
                if( CharacterButton[i].contains( x, y ) ) {
                    clickCharacterButton(i);
                    return true;
                }
            }

            if( BackButton.contains( x, y ) )
            {
                clickBackButton();
                return true;
            }
    }

    return false;
}

bool CharacterScene::keyEvent(QKeyEvent * input){

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
void CharacterScene::clickCharacterButton(int index) {
    if( getGameClass()->getCharacterAvailable(index) ) {
        getGameClass()->setCharacterInUse(static_cast<CharacterType>(index));
        switch(getGameClass()->getGametype()) {
        case SWIMMING:
            nextScene = new SwimScene( getGameClass() );
            break;
        case BASKETBALL:
            nextScene = new basketballscene( getGameClass() );
            break;
        case SOCCER:
            nextScene = new soccerscene( getGameClass() );
            break;
        case QUIZ:
            nextScene = new QuizScene( getGameClass() );
            break;
        }
    }
}
void CharacterScene::clickBackButton(){
    if( getGameClass()->getGamemode() == OLYMPIC )
        nextScene = new SelectScene( getGameClass() );
    else
        nextScene = new SelectSingleScene( getGameClass() );
}
