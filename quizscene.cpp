#include "quizscene.h"
#include "selectsinglescene.h"
#include "selectscene.h"
#include "Game.h"
#include "Character.h"

QuizScene::QuizScene( Game* game) : Scene(game)
{
    nextScene = NULL;

    lastKey = Qt::Key_unknown;

    // font setting
    problemfont.setPointSize(90);
    problemfont.setFamily("Matura MT Script Capitals");
    Scorefont.setPointSize(25);
    Scorefont.setFamily("SansSerif");
    Scorefont.setBold(true);

    // gamemode setting
    if( getGameClass()->getGamemode() == OLYMPIC )
        numOfPlayers = 4;
    else
        numOfPlayers = 1;

    scores = new int [numOfPlayers];
    player = new Character[numOfPlayers];
    player[0] = Character();
    scores[0] = 0;
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
    operators[2] = "×";
    operators[3] = "÷";

    // quiz problems and answers setting
    problemindex = 0;
    equ = "= ";
    ans = "";
    if (diff == EASY) {
        for (int i=0; i<100; i++) {
            int x; // one digits
            int y; // one digits
            int op; // 0:+, 1:-, 2:*, 3:/
            int answer;
            op = qrand()%4;
            x = qrand()%9+1;
            if (op == 0) {
                y = qrand()%9+1;
                answer = x+y;
            }
            else if (op == 1) {
                do {y = qrand()%9+1;} while (y>x);
                answer = x-y;
            }
            else if (op == 2) {
                y = qrand()%9+1;
                answer = x*y;
            }
            else {
                do {y = qrand()%9+1;} while (x%y!=0);
                answer = x/y;
            }
            QString temp = QString("%1%2%3")
                    .arg(x)
                    .arg(operators[op])
                    .arg(y);
            problems[i] = temp;
            temp = QString("%1").arg(answer);
            answers[i] = temp;
        }
    }
    else if (diff == NORMAL) {
        for (int i=0; i<100; i++) {
            int x; // one digits
            int y; // one digits
            int op; // 0:+, 1:-, 2:*, 3:/
            int answer;
            op = qrand()%4;
            x = qrand()%29+1;
            if (op == 0) {
                y = qrand()%29+1;
                answer = x+y;
            }
            else if (op == 1) {
                do {y = qrand()%29+1;} while (y>x);
                answer = x-y;
            }
            else if (op == 2) {
                y = qrand()%9+1;
                answer = x*y;
            }
            else {
                do {y = qrand()%29+1;} while (x%y!=0);
                answer = x/y;
            }
            QString temp = QString("%1%2%3")
                    .arg(x)
                    .arg(operators[op])
                    .arg(y);
            problems[i] = temp;
            temp = QString("%1").arg(answer);
            answers[i] = temp;
        }
    }
    else {
        for (int i=0; i<100; i++) {
            int x; // one digits
            int y; // one digits
            int op; // 0:+, 1:-, 2:*, 3:/
            int answer;
            op = qrand()%4;
            x = qrand()%59+1;
            if (op == 0) {
                y = qrand()%59+1;
                answer = x+y;
            }
            else if (op == 1) {
                do {y = qrand()%59+1;} while (y>x);
                answer = x-y;
            }
            else if (op == 2) {
                y = qrand()%19+1;
                answer = x*y;
            }
            else {
                do {y = qrand()%59+1;} while (x%y!=0);
                answer = x/y;
            }
            QString temp = QString("%1%2%3")
                    .arg(x)
                    .arg(operators[op])
                    .arg(y);
            problems[i] = temp;
            temp = QString("%1").arg(answer);
            answers[i] = temp;
        }
    }
}

QuizScene::~QuizScene() {
    delete[] player;
    delete[] scores;
}

Scene* QuizScene::update()
{
    draw( 0, 0, "Blackboard.png" );

    drawText(50, 280, problems[problemindex], problemfont, Qt::white);
    drawText(320, 420, equ, problemfont, Qt::white);
    drawText(420, 420, ans, problemfont, Qt::white);
    drawText(220, 80, "Score: "+QString("%1").arg(scores[0]), Scorefont, Qt::white);

    return nextScene;
}
bool QuizScene::mouseEvent( int x, int y, MouseFunction function )
{
    return false;
}

bool QuizScene::keyEvent(QKeyEvent* input){
    if(nextScene != NULL)
        return false;

    switch(input->key()){
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if (answers[problemindex] == ans)
                scores[0]++;
            problemindex++;
            ans.clear();
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            if (ans.length()<4) {
                ans.append(QString("%1").arg(input->key()-48));
            }
            break;
        case Qt::Key_Backspace:
        case '.':
            ans.clear();
            break;
        default:
            break;
    }
    lastKey = input->key();
    return false;
}
