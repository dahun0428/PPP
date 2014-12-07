#include"singleresultscene.h"
#include "Game.h"
#include "qlabel.h"
#include <string>
#include <sstream>
singleResultScene::singleResultScene(Game * game, int _score) : Scene(game)
{
    nextScene = NULL;

    ButtonNext = QRect( 550, 400, 150, 70 );

    pre_score = getGameClass()->getHistory();
    new_score = _score;
    pre_point = getGameClass()->getPoint();

    // new point update
    if (getGameClass()->getGametype() == SWIMMING) {
        new_point = 200000/new_score;
        if (new_point > 50)
            new_point = 50;
    }
    else if (getGameClass()->getGametype() == BASKETBALL) {
        if (getGameClass()->getSingleDifficulty() == EASY)
            new_point = new_score*5;
        else if (getGameClass()->getSingleDifficulty() == NORMAL)
            new_point = new_score*10;
        else if (getGameClass()->getSingleDifficulty() == HARD)
            new_point = new_score*15;
    }
    else if (getGameClass()->getGametype() == SOCCER) {
        if (getGameClass()->getSingleDifficulty() == EASY)
            new_point = new_score*3;
        else if (getGameClass()->getSingleDifficulty() == NORMAL)
            new_point = new_score*6;
        else if (getGameClass()->getSingleDifficulty() == HARD)
            new_point = new_score*10;
    }
    else {
        if (getGameClass()->getSingleDifficulty() == EASY)
            new_point = new_score*2;
        else if (getGameClass()->getSingleDifficulty() == NORMAL)
            new_point = new_score*3;
        else if (getGameClass()->getSingleDifficulty() == HARD)
            new_point = new_score*5;
    }

    //scoretext="t";
    ScoreFont.setFamily("SansSerif");
    ScoreFont.setPointSize(20);
    ScoreFont.setStretch(160);

    PointFont.setFamily("SansSerif");
    PointFont.setPointSize(15);
    PointFont.setStretch(160);
}
singleResultScene::~singleResultScene()
{

}
Scene* singleResultScene::update()
{
    draw( 0, 0, "White.png" );
    draw(50,100,"Single_Result.png");

    //Score print
    if (getGameClass()->getGametype() == SWIMMING) {
        QString temp;
        drawText(220,420,temp.sprintf("%.2f",((double)new_score)/1000), ScoreFont);
        if (pre_score < 0) {
            drawText(200,260,QString("-"), ScoreFont);
            drawCenter(350,370,"new_record.png",0.6);
        }
        else {
            drawText(220,260,temp.sprintf("%.2f",((double)pre_score)/1000), ScoreFont);
            if (new_score<pre_score)
                drawCenter(350,370,"new_record.png",0.6);
        }
    }
    else {
        drawText(200,260,QString("%1").arg(pre_score), ScoreFont);
        drawText(220,420,QString("%1").arg(new_score),ScoreFont);
        if (new_score>pre_score)
            drawCenter(350,400,"new_record.png",0.6);
    }

    // point print
    drawText(450,215,QString("%1").arg(pre_point),PointFont);
    drawText(450,260,QString("%1").arg(new_point),PointFont);
    drawText(450,300,QString("%1").arg(pre_point+new_point),PointFont);


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
    //point, Best
    getGameClass()->setNewHistory(new_score);
    getGameClass()->setPoint(pre_point+new_point);
    nextScene = new SelectSingleScene(getGameClass());
}
