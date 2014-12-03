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

    Button1 = QRect( 670, 265, 60, 170 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );

}
GambleScene::~GambleScene() {}

Scene* GambleScene::update()
{
    draw( 0, 0, "White.png" );

    drawCenter( 660, 70, "Points.png");
    pointText = intToQString(getGameClass()->getPoint());
    drawText( 680, 78, pointText);
    drawCenter( 160, 300, "GambleSlot1.png");
    drawCenter( 330, 300, "GambleSlot1.png");
    drawCenter( 490, 300, "GambleSlot1.png");

    if( Button1.contains( lastCursor ) )
        drawCenter( 700, 350, "Pull1.png" );
    else
        drawCenter( 700-2, 350-2, "Pull1.png" );

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
void GambleScene::clickButton1()
{

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
