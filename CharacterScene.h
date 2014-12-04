#ifndef CHARACTERSCENE_H
#define CHARACTERSCENE_H
#include "Scene.h"

class CharacterScene : public Scene
{

public:
    CharacterScene( Game* );
    ~CharacterScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;

    QRect CharacterButton[5];
    QRect BackButton;
    QRect alertButton;

    void clickCharacterButton(int index);
    void clickBackButton();
};

#endif // CHARACTERSCENE_H
