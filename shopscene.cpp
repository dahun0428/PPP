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
    for(int i=0; i<5; i++)
        BuyButton[i] = QRect( 40+150*i, 190, 120, 120);

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

    for(int i=0; i<5; i++)
        drawText( 70+150*i, 330, priceText[i]);

    if( BuyButton[0].contains( lastCursor ) )
        drawCenter( 100, 250, "Pobba.png");
    else
        drawCenter( 100-2, 250-2, "Pobba.png");

    if(BuyButton[1].contains( lastCursor ) )
        drawCenter( 250, 250, "Kaiser.png" );
    else
        drawCenter( 250-2, 250-2, "Kaiser.png" );

    if( BuyButton[2].contains( lastCursor ) )
        drawCenter( 400, 250, "Swimmer.png" );
    else
        drawCenter( 400-2, 250-2, "Swimmer.png" );

    if( BuyButton[3].contains( lastCursor ) )
        drawCenter( 550, 250, "Physics.png" );
    else
        drawCenter( 550-2, 250-2, "Physics.png" );

    if( BuyButton[4].contains( lastCursor ) )
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
            for(int i=0; i<5; i++) {
                if( BuyButton[i].contains( x, y ) ) {
                    clickBuyButton(i);
                    return true;
                }
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

bool ShopScene::keyEvent(QKeyEvent * input){

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
void ShopScene::clickBuyButton(int index) {
    if( getGameClass()->getCharacterAvailable(index) ) {
        // display already purchased.
    }
    else if( getGameClass()->getPoint() < price[index] ) {
        // display no money.
    }
    else {
        getGameClass()->setPoint( getGameClass()->getPoint() - price[index] );
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
