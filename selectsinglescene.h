#include "Scene.h"
#ifndef SELECTSINGLESCENE_H
#define SELECTSINGLESCENE_H

class SelectSingleScene : public Scene
    {
    public:
        SelectSingleScene(Game*) ;


        ~SelectSingleScene();
    protected:
        Scene* update();
        bool mouseEvent( int x, int y, MouseFunction );
        bool keyEvent(QKeyEvent *);
    private:
        Scene* nextScene;
        QPoint lastCursor;

        QRect ButtonEasy;
        QRect ButtonNormal;
        QRect ButtonHard;

        QRect ButtonSwim;
        QRect ButtonBasket;
        QRect ButtonSoccer;
        QRect ButtonQuiz;

        QRect BackButton;
        QRect SaveButton;

        void clickButtonEasy();
        void clickButtonNormal();
        void clickButtonHard();

        void clickButtonSwim();
        void clickButtonBasket();
        void clickButtonSoccer();
        void clickButtonQuiz();

        void clickBackButton();
        void clickSaveButton();
};
#endif // SELECTSINGLESCENE_H
