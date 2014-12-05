#include "quizscene.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "Game.h"
#include "Character.h"

QuizScene::QuizScene( Game* game) : Scene(game)
{
    nextScene = NULL;

    lastKey = Qt::Key_unknown;

    if( getGameClass()->getGamemode() == OLYMPIC )
        numOfPlayers = 4;
    else
        numOfPlayers = 1;

    scores = new int [numOfPlayers];
    player = new Character[numOfPlayers];
    player[0] = Character();
    if( getGameClass()->getGamemode() == OLYMPIC ) {
        player[1] = Kaist();
        player[2] = Unist();
        player[3] = Gist();
        // score initializing
        scores[1] = qrand()%10;
        scores[2] = qrand()%10;
        scores[3] = qrand()%10;
    }

    // playtime initializing
    Character playingcharacter = getGameClass()->getRealCharacterInUse();
    playtime = playingcharacter.getIntelligence()*4.0;

    enum Difficulty diff;
    if (getGameClass()->getGamemode() == SINGLE)
        diff = getGameClass()->getSingleDifficulty();
    else
        diff = getGameClass()->getOlympicDifficulty();

    operators[0] = "+";
    operators[1] = "-";
    operators[2] = "*";
    operators[3] = "/";
    // quiz problems and answers setting
    if (diff == EASY) {
        for (int i=0; i<100; i++) {
            int x; // one digits
            int y; // one digits
            int op; // 0:+, 1:-, 2:*, 3:/
            x = qrand()%10;
            y = qrand()%10;
            op = qrand()%4;

        }
    }
    else if (diff == NORMAL) {

    }
    else {

    }
}
QuizScene::~QuizScene() {
    delete[] player;
}

Scene* QuizScene::update()
{
    draw( 0, 0, "White.png" );
    draw(60, 110, "Pool.png");

    return nextScene;
}
bool QuizScene::mouseEvent( int x, int y, MouseFunction function )
{
    lastCursor.setX( x );
    lastCursor.setY( y );

    if(nextScene != NULL)
        return false;

    switch( function )
    {
        case MOUSE_CLICK:
            break;
    }

    return false;
}
bool QuizScene::keyEvent(QKeyEvent* input){
    if(nextScene != NULL)
        return false;

    switch(input->key()){
    case 'A':
        break;
    default:
        break;
    }
    //lastKeyInput = input;
    lastKey = input->key();
    return false;
}
