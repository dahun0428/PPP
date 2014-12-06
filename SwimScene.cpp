#include "SwimScene.h"
#include "singleresultscene.h"
#include "selectscene.h"
#include "Game.h"
#include <string>
#include <sstream>

SwimScene::SwimScene( Game* game) : Scene(game)
{
    nextScene = NULL;
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
    lastKey = Qt::Key_unknown;
    timer.start();
    elapsedTime = 0;

    if( getGameClass()->getGamemode() == SINGLE )
        numOfPlayers = 4;   // development mode
    else
        numOfPlayers = 4;

    player = new Character [numOfPlayers];
    swimFactor = new double[numOfPlayers];
    position = new double[numOfPlayers];
    swimmerShapeCount = new int[numOfPlayers];

    switch( getGameClass()->getCharacterInUse() ) {
    case POBBA:
        player[0] = Pobba();
        break;
    case KAISER:
        player[0] = Kaiser();
        break;
    case SWIMMER:
        player[0] = Swimmer();
        break;
    case PHYSICS:
        player[0] = Physics();
        break;
    case DEPTTOP:
        player[0] = Depttop();
        break;
    case STUDENT:
    default:
        player[0] = Character();
        break;
    }
        player[1] = Gist();   // development mode

        player[2] = Unist();
        player[3] = Gist();
    if( getGameClass()->getGamemode() == OLYMPIC ) {

        player[2] = Unist();
        player[3] = Gist();
    }

    for(int i=0; i<numOfPlayers; i++) {
        swimFactor[i] = player[i].getSpeed();
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

    for(int i=0; i<numOfPlayers; i++) {
        position[i] = 0.0;
        swimmerShapeCount[i] = i;
    }
    finishPosition = 600.0;
    userSwimCount = 0;
    opponentSwimCount = 0;
}
SwimScene::~SwimScene() {
    delete[] player;
    delete[] swimFactor;
    delete[] swimmerShapeCount;
    delete[] position;
}

Scene* SwimScene::update()
{
    draw( 0, 0, "White.png" );
    draw( 10, 200, "Pool.png");
    drawCenter( 630, 550, "SwimTimer.png" );

    elapsedTime = timer.elapsed();
    drawText( 610, 550, doubleToQString(static_cast<double>(elapsedTime) / 1000) );

    if( userSwimCount >= diff ) {
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
    for(int i=0; i<numOfPlayers; i++) {
        switch(swimmerShapeCount[i]) {
        case 0:
            drawCenter( 175 + position[i], 235 + 70*i, "SpinSlot1.png");
            break;
        case 1:
            drawCenter( 175 + position[i], 235 + 70*i, "SpinSlot2.png");
            break;
        case 2:
            drawCenter( 175 + position[i], 235 + 70*i, "SpinSlot3.png");
            break;
        case 3:
        default:
            drawCenter( 175 + position[i], 235 + 70*i, "SpinSlot4.png");
            break;
        }
    }
    if( BackButton.contains(lastCursor) )
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    if(isFinished()) {
        storeResult();
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
    switch(input->key()){           // 0x01000012 is left arrow
    case 0x01000012:                // 0x01000014 is right arrow
        if(lastKey == 0x01000014) {
            userSwimCount++;
            swimmerShapeCount[0]++;
            if(swimmerShapeCount[0]>3)
                swimmerShapeCount[0] = 0;
        }
        lastKey = 0x01000012;
        return true;
    case 0x01000014:
        if(lastKey == 0x01000012) {
            userSwimCount++;
            swimmerShapeCount[0]++;
            if(swimmerShapeCount[0]>3)
                swimmerShapeCount[0] = 0;
        }
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
void SwimScene::opponentSwim() {
    double range = static_cast<double>(RAND_MAX/3);
    double swimDistance;
    for(int i=1; i<numOfPlayers; i++) {
        swimDistance = (static_cast<double>(rand()) / range)*swimFactor[i];
        position[i] += swimDistance;
        swimmerShapeCount[i]++;
        if(swimmerShapeCount[i]>3)
            swimmerShapeCount[i] = 0;
    }
}

void SwimScene::clickBackButton()
{
    if( getGameClass()->getGamemode() == SINGLE )
        nextScene = new SelectSingleScene( getGameClass() );
    else
        nextScene = new SelectScene( getGameClass() );
}

bool SwimScene::isFinished() {
    for(int i=0; i<numOfPlayers; i++) {
        if(position[i] >= finishPosition)
            return true;
    }
    return false;
}

void SwimScene::storeResult() {
    getGameClass()->setScore(elapsedTime);
    if( getGameClass()->getGamemode() == SINGLE ) {
        getGameClass()->setNewHistory(elapsedTime);
        nextScene = new singleResultScene( getGameClass() );
    }
    else {
        nextScene = new SelectScene( getGameClass() );
    }
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
