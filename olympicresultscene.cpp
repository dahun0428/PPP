#include "olympicresultscene.h"
#include "Game.h"
#include "qlabel.h"
#include <string>
#include <sstream>


OlympicResultScene::OlympicResultScene(Game * game, int _scores[4]) : Scene(game)
{
    nextScene = NULL;

    ButtonNext = QRect( 550, 400, 150, 70 );

    for(int i=0; i<4; i++)
        scores[i] = _scores[i];
    pre_point = getGameClass()->getPoint();
    new_point = scores[0]*10;
    // played update
    getGameClass()->setPlayed(getGameClass()->getGametype());

    //setting medal receuver
    setMedalReceiver();
}
OlympicResultScene::~OlympicResultScene()
{

}
Scene* OlympicResultScene::update()
{
    draw( 0, 0, "White.png" );
    draw(50,100,"Olympic_Result.png");
    //point print
    drawText(450,215,QString("%1").arg(pre_point),PointFont);
    drawText(450,260,QString("%1").arg(new_point),PointFont);
    drawText(450,300,QString("%1").arg(pre_point+new_point),PointFont);



    if( ButtonNext.contains( lastCursor ) )
        draw(550,400,"NEXT.png");
    else
        draw(550-2,400-2,"NEXT.png");


    return nextScene;
}
bool OlympicResultScene::mouseEvent( int x, int y, MouseFunction function )
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
bool OlympicResultScene::keyEvent(QKeyEvent * input){

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
void OlympicResultScene::clickButtonNext()
{
    nextScene = new SelectScene(getGameClass());
}

void OlympicResultScene::setMedalReceiver() {
    gold_receiver = GIST;
    silver_receiver = GIST;
    bronze_receiver = GIST;
    if (getGameClass()->getGamemode() == SWIMMING) {

    }
    else {
        for (int i=3; i>=0; i--) {
            if (scores[i] > scores[(int)gold_receiver]) {
                bronze_receiver = silver_receiver;
                silver_receiver = gold_receiver;
                gold_receiver = (enum School)(i);
            }
            else if (scores[i] > scores[(int)silver_receiver]) {
                bronze_receiver = silver_receiver;
                silver_receiver = (enum School)(i);
            }
            else if (scores[i] > scores[(int)bronze_receiver]) {
                bronze_receiver = (enum School)(i);
            }
        }
    }
}
