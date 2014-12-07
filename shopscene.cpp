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
    price[0] = 1500;
    price[1] = 1500;
    price[2] = 2000;
    price[3] = 1000;
    price[4] = 5000;
    for(int i=0; i<5; i++) {
        if(getGameClass()->getCharacterAvailable(i+1))
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
    Font1.setPointSize(18);
    Font1.setFamily("SansSerif");
    Font2.setPointSize(15);
    Font2.setFamily("SansSerif");

}
ShopScene::~ShopScene()
{

}

Scene* ShopScene::update()
{
    draw( 0, 0, "White.png" );

    drawCenter( 660, 70, "Points.png");
    pointText = intToQString(getGameClass()->getPoint());


    drawText( 680, 78, pointText,Font1);

    for(int i=0; i<5; i++)
        drawText( 50+150*i, 330, priceText[i],Font2);
    if(!(getGameClass()->getCharacterAvailable(1))){
        if( BuyButton[0].contains( lastCursor ) )
            drawCenter( 100, 250, "unknown.png");
        else
            drawCenter( 100-2, 250-2, "unknown.png");

    }
    else{

        if( BuyButton[0].contains( lastCursor ) )
            drawCenter( 100, 250, "Pobba.png");
        else
           drawCenter( 100-2, 250-2, "Pobba.png");
    }
    if(!(getGameClass()->getCharacterAvailable(2))){
        if(BuyButton[1].contains( lastCursor ) )
            drawCenter( 250, 250, "unknown.png" );
        else
            drawCenter( 250-2, 250-2, "unknown.png" );
    }
    else{
        if(BuyButton[1].contains( lastCursor ) )
            drawCenter( 250, 250, "Kaiser.png" );
        else
            drawCenter( 250-2, 250-2, "Kaiser.png" );
    }
    if(!(getGameClass()->getCharacterAvailable(3))){
        if( BuyButton[2].contains( lastCursor ) )
            drawCenter( 400, 250, "unknown.png" );
        else
            drawCenter( 400-2, 250-2, "unknown.png" );
    }
    else{
        if( BuyButton[2].contains( lastCursor ) )
            drawCenter( 400, 250, "Swimmer.png" );
        else
            drawCenter( 400-2, 250-2, "Swimmer.png" );
    }
    if(!(getGameClass()->getCharacterAvailable(4))){
        if( BuyButton[3].contains( lastCursor ) )
            drawCenter( 550, 250, "unknown.png" );
        else
            drawCenter( 550-2, 250-2, "unknown.png" );

    }
    else{
        if( BuyButton[3].contains( lastCursor ) )
            drawCenter( 550, 250, "Physics.png" );
        else
            drawCenter( 550-2, 250-2, "Physics.png" );
    }
    if(!(getGameClass()->getCharacterAvailable(5))){
        if( BuyButton[4].contains( lastCursor ) )
            drawCenter( 700, 250, "unknown.png" );
        else
            drawCenter( 700-2, 250-2, "unknown.png" );

    }
    else{
        if( BuyButton[4].contains( lastCursor ) )
            drawCenter( 700, 250, "DeptTop.png" );
        else
            drawCenter( 700-2, 250-2, "DeptTop.png" );
    }

    if( GambleButton.contains( lastCursor ) )
        drawCenter( 700, 500, "Gamble.png");
    else
        drawCenter( 700-2, 500-2, "Gamble.png");
    drawText(660,580,"Gamble",Font2);

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
    if( getGameClass()->getCharacterAvailable(index+1) ) {
        // display already purchased.
    }
    else if( getGameClass()->getPoint() < price[index] ) {
        // display no money.
    }
    else {
        getGameClass()->setPoint( getGameClass()->getPoint() - price[index] );
        getGameClass()->setCharacterAvailable(index+1, true);
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
