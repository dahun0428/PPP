#include "savescene.h"
#include "StartScene.h"
#include "newScene.h" // tb
#include "qfile.h" // tb
#include "Game.h"
#include "qlabel.h"
#include "selectsinglescene.h"
#include "selectscene.h"
SaveScene::SaveScene( Game* game, enum SavePoint _sp) : Scene( game )
{

    nextScene = NULL;


    Button1 = QRect( 130, 140, 540, 60 );
    Button2 = QRect( 130, 240, 540, 60 );
    Button3 = QRect( 130, 340, 540, 60 );
    Button4 = QRect( 130, 440, 540, 60 );
    BackButton = QRect ( 50, 50, 40, 40 );
    alertButton = QRect( 260, 270, 120, 100 );

    FilePath = "C:\\Qt\\Tools\\QtCreator\\bin\\PPP\\Resources\\";

    for(int i=0; i<4; i++) {
        filename[i] = "None.png";
    }

    if(QFile::exists(FilePath+"Save\\save_data1"))
        filename[0] =  "data1.png";
    if(QFile::exists(FilePath+"Save\\save_data2"))
        filename[1] =  "data2.png";
    if(QFile::exists(FilePath+"Save\\save_data3"))
        filename[2] =  "data3.png";
    if(QFile::exists(FilePath+"Save\\save_data4"))
        filename[3] =  "data4.png";

    sp = _sp;
}
SaveScene::~SaveScene()
{

}
Scene* SaveScene::update()
{
    draw( 0, 0, "White.png" );


    if( Button1.contains( lastCursor ) )
        drawCenter( 400, 170, filename[0] );
    else
        drawCenter( 400-2, 170-2, filename[0] );

    if( Button2.contains( lastCursor ) )
        drawCenter( 400, 270, filename[1] );
    else
        drawCenter( 400-2, 270-2, filename[1] );

    if( Button3.contains( lastCursor ) )
        drawCenter( 400, 370, filename[2] );
    else
        drawCenter( 400-2, 370-2, filename[2] );

    if( Button4.contains( lastCursor ) )
        drawCenter( 400, 470, filename[3] );
    else
        drawCenter( 400-2, 470-2, filename[3] );


    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 70-2, 70-2, "Back.png" );



    return nextScene;
}
bool SaveScene::mouseEvent( int x, int y, MouseFunction function )
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

bool SaveScene::keyEvent(QKeyEvent * input){

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
void SaveScene::clickButton1()
{
    // game save
    Game* pg = getGameClass();
    pg->saveGame(FilePath+"Save\\save_data1");
    switch(sp) {
        case NEW:
            nextScene = new NewScene( getGameClass() );
            break;
        case SINGLESELECT:
            nextScene = new SelectSingleScene( getGameClass() );
            break;
        case OLYMPICSELECT:
            nextScene = new SelectScene( getGameClass() );
            break;
    }
}

void SaveScene::clickButton2()
{
    // game save
    Game* pg = getGameClass();
    pg->saveGame(FilePath+"Save\\save_data2");
    switch(sp) {
        case NEW:
            nextScene = new NewScene( getGameClass() );
            break;
        case SINGLESELECT:
            nextScene = new SelectSingleScene( getGameClass() );
            break;
        case OLYMPICSELECT:
            nextScene = new SelectScene( getGameClass() );
            break;
    }
}

void SaveScene::clickButton3()
{
    // game save
    Game* pg = getGameClass();
    pg->saveGame(FilePath+"Save\\save_data3");
    switch(sp) {
        case NEW:
            nextScene = new NewScene( getGameClass() );
            break;
        case SINGLESELECT:
            nextScene = new SelectSingleScene( getGameClass() );
            break;
        case OLYMPICSELECT:
            nextScene = new SelectScene( getGameClass() );
            break;
    }
}

void SaveScene::clickButton4()
{
    // game save
    Game* pg = getGameClass();
    pg->saveGame(FilePath+"Save\\save_data4");
    switch(sp) {
        case NEW:
            nextScene = new NewScene( getGameClass() );
            break;
        case SINGLESELECT:
            nextScene = new SelectSingleScene( getGameClass() );
            break;
        case OLYMPICSELECT:
            nextScene = new SelectScene( getGameClass() );
            break;
    }
}

void SaveScene::clickBackButton(){
    switch(sp) {
        case NEW:
            nextScene = new NewScene( getGameClass() );
            break;
        case SINGLESELECT:
            nextScene = new SelectSingleScene( getGameClass() );
            break;
        case OLYMPICSELECT:
            nextScene = new SelectScene( getGameClass() );
            break;
    }

}
