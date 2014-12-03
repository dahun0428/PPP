#include "Window.h"
#include <cmath>
#include <ctime>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QFontDatabase>
#include "game.h"


Window::Window( QWidget *parent ) : QMainWindow(parent)
{

	initialize();
}
Window::~Window()
{
	delete game;
    delete fpsLabel;
}
void Window::initialize()
{
	std::srand( (unsigned int)time(NULL) );
    setWindowTitle( "  Postech Olympics!!!  ");
	setMouseTracking(true);
	setFixedSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	isMouseDown = false;
 	game = new Game( this );
	makeTimer();
    show();
	startFps();
}

void Window::paintEvent( QPaintEvent*  )
{
     painter = new QPainter(this);
     game->onDraw( painter );
}

void Window::mousePressEvent( QMouseEvent* mouseEvent )
{
	mousePos = mouseEvent->pos();
	mouseDownPos = mousePos;

	switch( mouseEvent->button() )
	{
		case Qt::LeftButton:
			isMouseDown = true;
			if( mouseFunction( MOUSE_DOWN ) )
				isMouseDown = false;
			break;
	}
}

void Window::mouseMoveEvent( QMouseEvent* mouseEvent )
{
	mousePos = mouseEvent->pos();
	mouseFunction( MOUSE_MOVE );
	if( isMouseDown )
		mouseFunction( MOUSE_DRAG );
}
void Window::mouseReleaseEvent( QMouseEvent* mouseEvent )
{
	mousePos = mouseEvent->pos();
	switch( mouseEvent->button() )
	{
		case Qt::LeftButton:
			if( isMouseDown && (mouseDownPos - mousePos).manhattanLength() < CLICK_MOUSE_MOVE_RANGE )
			{
				if( !mouseFunction( MOUSE_CLICK ))
				{
					mouseFunction( MOUSE_UP );
				}
			}
			else
			{
				mouseFunction( MOUSE_UP );
			}
			isMouseDown = false;
			break;
    default:
        break;
	}
}
bool Window::mouseFunction( MouseFunction function )
{
	return game->mouseEvent( mousePos.x(), mousePos.y(), function );
}
void Window::makeTimer()
{
	setDrawTime();
    startTimer(1);
}
void Window::timerEvent( QTimerEvent* event )
{
	redraw();
}
void Window::redraw()
{
	if( QTime::currentTime() > lastDrawTime.addMSecs( 1000/FRAME ) )
	{
		checkFps();
		setDrawTime();
		repaint();
	}
}
void Window::setDrawTime()
{
	lastDrawTime = QTime::currentTime();
}
void Window::startFps()
{
	fpsLabel = new QLabel( "", this );
	lastFps = 0;
	checkingFps = 0;
	if( SHOW_FPS ) fpsLabel->show();
}
void Window::checkFps()
{
	QTime now = QTime::currentTime();

	if( now > lastFpsTime.addMSecs( 1000 ) )
	{
		lastFps = checkingFps;
		checkingFps = 0;
		lastFpsTime = now;
		fpsLabel->setText( " fps: " + QString::number( lastFps ) );
	}
	++checkingFps;
}
