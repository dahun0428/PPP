#pragma once
#include <QPainter>
#include <QFontDatabase>
#include "Global.h"


class Game;
class QRect;

class Scene
{

public:
	explicit Scene( Game* );
	virtual ~Scene();
	Scene* update( QPainter* );
	virtual Scene* update() = 0;
	Game* getGameClass(){ return game; }

	bool mouseFunction( int x, int y, MouseFunction );
	QPoint getCursorXY(){ return cursorXY; }

	QPainter* getCanvas(){ return canvas; }
	void setPen( QPen* pen ){ canvas->setPen( *pen ); }
	


	void draw( double x, double y, QString text );
	void drawColor( QColor color );
	void drawCenter( double x, double y, QString text, double scale = 1.0 );
	void drawText( double x, double y, QString text );
	void drawText( double x, double y, double w, double h, QString text, TextAlign = LEFT );
	void drawText( QRect, QString text, TextAlign = LEFT );

protected:
	virtual bool mouseEvent( int x, int y, MouseFunction ) = 0;
	void setCanvas( QPainter* );
	QPainter* canvas;
private:
	Game* game;
	QPoint cursorXY;
	QPen* scorePen;



public:

};
