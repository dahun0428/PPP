#include "shopscene.h"
#include "GambleScene.h"
#include "qlabel.h"
#include "newScene.h"
#include "loadscene.h"
#include "Game.h"
#include <string>
#include <sstream>

ShopScene::ShopScene(Game * game) : Scene(game)
{
    nextScene = NULL;
    pointText = intToQString(getGameClass()->getPoint());
    for(int i=0; i<5; i++) {
        price[i] = (i+1)*500;
        if(getGameClass()->getCharacterAvailable(i))
            priceText[i] = "Purchased";
        else {
            priceText[i] = intToQString(price[i]);
            priceText[i].append(" Points");
        }
    }
    Button1 = QRect( 40, 190, 120, 120 );
    Button2 = QRect( 190, 190, 120, 120 );
    Button3 = QRect( 340, 190, 120, 120 );
    Button4 = QRect( 490, 190, 120, 120 );
    Button5 = QRect( 640, 190, 120, 120 );
    GambleButton = QRect(640, 440, 120, 120);
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
}
ShopScene::~ShopScene()
{

}

Scene* ShopScene::update()
{
    draw( 0, 0, "White.png" );

    drawCenter( 660, 70, "Points.png");
    pointText = intToQString(getGameClass()->getPoint());
    drawText( 680, 78, pointText);

    drawText( 70, 330, priceText[0]);
    drawText( 220, 330, priceText[1]);
    drawText( 370, 330, priceText[2]);
    drawText( 520, 330, priceText[3]);
    drawText( 670, 330, priceText[4]);

    if( Button1.contains( lastCursor ) )
        drawCenter( 100, 250, "Pobba.png");
    else
        drawCenter( 100-2, 250-2, "Pobba.png");

    if( Button2.contains( lastCursor ) )
        drawCenter( 250, 250, "Kaiser.png" );
    else
        drawCenter( 250-2, 250-2, "Kaiser.png" );

    if( Button3.contains( lastCursor ) )
        drawCenter( 400, 250, "Swimmer.png" );
    else
        drawCenter( 400-2, 250-2, "Swimmer.png" );

    if( Button4.contains( lastCursor ) )
        drawCenter( 550, 250, "Physics.png" );
    else
        drawCenter( 550-2, 250-2, "Physics.png" );

    if( Button5.contains( lastCursor ) )
        drawCenter( 700, 250, "DeptTop.png" );
    else
        drawCenter( 700-2, 250-2, "DeptTop.png" );

    if( GambleButton.contains( lastCursor ) )
        drawCenter( 700, 500, "Gamble.png");
    else
        drawCenter( 700-2, 500-2, "Gamble.png");

    if( BackButton.contains( lastCursor ) )
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );

    return nextScene;
}
bool ShopScene::mouseEvent( int x, int y, MouseFunction function )
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
                clickBuyButton(0);
                return true;
            }
            if( Button2.contains( x, y ) )
            {
                clickBuyButton(1);
                return true;
            }
            if( Button3.contains( x, y ) )
            {
                clickBuyButton(2);
                return true;
            }
            if( Button4.contains( x, y ) )
            {
                clickBuyButton(3);
                return true;
            }
            if( Button5.contains( x, y ) )
            {
                clickBuyButton(4);
                return true;
            }
            if( GambleButton.contains( x, y ) )
            {
                clickGambleButton();
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

void ShopScene::clickBuyButton(int index) {
    if(getGameClass()->getCharacterAvailable(index)) {
        // display already purchased.
    }
    else if(getGameClass()->getPoint() < price[index]) {
        // display no money.
    }
    else {
        getGameClass()->setPoint(getGameClass()->getPoint() - price[index]);
        getGameClass()->setCharacterAvailable(index, true);
        priceText[index] = "Purchased";
        // display purchased.
    }
}
void ShopScene::clickGambleButton()
{
    nextScene = new GambleScene( getGameClass() );
}
void ShopScene::clickBackButton(){
    nextScene = new NewScene( getGameClass() );

}

QString ShopScene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
