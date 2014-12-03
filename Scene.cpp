#include "Scene.h"

#include <QPainter>
#include <QRect>

Scene::Scene( Game* _game ) : game( _game )
{
	canvas = NULL;

}
Scene::~Scene()
{

}
Scene* Scene::update( QPainter* _canvas )
{
	setCanvas( _canvas );
	return update();
}
void Scene::setCanvas( QPainter* _canvas )
{
	canvas = _canvas;
}
void Scene::drawColor( QColor color )
{
	canvas->fillRect( 0, 0, 640, 480, color );
}
void Scene::draw( double x, double y, QString imgName )
{
	if(canvas){
        QByteArray FullName;
        FullName.append("..\\..\\PPP\\Resources\\");

		FullName.append(imgName);

		QPixmap newImg;
        newImg.load(QString::fromUtf8(FullName));
    //    newImg.load(FullName);
		canvas->drawPixmap( x, y, newImg );
	}
}
void Scene::drawCenter( double _x, double _y, QString imgName, double scale )
{
    if( canvas == NULL ) return;

    QByteArray FullName;
    FullName.append("..\\..\\PPP\\Resources\\");
	FullName.append(imgName);

	QPixmap* pixmap;
	pixmap = new QPixmap();
    pixmap->load(QString::fromUtf8(FullName));
	if( scale == 1.0 )
	{
		double x = _x - pixmap->width() / 2.0;
		double y = _y - pixmap->height() / 2.0;
		canvas->drawPixmap( x , y, *pixmap );
	}
	else
	{
		double w = pixmap->width() * scale;
		double h = pixmap->height() * scale;
		double x = _x - w / 2.0;
		double y = _y - h / 2.0;
		canvas->drawPixmap( x, y, w, h, *pixmap );
	}
}

void Scene::drawText( double x, double y, QString text )
{
	if(canvas)
		canvas->drawText( x, y, text );
}
void Scene::drawText( double x, double y, double w, double h, QString text, TextAlign align )
{
	QRect rect(x, y, w, h);
	drawText( rect, text, align );
}
void Scene::drawText( QRect rect, QString text, TextAlign align )
{
	QTextOption textOption;
	textOption.setAlignment( static_cast<Qt::Alignment>(align) );

	if(canvas)
		canvas->drawText( rect, text, textOption );
}


bool Scene::mouseFunction( int x, int y, MouseFunction function )
{
	cursorXY.setX( x );
	cursorXY.setY( y );
	return mouseEvent( x, y, function );
}
