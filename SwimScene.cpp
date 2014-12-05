#include "SwimScene.h"
#include "basketresultscene.h"
#include "selectscene.h"
#include "Game.h"
#include <string>
#include <sstream>

SwimScene::SwimScene( Game* game) : Scene(game)
{
    nextScene = NULL;

    Button1 = QRect( 315, 525, 170, 70 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
    lastKey = Qt::Key_unknown;
    timer.start();
    elapsedTime = 0;
    finishedCount = 0;

    if( getGameClass()->getGamemode() == SINGLE )
        numOfPlayers = 2;
    else
        numOfPlayers = 4;

    player = new Character* [numOfPlayers];
    swimFactor = new double[numOfPlayers];
    position = new double[numOfPlayers];

    switch( getGameClass()->getCharacterInUse() ) {
    case POBBA:
        player[0] = new Pobba;
        break;
    case KAISER:
        player[0] = new Kaiser;
        break;
    case SWIMMER:
        player[0] = new Swimmer;
        break;
    case PHYSICS:
        player[0] = new Physics;
        break;
    case DEPTTOP:
        player[0] = new Depttop;
        break;
    case STUDENT:
    default:
        player[0] = new Character;
        break;
    }
        player[1] = new Gist;
    if( getGameClass()->getGamemode() == OLYMPIC ) {

        player[2] = new Unist;
        player[3] = new Gist;
    }

    for(int i=0; i<numOfPlayers; i++) {
        swimFactor[i] = player[i]->getSpeed();
    }
    if( getGameClass()->getCharacterInUse() == SWIMMER )
        swimFactor[0] *= 6.0;
    else
        swimFactor[0] *= 3.0;

    if (getGameClass()->getGamemode() == SINGLE)
        diff = getGameClass()->getSingleDifficulty();
    else
        diff = getGameClass()->getOlympicDifficulty();

    switch( diff ) {
    case EASY:
        for(int i=1; i<numOfPlayers; i++)
            swimFactor[i] *= 0.5;
        break;
    case NORMAL:
    default:
        for(int i=1; i<numOfPlayers; i++)
            swimFactor[i] *= 0.7;
        break;
    case HARD:
        for(int i=1; i<numOfPlayers; i++)
            swimFactor[i] *= 1.0;
        break;
    }

    for(int i=0; i<numOfPlayers; i++)
        position[i] = 0.0;
    finishPosition = 600.0;
    userSwimCount = 0;
    opponentSwimCount = 0;
}
SwimScene::~SwimScene() {}

Scene* SwimScene::update()
{
    draw( 0, 0, "White.png" );
    draw( 60, 110, "Pool.png");
    elapsedTime = timer.elapsed();
    drawText( 200, 400, doubleToQString(static_cast<double>(elapsedTime) / 1000) );

    if( userSwimCount >= diff + 1) {
        userSwim();
        userSwimCount = 0;
    }
//    if( getGameClass()->getGamemode() == OLYMPIC ) {
        opponentSwimCount++;
        if(opponentSwimCount == 5) {
            opponentSwim();
            opponentSwimCount = 0;
        }
//    }
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
        finishedCount++;
        getGameClass()->setScore(elapsedTime);
        if( getGameClass()->getGamemode() == SINGLE ) {
            delete player;
            delete swimFactor;
            delete position;
            nextScene = new basketResultScene( getGameClass() );
        }
        else {
            delete player;
            delete swimFactor;
            delete position;
            nextScene = new SelectScene( getGameClass() );
        }
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
                userSwim();
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
bool SwimScene::keyEvent(QKeyEvent* input){
    if(nextScene != NULL)
        return false;
    switch(input->key()){
    case 0x01000012:
        if(lastKey == 0x01000014)
            userSwimCount++;
        lastKey = 0x01000012;
        return true;
    case 0x01000014:
        if(lastKey == 0x01000012)
            userSwimCount++;
        lastKey = 0x01000014;
        return true;
    default:
        break;
    }
    lastKey = input->key();
    return false;
}

void SwimScene::userSwim()
{
    position[0] += swimFactor[0];
}
void SwimScene::clickBackButton()
{
    if( getGameClass()->getGamemode() == SINGLE )
        nextScene = new SelectSingleScene( getGameClass() );
    else
        nextScene = new SelectScene( getGameClass() );
    delete player;
    delete swimFactor;
    delete position;
}

void SwimScene::opponentSwim() {
    double range = static_cast<double>(RAND_MAX/3);
    double swimDistance;
    for(int i=1; i<numOfPlayers; i++) {
        swimDistance = (static_cast<double>(rand()) / range)*swimFactor[i];
        position[i] += swimDistance;
    }
}
bool SwimScene::isFinished() {
    for(int i=0; i<numOfPlayers; i++) {
        if(position[i] >= finishPosition)
            return true;
    }
    return false;
}

QString SwimScene::doubleToQString(double n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
