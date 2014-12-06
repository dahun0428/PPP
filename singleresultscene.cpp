#include"singleresultscene.h"
#include "Game.h"
#include "qlabel.h"
#include <string>
#include <sstream>
singleResultScene::singleResultScene(Game * game) : Scene(game)
{
    nextScene = NULL;

    ButtonNext = QRect( 550, 400, 150, 70 );

    //scoretext="t";
    Font1.setFamily("SansSerif");
    Font1.setPointSize(20);
    Font1.setStretch(160);
}
singleResultScene::~singleResultScene()
{

}
Scene* singleResultScene::update()
{
    draw( 0, 0, "White.png" );
    draw(50,100,"Single_Result.png");
    //Score Best pint출력
    scoretext=intToQString(getGameClass()->getScore());
    drawText(220,420,scoretext,Font1);



    if( ButtonNext.contains( lastCursor ) )
        draw(550,400,"NEXT.png");
    else
        draw(550-2,400-2,"NEXT.png");


    return nextScene;
}
bool singleResultScene::mouseEvent( int x, int y, MouseFunction function )
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
bool singleResultScene::keyEvent(QKeyEvent * input){

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
void singleResultScene::clickButtonNext()
{
    //point, Best 처리
    nextScene = new SelectSingleScene(getGameClass());
}
QString singleResultScene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
