#include "loadscene.h"
#include "StartScene.h"
#include "newScene.h" // tb
#include "qfile.h" // tb
#include "Game.h"
#include "qlabel.h"

LoadScene::LoadScene( Game* game) : Scene( game )
{
    nextScene = NULL;


    Button1 = QRect( 78, 168, 140, 140 );
    Button2 = QRect( 201, 310, 140, 140 );
    Button3 = QRect( 453, 304, 140, 140 );
    Button4 = QRect ( 576, 166, 140, 140);
    BackButton = QRect ( 50, 50, 40, 40 );

    FilePath = "C:\\Qt\\Tools\\QtCreator\\bin\\PPP\\Resources\\";

    for(int i=0; i<4; i++) {
        filename[i] = "None.png";
        load[i] = false;
    }



    if(QFile::exists(FilePath+"Save\\save_data1")) {
        filename[0] =  "data1.png";
        load[0] = true;
    }
    if(QFile::exists(FilePath+"Save\\save_data2")) {
        filename[1] =  "data2.png";
        load[1] = true;
    }
    if(QFile::exists(FilePath+"Save\\save_data3")) {
        filename[2] =  "data3.png";
        load[2] = true;
    }
    if(QFile::exists(FilePath+"Save\\save_data4")) {
        filename[3] =  "data4.png";
        load[3] = true;
    }


}
LoadScene::~LoadScene()
{

}
Scene* LoadScene::update()
{
    draw( 0, 0, "White.png" );

    if( Button1.contains( lastCursor ) )
        drawCenter( 138, 248, filename[0] );
    else
        drawCenter( 138-2, 248-2, filename[0] );

    if( Button2.contains( lastCursor ) )
        drawCenter( 271, 380, filename[1] );
    else
        drawCenter( 271-2, 380-2, filename[1] );

    if( Button3.contains( lastCursor ) )
        drawCenter( 523, 374, filename[2] );
    else
        drawCenter( 523-2, 374-2, filename[2] );

    if( Button4.contains( lastCursor ) )
        drawCenter( 646, 236, filename[3] );
    else
        drawCenter( 646-2, 236-2, filename[3] );


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

            if( Button3.contains( x, y ) )
            {
                clickButton3();
                return true;
            }

            if( Button4.contains( x, y ) )
            {
                clickButton4();
                return true;
            }

            if( BackButton.contains(x,y)){
                clickBackButton();
                return true;
            }

    }

    return false;
}
bool LoadScene::keyEvent(QKeyEvent * input){

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
void LoadScene::clickButton1()
{
    if(load[0]) {
        // game load
        Game* pg = getGameClass();

        pg->loadGame(FilePath+"Save\\save_data1");
        nextScene = new NewScene( getGameClass() );
    }
}

void LoadScene::clickButton2()
{
    if(load[1]) {
        // game load
        Game* pg = getGameClass();

        pg->loadGame(FilePath+"Save\\save_data2");
        nextScene = new NewScene( getGameClass() );
    }
}

void LoadScene::clickButton3()
{
    if(load[2]) {
        // game load
        Game* pg = getGameClass();

        pg->loadGame(FilePath+"Save\\save_data3");
        nextScene = new NewScene( getGameClass() );
    }
}

void LoadScene::clickButton4()
{
    if(load[3]) {
        // game load
        Game* pg = getGameClass();

        pg->loadGame(FilePath+"Save\\save_data4");
        nextScene = new NewScene( getGameClass() );
    }
}

void LoadScene::clickBackButton(){
    nextScene = new StartScene( getGameClass() );
}
