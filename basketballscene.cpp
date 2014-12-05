#include "basketballscene.h"
#include <QGlobal.h>
#include <string>
#include <sstream>
#include "qlabel.h"
#include"selectsinglescene.h"
#include"singleresultscene.h"
#include"olympicresultscene.h"


basketballscene::basketballscene(Game *game) : Scene(game)
{
    nextScene=NULL;
    score=0;
    updown=true;
    state=0;
    life=3;
    scoretext=intToQString(score);
    BackButton = QRect ( 50, 50, 40, 40 );
    bx=0;
    by=0;
    bv=0;

    bdir=0;
    t=0;
    t2=0;
    check=true;

    enum Difficulty diff;
    if (getGameClass()->getGamemode() == SINGLE)
        diff = getGameClass()->getSingleDifficulty();
    else
        diff = getGameClass()->getOlympicDifficulty();

    if(diff==EASY)
        bx0=BXE;
    else if(diff==NORMAL)
        bx0=BXN;
    else
        bx0=BXH;

    mode=game->getGamemode();
    //newFont.setBold(true);
    newFont.setFamily("SansSerif");
    newFont.setPointSize(15);

}
QString basketballscene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
bool basketballscene::keyEvent(QKeyEvent * input){
    lastKeyInput = input;
    lastKey = input->key();
    if(nextScene !=NULL)
        return false;

    switch(lastKey){



            case 0x20:
            if(state==0){
                check=true;
                state=1;
                t=0;
                updown=true;
            }
            else if(state==1){
                bv=t;
                t=0;
                updown=true;
                state=2;
            }
            else if(state==2){
                bdir=t;
                bvx=bv*bdir/50;
                if(bvx>bv/2)
                    bvy=5*(bv-bvx)/2;
                else
                    bvy=bv-2*bvx/5;
                bvx=bvx/2;
                bvy=bvy/2;

                t=0;
                updown=true;
                state=3;
            }
            else if(state==3){
                ;
            }
            else{

                state=0;//지워야됌
                t=0;
                bx=0;
                by=0;
                updown=true;
            }
            break;
            return true;
    default:
        break;

    }
    return false;



}


Scene* basketballscene::update()
{
    if(life==0){
        //getGameClass()->setScore(score);
        if(mode==SINGLE) {
            getGameClass()->setScore(score);
            nextScene = new singleResultScene(getGameClass());
        }
        else
            nextScene = new OlympicResultScene(getGameClass());
    }

    draw( 0, 0, "basketballBG.png" );
    draw(300,0,"soccerscore.png");
    if(life==3)
        drawCenter(760,30,"basketball.png");
    if(life>=2)
        drawCenter(710,30,"basketball.png");

    if( BackButton.contains(lastCursor))
        drawCenter( 70, 70, "Back.png" );
    else
        drawCenter( 68, 68, "Back.png" );


    scoretext=intToQString(score);
    drawText(400,30,scoretext,newFont);
    switch(state){
    case 0:
        drawCenter(bx0,BY,"basketball.png");
        break;


    case 1:
        drawCenter(bx0,BY,"basketball.png");
        drawCenter(bx0+30,BY-85,"powergauge.png");
        drawCenter(bx0+40,BY-3*t,"powercursor.png");
        if(updown&&t==50)
            updown=false;
        else if(updown==false&&t==0)
            updown=true;
        if(updown)
            t++;
        else
            t--;
        break;
    case 2:
        drawCenter(bx0,BY,"basketball.png");
        drawCenter(bx0-50,BY-85,"anglebar.png");
        if(t<25)
            drawCenter(bx0-5-t,BY-85+2*t/5,"dot.png");
        else
            drawCenter(bx0-17-t/2,BY-90+t,"dot.png");
        if(updown&&t==50)
            updown=false;
        else if(updown==false&&t==0)
            updown=true;
        if(updown)
            t++;
        else
            t--;
        break;
    case 3:
        if(t==3){
            t=0;
            updown=true;
            bx=bx+bvx;
            by=by+bvy;
            bvy=bvy-GRAV;
        }


        drawCenter(bx0-bx,BY-by,"basketball.png");
        t++;
        if(by>92&&by<190&&bx>(bx0-180)&&bx<(bx0-125)&&bvx>0)
            bvx=-9*bvx/10;
        if(by<125&&by>110){
            if(bx<(bx0-180)&&bx>(bx0-220)){
                if(bvy<0&&check){
                    check=false;
                    score++;
                    scoretext=intToQString(score);
                    drawText(400,30,scoretext);
                    bvy=bvy/2;
                    bvx=bvx/3;
                }
            }
        }
        if(by<-160||bx>bx0){
            bx=0;
            by=0;
            if(check==true)
                life--;
            state=0;
        }


    default:
        break;
    }





    return nextScene;
}
bool basketballscene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:


            if( BackButton.contains(x,y))
            {
                clickBackButton();
                return true;
            }


    }
    return false;


}
void basketballscene::clickBackButton(){

    nextScene = new StartScene( getGameClass() );


}
