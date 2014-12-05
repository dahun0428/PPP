#include "Scene.h"
#ifndef SELECTSCENE_H
#define SELECTSCENE_H


class SelectScene : public Scene
    {
    public:
        SelectScene(Game*) ;

        ~SelectScene();
    protected:
        Scene* update();
        bool mouseEvent( int x, int y, MouseFunction );
        bool keyEvent(QKeyEvent *);
    private:
        Scene* nextScene;
        QPoint lastCursor;


        QRect ButtonSwim;
        QRect ButtonBasket;
        QRect ButtonSoccer;
        QRect ButtonQuiz;
        QRect BackButton;
        QRect SaveButton;

        void clickButtonSwim();
        void clickButtonBasket();
        void clickButtonSoccer();
        void clickBackButton();
        void clickSaveButton();

};
#endif // SELECTSCENE_H
