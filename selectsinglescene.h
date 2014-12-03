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
    private:
        Scene* nextScene;
        QPoint lastCursor;

        QRect ButtonEasy;
        QRect ButtonNormal;
        QRect ButtonHard;

        QRect ButtonSwim;
        QRect ButtonBasket;
        QRect ButtonSoccer;
        QRect BackButton;

        void clickButtonEasy();
        void clickButtonNormal();
        void clickButtonHard();

        void clickButtonSwim();
        void clickButtonBasket();
        void clickButtonSoccer();
        void clickBackButton();
};
#endif // SELECTSINGLESCENE_H
