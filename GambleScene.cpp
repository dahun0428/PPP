#include "GambleScene.h"
#include "shopscene.h"
#include "Game.h"
#include <string>
#include <sstream>

GambleScene::GambleScene( Game* game) : Scene(game)
{
    nextScene = NULL;
    pointText = intToQString(getGameClass()->getPoint());
    gambleCost = 500;
    spinCount = 0;
    for(int i=0; i<3; i++) {
        spinSlot[i] = 0;
        spinSlotShapeName[i] = "SpinSlot";
    }
    Button1 = QRect( 670, 265, 60, 170 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
    newFont.setPointSize(18);
    newFont.setFamily("SansSerif");

}
GambleScene::~GambleScene() {}

Scene* GambleScene::update()
{
    draw( 0, 0, "White.png" );

    drawCenter( 660, 70, "Points.png");
    pointText = intToQString(getGameClass()->getPoint());
    drawText( 680, 78, pointText,newFont);

    if( spinCount == 0 ) {
        drawCenter( 160, 300, "SpinSlot.png");
        drawCenter( 330, 300, "SpinSlot.png");
        drawCenter( 490, 300, "SpinSlot.png");
    }
    else {
        spinCount++;
        if( spinCount < 50 ) {
            drawCenter( 160, 300, spinSlotShapeName[0]);
            drawCenter( 330, 300, "SpinSlot.png");
            drawCenter( 490, 300, "SpinSlot.png");
        }
        else if( spinCount < 100 ) {
            drawCenter( 160, 300, spinSlotShapeName[0]);
            drawCenter( 330, 300, spinSlotShapeName[1]);
            drawCenter( 490, 300, "SpinSlot.png");
        }
        else if( spinCount < 170 ) {
            drawCenter( 160, 300, spinSlotShapeName[0]);
            drawCenter( 330, 300, spinSlotShapeName[1]);
            drawCenter( 490, 300, spinSlotShapeName[2]);
            showGambleResult();
        }
        else
            finishOneRound();
    }

    drawCenter( 680, 200, "Cost.png");
    drawText( 695, 207, intToQString(gambleCost),newFont);
    if( Button1.contains( lastCursor ) )
        drawCenter( 680, 350, "Pull1.png" );
    else
        drawCenter( 680-2, 350-2, "Pull1.png" );

    if( BackButton.contains( lastCursor ) )
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    return nextScene;
}
bool GambleScene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:

            if( Button1.contains( x, y ) && spinCount == 0 )
            {
                clickButton1();
                return true;
            }
            if( BackButton.contains( x, y ) && spinCount == 0 )
            {
                clickBackButton();
                return true;
            }
    }

    return false;
}

bool GambleScene::keyEvent(QKeyEvent * input){

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
void GambleScene::clickButton1()
{
    if(getGameClass()->getPoint() < gambleCost) {
        // display no money
        getGameClass()->setPoint(getGameClass()->getPoint() + 3000);
    }
    else {
        startOneRound();
    }
}
void GambleScene::clickBackButton()
{
    nextScene = new ShopScene(getGameClass());
}

QString GambleScene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}

void GambleScene::startOneRound() {
    getGameClass()->setPoint(getGameClass()->getPoint() - 500);
    spinCount = 1;
    for(int i=0; i<3; i++) {
        spinSlot[i] = 1 + (rand() % 5);
        spinSlotShapeName[i].append(intToQString(spinSlot[i]));
        spinSlotShapeName[i].append(".png");
    }
}

void GambleScene::finishOneRound() {
    if(spinSlot[0] == spinSlot[1] && spinSlot[0] == spinSlot[2])
        getGameClass()->setPoint(getGameClass()->getPoint() + 3000);
    else if(spinSlot[0] == spinSlot[1] || spinSlot[0] == spinSlot[2] || spinSlot[1] == spinSlot[2])
        getGameClass()->setPoint(getGameClass()->getPoint() + 1500);

    spinCount = 0;
    for(int i=0; i<3; i++) {
        spinSlot[i] = 0;
        spinSlotShapeName[i] = "SpinSlot";
    }
}
void GambleScene::showGambleResult() {
    if(spinSlot[0] == spinSlot[1] && spinSlot[0] == spinSlot[2])
        drawCenter( 275, 450, "Win3000.png");
    else if(spinSlot[0] == spinSlot[1] || spinSlot[0] == spinSlot[2] || spinSlot[1] == spinSlot[2])
        drawCenter( 275, 450, "Win1500.png");
    else
        drawCenter( 275, 450, "LoseMoney.png");
}
