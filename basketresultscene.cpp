#include"basketresultscene.h"
#include "Game.h"
#include "qlabel.h"
#include "selectsinglescene.h"
#include <string>
#include <sstream>
basketResultScene::basketResultScene(Game * game) : Scene(game)
{
    nextScene = NULL;

    ButtonNext = QRect( 550, 400, 150, 70 );

    //scoretext="t";
}
basketResultScene::~basketResultScene()
{

}
Scene* basketResultScene::update()
{
    draw( 0, 0, "White.png" );
    draw(50,100,"Single_Result.png");
    //Score Best pint출력
    scoretext=intToQString(getGameClass()->getScore());
    drawText(220,415,scoretext);



    if( ButtonNext.contains( lastCursor ) )
        draw(550,400,"NEXT.png");
    else
        draw(550-2,400-2,"NEXT.png");


    return nextScene;
}
bool basketResultScene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:

            if( ButtonNext.contains( x, y ) )
            {
                clickButtonNext();
                return true;
            }


    }

    return false;
}
bool basketResultScene::keyEvent(QKeyEvent * input){

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
void basketResultScene::clickButtonNext()
{
    //point, Best 처리
    nextScene = new SelectSingleScene(getGameClass());
}
QString basketResultScene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
