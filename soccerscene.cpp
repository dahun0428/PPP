#include "soccerscene.h"
#include <QGlobal.h>
#include <string>
#include <sstream>
#include "qlabel.h"
#include <QKeyEvent>
#include"Game.h"
#include"singleresultscene.h"
#include"selectsinglescene.h"
#include"olympicresultscene.h"





soccerscene::soccerscene(Game* game) : Scene( game )
{

    nextScene = NULL;
    keeper=0;
    t=0;
    state=0;
    score=0;
    life=3;
    if (game->getGamemode() == SINGLE)
        Diff = game->getSingleDifficulty();
    else
        Diff = game->getOlympicDifficulty();

    if(Diff==EASY)
        Dir=5;
    else if(Diff==NORMAL)
        Dir=3;
    else
        Dir=2;
    mode=game->getGamemode();
    enable=true;

   // scoretext = intToQString(score);


    Button1 = QRect( 180, 450, 40, 40 );
    Button2 = QRect( 380, 450, 40, 40 );
    Button3 = QRect ( 580, 450, 40, 40);
    Button4 = QRect ( 280, 450, 40, 40);
    Button5 = QRect ( 480, 450, 40, 40);
    BackButton = QRect ( 50, 50, 40, 40 );
    //alertButton = QRect( 260, 270, 120, 100 );
    newFont.setFamily("SansSerif");
    newFont.setPointSize(15);
}

Scene* soccerscene::update()
{
    if(life==0&&enable){
        getGameClass()->setScore(score);
        if(mode==SINGLE)
            nextScene = new singleResultScene(getGameClass());
        else
            nextScene = new OlympicResultScene(getGameClass());
    }
    draw( 0, 0, "soccerBG2.png" );
    draw(300,0,"soccerscore.png");
    drawText(400,30,scoretext,newFont);
    if(life==3)
        drawCenter(760,30,"soccerball.png");
    if(life>=2)
        drawCenter(710,30,"soccerball.png");

    switch(state){
    case 0:
        drawCenter(400, 300, "goalnett.png" );
        drawCenter(400, 325, "keeper2.png" );

        if( Button1.contains( lastCursor ) )
            drawCenter( 200, 470, "soccerb1.png" );
        else
            drawCenter( 200-2, 470-2, "soccerb1.png" );
        if(Dir!=2){
            if( Button2.contains( lastCursor ) )
                drawCenter( 400, 470, "soccerb2.png" );
            else
                drawCenter( 400-2, 470-2, "soccerb2.png" );
        }

        if( Button3.contains( lastCursor ) )
            drawCenter( 600, 470, "soccerb3.png" );
        else
            drawCenter( 600-2, 470-2, "soccerb3.png" );
        if(Dir==5){
            if( Button4.contains( lastCursor ) )
                drawCenter( 300, 470, "soccerb4.png" );
            else
                drawCenter( 300-2, 470-2, "soccerb4.png" );
            if( Button5.contains( lastCursor ) )
                drawCenter( 500, 470, "soccerb5.png" );
            else
                drawCenter( 500-2, 470-2, "soccerb5.png" );
        }

        if( BackButton.contains(lastCursor))
            drawCenter( 70, 70, "Back.png" );
        else
            drawCenter( 70-2, 70-2, "Back.png" );
        break;
    case 1:
        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(330,350,"leftkeeper.png");
        else if(keeper==2)
            drawCenter(520,350,"rightkeeper.png");
        else if(keeper==3)
            drawCenter(300,300,"leftupkeeper.png");
        else if(keeper==4)
            drawCenter(450,300,"rightupkeeper.png");
        drawCenter(400-2*t,450-t,"soccerball.png",1-t/140.00);
        t++;
        if(t>35){
            if(keeper!=(state-1)){
                drawCenter(400,550,"goal.png");
            }
            else
                drawCenter(400,550,"Block.png");
        }
        if(t==70){
            enable=true;
            state=0;
            t=0;
            scoretext=intToQString(score);

        }
        break;
    case 2:




        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(330,350,"leftkeeper.png");
        else if(keeper==2)
            drawCenter(520,350,"rightkeeper.png");
        else if(keeper==3)
            drawCenter(300,300,"leftupkeeper.png");
        else if(keeper==4)
            drawCenter(450,300,"rightupkeeper.png");

        drawCenter(400,450-3*t,"soccerball.png",1-t/140.00);
        t++;
        if(t>35){
            if(keeper!=(state-1)){
                drawCenter(400,550,"goal.png");
            }
            else
                drawCenter(400,550,"Block.png");
        }
        if(t==70){
            enable=true;
            state=0;
            t=0;
            scoretext=intToQString(score);
        }
        break;

    case 3:
        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(330,350,"leftkeeper.png");
        else if(keeper==2)
            drawCenter(520,350,"rightkeeper.png");
        else if(keeper==3)
            drawCenter(300,300,"leftupkeeper.png");
        else if(keeper==4)
            drawCenter(450,300,"rightupkeeper.png");
        drawCenter(400+2*t,450-t,"soccerball.png",1-t/140.00);
        t++;
        if(t>35){
            if(keeper!=(state-1)){
                drawCenter(400,550,"goal.png");
            }
            else
                drawCenter(400,550,"Block.png");
        }
        if(t==70){
            enable=true;
            state=0;
            t=0;
            scoretext=intToQString(score);
        }
        break;
    case 4:
        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(330,350,"leftkeeper.png");
        else if(keeper==2)
            drawCenter(520,350,"rightkeeper.png");
        else if(keeper==3)
            drawCenter(300,300,"leftupkeeper.png");
        else if(keeper==4)
            drawCenter(450,300,"rightupkeeper.png");
        drawCenter(400-t,450-2*t,"soccerball.png",1-t/140.00);
        t++;
        if(t>35){
            if(keeper!=(state-1)){
                drawCenter(400,550,"goal.png");
            }
            else
                drawCenter(400,550,"Block.png");
        }
        if(t==70){
            enable=true;
            state=0;
            t=0;
            scoretext=intToQString(score);
        }
        break;
    case 5:
        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(330,350,"leftkeeper.png");
        else if(keeper==2)
            drawCenter(520,350,"rightkeeper.png");
        else if(keeper==3)
            drawCenter(300,300,"leftupkeeper.png");
        else if(keeper==4)
            drawCenter(450,300,"rightupkeeper.png");
        drawCenter(400+t,450-2*t,"soccerball.png",1-t/140.00);
        t++;
        if(t>35){
            if(keeper!=(state-1)){
                drawCenter(400,550,"goal.png");
            }
            else
                drawCenter(400,550,"Block.png");
        }
        if(t==70){
            enable=true;
            state=0;
            t=0;
            scoretext=intToQString(score);
        }
        break;




    }

    return nextScene;
}
bool soccerscene::keyEvent(QKeyEvent * input){

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
bool soccerscene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:
        if(enable){

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

            if( Button3.contains(x,y))
               {
                clickButton3();
                return true;
            }
            if( Button4.contains(x,y))
               {
                clickButton4();
                return true;
            }
            if( Button5.contains(x,y))
               {
                clickButton5();
                return true;
            }
        }

    }

    return false;
}

