#ifndef SHOPSCENE_H
#define SHOPSCENE_H
#include"Scene.h"
#include<QFont>

class ShopScene : public Scene
{

public:
    ShopScene( Game* );
    ~ShopScene();
protected:
    Scene* update();
    bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent(QKeyEvent *);
private:
    Scene* nextScene;
    QPoint lastCursor;
    QString pointText;
    int price[5];
    QString priceText[5];

    QRect BuyButton[5];
    QRect GambleButton;
    QRect BackButton;
    QRect alertButton;

    void clickBuyButton(int index);
    void clickGambleButton();
    void clickBackButton();

    QString intToQString(int n);       // move somewhere else?
    QFont Font1,Font2;
};

#endif // SHOPSCENE_H
