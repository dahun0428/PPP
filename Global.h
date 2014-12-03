#pragma once
#include<qnamespace.h>
//#include<QNameSpace>

enum DEBUG { SHOW_FPS = false, SHOW_TIME = false };

enum MouseFunction { MOUSE_MOVE, MOUSE_CLICK, MOUSE_DOWN, MOUSE_DRAG, MOUSE_UP };
enum TextAlign {
	LEFT				= Qt::AlignLeft,
	CENTER				= Qt::AlignHCenter,
	RIGHT				= Qt::AlignRight,
  /*  CENTER_LEFT			= Qt::AlignVCenter	| Qt::AlignLeft,
	CENTER_CENTER		= Qt::AlignVCenter	| Qt::AlignHCenter,
	CENTER_RIGHT		= Qt::AlignVCenter	| Qt::AlignRight,
	BOTTOM_LEFT			= Qt::AlignBottom	| Qt::AlignLeft,
	BOTTOM_CENTER		= Qt::AlignBottom	| Qt::AlignHCenter,
    BOTTOM_RIGHT		= Qt::AlignBottom	| Qt::AlignRight*/
};
enum { CLICK_MOUSE_MOVE_RANGE = 6 };
enum { SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600, FRAME = 60 };
enum Difficulty { NONE, EASY, NORMAL, HARD};
enum GameMode { SINGLE, OLYMPIC};
