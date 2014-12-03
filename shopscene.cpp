#include "shopscene.h"
#include "qlabel.h"
#include "newScene.h"
#include "loadscene.h"


ShopScene::ShopScene(Game * game) : Scene(game)
{
    nextScene = NULL;

     Button1 = QRect( 310, 200, 180, 80 );
     BackButton = QRect ( 50, 50, 40, 40 );

}

ShopScene::~ShopScene()
{

}
Scene* ShopScene::update()
{
    draw( 0, 0, "White.png" );


    /*if( Button1.contains( lastCursor ) )
        drawCenter( 400, 240, "ThisisShop.png" );
    else*/
        drawCenter( 400, 240, "ThisisShop.png" );

  /*  if( Button2.contains( lastCursor ) )
        drawCenter( 400, 340, "Continue.png" );
    else
        drawCenter( 400-2, 340-2, "Continue.png" );*/

    if( BackButton.contains(lastCursor))
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
                clickButton1();
                return true;
            }

        /*	if( Button2.contains( x, y ) )
            {
                clickButton2();
                return true;
            }
*/
            if( BackButton.contains( x, y ) )
            {
                clickBackButton();
                return true;
            }
    }

    return false;
}
void ShopScene::clickButton1()
{
  //  nextScene = new NewScene( getGameClass() );

}

void ShopScene::clickButton2()
{
    nextScene = new LoadScene( getGameClass() );
}

void ShopScene::clickBackButton(){
    nextScene = new NewScene( getGameClass() );

}