void soccerscene::clickButton1()

{
    enable=false;
    keeper=qrand()%Dir;
    if(Dir==2)
        keeper=keeper*2;

    state=1;
    if(keeper!=(state-1)){
        score++;
     //  supersave
    }
    else
        life--;
}
void soccerscene::clickButton2()
{
    enable=false;
    if(Dir==2)
        return ;
    keeper=qrand()%Dir;

    state=2;
    if(keeper!=(state-1)){
        score++;
      //  supersave
    }
    else
        life--;

}
void soccerscene::clickButton3(){
    enable=false;
    keeper=qrand()%Dir;
    if(Dir==2)
        keeper=keeper*2;
    state=3;
    if(keeper!=(state-1)){
        score++;
     // supersave

    }
    else
        life --;
}
void soccerscene::clickButton4(){
    enable=false;
    if(Dir!=5)
        return ;
    keeper=qrand()%Dir;
    if(Dir==2)
        keeper=keeper*2;
    state=4;
    if(keeper!=(state-1)){
        score++;
     //supersave
    }
    else
        life;;
}
void soccerscene::clickButton5(){
    enable=false;
    if(Dir!=5)
        return ;
    keeper=qrand()%Dir;

    state=5;
    if(keeper!=(state-1)){
        score++;
     //   supersave
    }
    else
        life--;
}
void soccerscene::clickBackButton(){
    nextScene = new StartScene( getGameClass() );


}



QString soccerscene::intToQString(int n) {
    std::stringstream tempStrs;
    std::string temp;
    QString tempQStr;
    tempStrs << n;
    temp = tempStrs.str();
    tempQStr = temp.c_str();
    return tempQStr;
}
