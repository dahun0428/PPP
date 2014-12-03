#include"Scene.h"
#ifndef SHOPSCENE_H
#define SHOPSCENE_H

class ShopScene : public Scene
{

public:
    ShopScene( Game* );
    ~ShopScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
private:
    Scene* nextScene;
    QPoint lastCursor;


    QRect Button1;
    QRect Button2;
    QRect Button3;
    QRect alertButton;
    QRect BackButton;

    void clickButton1();
    void clickButton2();
    void clickBackButton();
};

#endif // SHOPSCENE_H
