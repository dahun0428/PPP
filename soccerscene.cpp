#include "soccerscene.h"
#include <QGlobal.h>
#include <string>
#include <sstream>
#include "qlabel.h"
#include <QKeyEvent>



soccerscene::soccerscene(Game* game) : Scene( game )
{

    nextScene = NULL;
    keeper=0;
    t=0;
    state=0;
    score=0;
   // scoretext = intToQString(score);


    Button1 = QRect( 180, 450, 40, 40 );
    Button2 = QRect( 380, 450, 40, 40 );
    Button3 = QRect ( 580, 450, 40, 40);
    BackButton = QRect ( 50, 50, 40, 40 );
    //alertButton = QRect( 260, 270, 120, 100 );
}

Scene* soccerscene::update()
{
    draw( 0, 0, "soccerBG2.png" );
    draw(300,0,"soccerscore.png");
    drawText(400,0,scoretext);

    switch(state){
    case 0:
        drawCenter(400, 300, "goalnett.png" );
        drawCenter(400, 325, "keeper2.png" );

        if( Button1.contains( lastCursor ) )
            drawCenter( 200, 470, "soccerb1.png" );
        else
            drawCenter( 200-2, 470-2, "soccerb1.png" );

        if( Button2.contains( lastCursor ) )
            drawCenter( 380, 470, "soccerb2.png" );
        else
            drawCenter( 380-2, 470-2, "soccerb2.png" );

        if( Button3.contains( lastCursor ) )
            drawCenter( 580, 470, "soccerb3.png" );
        else
            drawCenter( 580-2, 470-2, "soccerb3.png" );

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
            drawCenter(300,300,"leftkeeper.png");
        else
            drawCenter(500,300,"rightkeeper.png");
        drawCenter(400-t,450-2*t,"soccerball.png");
        t++;
        if(t>35&&keeper!=(state-1)){
            drawCenter(400,550,"goal.png");
        }
        if(t==70){
            state=0;
            t=0;

        }
        break;
    case 2:




        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 290, "keeper2.png" );
        else if(keeper==0)
            drawCenter(300,300,"leftkeeper.png");
        else
            drawCenter(500,300,"rightkeeper.png");

        drawCenter(400,450-3*t,"soccerball.png");
        t++;
        if(t>35&&keeper!=(state-1)){
            drawCenter(400,550,"goal.png");
        }
        if(t==70){
            state=0;
            t=0;
        }
        break;

    case 3:
        drawCenter(400, 300, "goalnett1.png" );
        if(keeper==1)
            drawCenter(400, 300, "keeper2.png" );
        else if(keeper==0)
            drawCenter(300,300,"leftkeeper.png");
        else
            drawCenter(500,300,"rightkeeper.png");
        drawCenter(400+t,450-2*t,"soccerball.png");
        t++;
        if(t>35&&keeper!=(state-1)){
            drawCenter(400,550,"goal.png");
        }
        if(t==70){
            state=0;
            t=0;
        }
        break;


    }

    return nextScene;
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

    }

    return false;
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
void soccerscene::clickButton1()

{
    keeper=qrand()%3;
    state=1;
    if(keeper!=(state-1)){
        score++;
     //   scoretext = intToQString(score);
    }
}
void soccerscene::clickButton2()
{
    keeper=qrand()%3;
    state=2;
    if(keeper!=(state-1)){
        score++;
      //  scoretext = intToQString(score);
    }

}
void soccerscene::clickButton3(){
    keeper=qrand()%3;
    state=3;
    if(keeper!=(state-1)){
        score++;
     //   scoretext = intToQString(score);
    }
}
void soccerscene::clickBackButton(){
    nextScene = new StartScene( getGameClass() );


}



