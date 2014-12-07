#include "olympicresultscene.h"
#include "Game.h"
#include "qlabel.h"
#include "historyscene.h"
#include <string>
#include <sstream>


OlympicResultScene::OlympicResultScene(Game * game, int _scores[4]) : Scene(game)
{
    nextScene = NULL;

    ButtonNext = QRect( 550, 400, 150, 70 );

    ScoreFont.setFamily("SansSerif");
    ScoreFont.setPointSize(15);
    ScoreFont.setStretch(160);
    PointFont.setFamily("SansSerif");
    PointFont.setPointSize(15);
    PointFont.setStretch(160);

    for(int i=0; i<4; i++)
        scores[i] = _scores[i];
    pre_point = getGameClass()->getPoint();

    // new point update
    if (getGameClass()->getGametype() == SWIMMING) {
        new_point = 200000/_scores[0];
        if (new_point > 50)
            new_point = 50;
    }
    else if (getGameClass()->getGametype() == BASKETBALL) {
        if (getGameClass()->getOlympicDifficulty() == EASY)
            new_point = scores[0]*5;
        else if (getGameClass()->getOlympicDifficulty() == NORMAL)
            new_point = scores[0]*10;
        else if (getGameClass()->getOlympicDifficulty() == HARD)
            new_point = scores[0]*15;
    }
    else if (getGameClass()->getGametype() == SOCCER) {
        if (getGameClass()->getOlympicDifficulty() == EASY)
            new_point = scores[0]*3;
        else if (getGameClass()->getOlympicDifficulty() == NORMAL)
            new_point = scores[0]*6;
        else if (getGameClass()->getOlympicDifficulty() == HARD)
            new_point = scores[0]*10;
    }
    else {
        if (getGameClass()->getOlympicDifficulty() == EASY)
            new_point = scores[0]*2;
        else if (getGameClass()->getOlympicDifficulty() == NORMAL)
            new_point = scores[0]*3;
        else if (getGameClass()->getOlympicDifficulty() == HARD)
            new_point = scores[0]*5;
    }

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

    int ypos[4] = {200, 280, 360, 440};
    drawCenter(130, ypos[0], "postech.png", 0.8);
    drawCenter(130, ypos[1], "kaist.png", 0.8);
    drawCenter(130, ypos[2], "unist.png", 0.8);
    drawCenter(130, ypos[3], "gist.png", 0.8);

    if (getGameClass()->getGametype() == SWIMMING) {
        QString tmp;
        drawText(175, ypos[0]+10, tmp.sprintf("%.2f",(double)scores[0]/1000.0), PointFont);
        drawText(175, ypos[1]+10, tmp.sprintf("%.2f",(double)scores[1]/1000.0), PointFont);
        drawText(175, ypos[2]+10, tmp.sprintf("%.2f",(double)scores[2]/1000.0), PointFont);
        drawText(175, ypos[3]+10, tmp.sprintf("%.2f",(double)scores[3]/1000.0), PointFont);
    }
    else {
        drawText(175, ypos[0]+10, QString("%1").arg(scores[0]), PointFont);
        drawText(175, ypos[1]+10, QString("%1").arg(scores[1]), PointFont);
        drawText(175, ypos[2]+10, QString("%1").arg(scores[2]), PointFont);
        drawText(175, ypos[3]+10, QString("%1").arg(scores[3]), PointFont);
    }

    drawCenter(285, ypos[(int)gold_receiver], "Gold_medal.png");
    drawCenter(285, ypos[(int)silver_receiver], "Silver_medal.png");
    drawCenter(285, ypos[(int)bronze_receiver], "Bronze_medal.png");


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
    Game* pt = getGameClass();
    pt->setPoint(pre_point+new_point);
    pt->getOlympicData(pt->getOlympicCnt())->goldReceive(gold_receiver);
    pt->getOlympicData(pt->getOlympicCnt())->silverReceive(silver_receiver);
    pt->getOlympicData(pt->getOlympicCnt())->bronzeReceive(bronze_receiver);
    bool cmp = pt->getPlayed(SWIMMING) && pt->getPlayed(BASKETBALL)
            && pt->getPlayed(SOCCER) && pt->getPlayed(QUIZ);
    if (cmp) {
        pt->complete();
        nextScene = new HistoryScene(getGameClass());
    }
    else
        nextScene = new SelectScene(getGameClass());
}

void OlympicResultScene::setMedalReceiver() {
    gold_receiver = GIST;
    silver_receiver = GIST;
    bronze_receiver = GIST;
    if (getGameClass()->getGametype() == SWIMMING) {
        for (int i=2; i>=0; i--) {
            if (scores[i] < scores[(int)gold_receiver]) {
                bronze_receiver = silver_receiver;
                silver_receiver = gold_receiver;
                gold_receiver = (enum School)(i);
            }
            else if (scores[i] < scores[(int)silver_receiver]) {
                bronze_receiver = silver_receiver;
                silver_receiver = (enum School)(i);
            }
            else if (scores[i] < scores[(int)bronze_receiver]) {
                bronze_receiver = (enum School)(i);
            }
            if (gold_receiver == silver_receiver) {
                silver_receiver = UNIST;
                bronze_receiver = KAIST;
            }
            if (silver_receiver == bronze_receiver) {
                bronze_receiver = UNIST;
            }
        }
    }
    else {
        for (int i=2; i>=0; i--) {
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
            if (gold_receiver == silver_receiver) {
                silver_receiver = UNIST;
                bronze_receiver = KAIST;
            }
            if (silver_receiver == bronze_receiver) {
                bronze_receiver = (enum School)((int)UNIST-1);
            }
        }
    }
}
