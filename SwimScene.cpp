#include "SwimScene.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "Game.h"

SwimScene::SwimScene( Game* game) : Scene(game)
{
    nextScene = NULL;

    Button1 = QRect( 315, 525, 170, 70 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );

    if( getGameClass()->getGamemode() == OLYMPIC)
        numOfPlayers = 5;
    else
        numOfPlayers = 2;

    switch( getGameClass()->getDifficulty() ) {
    case EASY:
        opponentSwimFactor = 1.0;
        break;
    case NORMAL:
        opponentSwimFactor = 2.0;
        break;
    case HARD:
        opponentSwimFactor = 3.0;
        break;
    default:
        opponentSwimFactor = 2.0;
        break;
    }

    position = new double[numOfPlayers];
    for(int i=0; i<numOfPlayers; i++) {
        position[i] = 0.0;
    }
    finishPosition = 600.0;
    opponentSwimCount = 0;
}
SwimScene::~SwimScene() {}

Scene* SwimScene::update()
{
    draw( 0, 0, "White.png" );
    draw(60, 110, "Pool.png");
    opponentSwimCount++;
    if(opponentSwimCount == 5) {
        opponentSwim();
        opponentSwimCount = 0;
    }
    for(int i=0; i<numOfPlayers; i++)
        drawCenter( 100 + position[i], 150 + 80*i, "SwimCharacter.png");

    if( Button1.contains( lastCursor ) )
        drawCenter( 400, 560, "Swim.png" );
    else
        drawCenter( 400-2, 560-2, "Swim.png" );

    if( BackButton.contains(lastCursor) )
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );
    if(isFinished()) {
        if( getGameClass()->getGamemode() == OLYMPIC)
            nextScene = new SelectScene( getGameClass() );
        else
            nextScene = new SelectSingleScene( getGameClass() );
    }
    return nextScene;
}
bool SwimScene::mouseEvent( int x, int y, MouseFunction function )
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
            if( BackButton.contains( x, y ) )
            {
                clickBackButton();
                return true;
            }
    }

    return false;
}
bool SwimScene::keyEvent(QKeyEvent * input) {
    return false;
}

void SwimScene::clickButton1()
{
    position[0] += 10.0;
}
void SwimScene::clickBackButton()
{
    if( getGameClass()->getGamemode() == OLYMPIC )
        nextScene = new SelectScene( getGameClass() );
    else
        nextScene = new SelectSingleScene( getGameClass() );
}

void SwimScene::opponentSwim() {
    double range = static_cast<double>(RAND_MAX/3);
    double swimDistance;
    for(int i=1; i<numOfPlayers; i++) {
        swimDistance = (static_cast<double>(rand()) / range)*opponentSwimFactor;
        position[i] += swimDistance;
    }
}
bool SwimScene::isFinished() {
    for(int i=0; i<numOfPlayers; i++) {
        if(position[i] >= finishPosition) {
            winnderIndex = i;
            return true;
        }
    }
    return false;
}
