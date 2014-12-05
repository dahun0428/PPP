#ifndef QUIZSCENE_H
#define QUIZSCENE_H

#include "Scene.h"
class Character;

class QuizScene : public Scene
{
public:
    QuizScene( Game* );
    ~QuizScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent* input);
private:
    Scene* nextScene;
    QPoint lastCursor;
    int lastKey;
    int numOfPlayers;
    Character* player;
    int* scores;
    double playtime;
    QString problems[100];
    QString answers[100];
    QString operators[4];
};

#endif // QUIZSCENE_H
