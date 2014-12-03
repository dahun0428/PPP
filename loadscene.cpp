#include "loadscene.h"
#include "StartScene.h"
#include "qlabel.h"
LoadScene::LoadScene( Game* game) : Scene( game )
{

    nextScene = NULL;


    Button1 = QRect( 130, 140, 540, 60 );
    Button2 = QRect( 130, 240, 540, 60 );
    Button3 = QRect( 130, 340, 540, 60 );
    Button4 = QRect( 130, 440, 540, 60 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );
}
LoadScene::~LoadScene()
{

}
Scene* LoadScene::update()
{
    draw( 0, 0, "White.png" );
    draw( 0, 30, "White.png" );

    if( Button1.contains( lastCursor ) )
        drawCenter( 400, 170, "None.png" );
    else
        drawCenter( 400-2, 170-2, "None.png" );

    if( Button2.contains( lastCursor ) )
        drawCenter( 400, 270, "None.png" );
    else
        drawCenter( 400-2, 270-2, "None.png" );

    if( Button3.contains( lastCursor ) )
        drawCenter( 400, 370, "None.png" );
    else
        drawCenter( 400-2, 370-2, "None.png" );

    if( Button4.contains( lastCursor ) )
        drawCenter( 400, 470, "None.png" );
    else
        drawCenter( 400-2, 470-2, "None.png" );


    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );



    return nextScene;
}
bool LoadScene::mouseEvent( int x, int y, MouseFunction function )
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

            if( Button2.contains( x, y ) )
            {
                clickButton2();
                return true;
            }
            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }

    }

    return false;
}
void LoadScene::clickButton1()
{


}

void LoadScene::clickButton2()
{
}

void LoadScene::clickBackButton(){
    nextScene = new StartScene( getGameClass() );

}
