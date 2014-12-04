#include "CharacterScene.h"
#include "qlabel.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "SwimScene.h"
#include "Game.h"

CharacterScene::CharacterScene(Game * game) : Scene(game)
{
    nextScene = NULL;
    for(int i=0; i<5; i++)
        CharacterButton[i] = QRect( 40+150*i, 190, 120, 120);
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
        drawCenter( 100, 250, "Pobba.png");
    else
        drawCenter( 100-2, 250-2, "Pobba.png");

    if(CharacterButton[1].contains( lastCursor ) )
        drawCenter( 250, 250, "Kaiser.png" );
    else
        drawCenter( 250-2, 250-2, "Kaiser.png" );

    if( CharacterButton[2].contains( lastCursor ) )
        drawCenter( 400, 250, "Swimmer.png" );
    else
        drawCenter( 400-2, 250-2, "Swimmer.png" );

    if( CharacterButton[3].contains( lastCursor ) )
        drawCenter( 550, 250, "Physics.png" );
    else
        drawCenter( 550-2, 250-2, "Physics.png" );

    if( CharacterButton[4].contains( lastCursor ) )
        drawCenter( 700, 250, "DeptTop.png" );
    else
        drawCenter( 700-2, 250-2, "DeptTop.png" );

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
            for(int i=0; i<5; i++) {
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
        nextScene = new SwimScene( getGameClass() );
    }
    else {
        nextScene = new SelectSingleScene( getGameClass() );
    }
}
void CharacterScene::clickBackButton(){
    if( getGameClass()->getGamemode() == OLYMPIC )
        nextScene = new SelectScene( getGameClass() );
    else
        nextScene = new SelectSingleScene( getGameClass() );
}
