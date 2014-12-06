#include "SwimScene.h"
#include "singleresultscene.h"
#include "olympicresultscene.h"
#include "selectscene.h"
#include "Game.h"
#include <string>
#include <sstream>

SwimScene::SwimScene( Game* game) : Scene(game)
{
    nextScene = NULL;
    alertButton = QRect( 260, 270, 120, 100 );
    lastKey = Qt::Key_unknown;
    timer.start();
    elapsedTime = 0;

    if( getGameClass()->getGamemode() == SINGLE )
        numOfPlayers = 1;
    else
        numOfPlayers = 4;

    player = new Character [numOfPlayers];
    swimFactor = new double[numOfPlayers];
    swimmerShapeCount = new int[numOfPlayers];
    position = new double[numOfPlayers];
    characterImgName = new QByteArray[numOfPlayers];

    switch( getGameClass()->getCharacterInUse() ) {
    case POBBA:
        player[0] = Pobba();
        characterImgName[0] = "pobba_swim";
        break;
    case KAISER:
        player[0] = Kaiser();
        characterImgName[0] = "kaiser_swim";
        break;
    case SWIMMER:
        player[0] = Swimmer();
        characterImgName[0] = "swimmer_swim";
        break;
    case PHYSICS:
        player[0] = Physics();
        characterImgName[0] = "physics_swim";
        break;
    case DEPTTOP:
        player[0] = Depttop();
        characterImgName[0] = "deptTop_swim";
        break;
    case STUDENT:
    default:
        player[0] = Character();
        characterImgName[0] = "default_swim";
        break;
    }
    if( getGameClass()->getGamemode() == OLYMPIC ) {
        player[1] = Kaist();
        //characterImgName[1] = "kaist_swim";
        player[2] = Unist();
        //characterImgName[2] = "unist_swim";
        player[3] = Gist();
        //characterImgName[3] = "gist_swim";
        for(int i=1; i<4; i++)
            characterImgName[i] = "default_swim";   //development mode
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
    finishPosition = 580.0;
    userSwimCount = 0;
    opponentSwimCount = 0;

    finishedPlayerCount = 0;
    for(int i=0; i<4; i++)
        score[i] = 0;
}
SwimScene::~SwimScene() {
    delete[] player;
    delete[] swimFactor;
    delete[] swimmerShapeCount;
    delete[] position;
    delete[] characterImgName;
}

Scene* SwimScene::update()
{
    draw( 0, 100, "Pool.png");
    drawCenter( 120, 550, "SwimTimer.png" );

    elapsedTime = timer.elapsed();
    drawText( 100, 550, doubleToQString(static_cast<double>(elapsedTime) / 1000) );

    if( userSwimCount >= diff ) {
        userSwim();
        userSwimCount = 0;
    }
    if( getGameClass()->getGamemode() == OLYMPIC ) {
        opponentSwimCount++;
        if(opponentSwimCount >= 5) {
            opponentSwim();
            opponentSwimCount = 0;
        }
    }
    for(int i=0; i<numOfPlayers; i++) {
        switch(swimmerShapeCount[i]) {
        case 0:
            drawCenter( 650 - position[i], 235 + 70*i, characterImgName[i] + "1.png");
            break;
        case 1:
            drawCenter( 650 - position[i], 235 + 70*i, characterImgName[i] + "2.png");
            break;
        case 2:
            drawCenter( 650 - position[i], 235 + 70*i, characterImgName[i] + "3.png");
            break;
        case 3:
        default:
            drawCenter( 650 - position[i], 235 + 70*i, characterImgName[i] + "4.png");
            break;
        }
    }
    if(isFinished()) {
        sendResult();
    }
    return nextScene;
}
bool SwimScene::mouseEvent( int x, int y, MouseFunction function )
{
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
    if(position[0] < finishPosition)
        position[0] += swimFactor[0];
}
void SwimScene::opponentSwim() {
    double range = static_cast<double>(RAND_MAX/3);
    for(int i=1; i<numOfPlayers; i++) {
        if(position[i] < finishPosition) {
            position[i] += (static_cast<double>(rand()) / range)*swimFactor[i];
            swimmerShapeCount[i]++;
            if(swimmerShapeCount[i]>3)
                swimmerShapeCount[i] = 0;
        }
    }
}

bool SwimScene::isFinished() {
    if( getGameClass()->getGamemode() == SINGLE ) {
        for(int i=0; i<numOfPlayers; i++)
            if(position[i] >= finishPosition)
                return true;
    }
    else {
        for(int i=0; i<numOfPlayers; i++)
            if(score[i] == 0 && position[i] >= finishPosition ) {
                score[i] = elapsedTime;
                finishedPlayerCount++;
            }
        if(finishedPlayerCount >= 4)
            return true;
    }
    return false;
}

void SwimScene::sendResult() {
    if( getGameClass()->getGamemode() == SINGLE )
        nextScene = new singleResultScene( getGameClass(), elapsedTime );
    else
        nextScene = new OlympicResultScene( getGameClass() );
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
