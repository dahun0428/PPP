#pragma once
#include <QMainWindow>
#include <QTime>
#include "Global.h"


class Game;
class QLabel;
class QMediaPlayer;
class QMediaPlaylist;

class Window : public QMainWindow
{
	Q_OBJECT

public:
	explicit Window( QWidget *parent = 0 );
	~Window();
    void paintEvent(QPaintEvent * );

protected:
	void mouseMoveEvent ( QMouseEvent* );
	void mousePressEvent( QMouseEvent* );
	void mouseReleaseEvent( QMouseEvent* );
	void timerEvent( QTimerEvent* );

    void keyPressEvent(QKeyEvent*) ;
    void keyReleaseEvent(QKeyEvent *);

private:
	QTime lastDrawTime;
    Game *game;
    QPainter *painter;
	bool isMouseDown;
    bool keyDown;
	QPointF mouseDownPos;
	QPointF mousePos;

	QLabel* fpsLabel;
	int checkingFps;
	QTime lastFpsTime;
	int lastFps;
	
	void initialize();
	void makeTimer();
	void redraw();
	void setDrawTime();
	bool mouseFunction( MouseFunction );
    void startFps();
	void checkFps();

    bool keyFunction( QKeyEvent *);


};
