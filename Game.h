#pragma once
#include "Global.h"

class Window;
class QPainter;
class Scene;

class Game
{
public:
	Game( Window* );
	~Game();
	void onDraw( QPainter* canvas );
	bool mouseEvent( int x, int y, MouseFunction );

	Window* getWindow(){ return window; }

    void setDifficulty(enum Difficulty);
    enum Difficulty getDifficulty();

    void setGamemode(GameMode gamemode);
    enum GameMode getGamemode();
private:
	Window* window;
	Scene* nowScene;
	
	void setScene( Scene* );
	void deleteNowScene();
	void drawNowScene( QPainter* canvas );
    int point;
    bool characterAvailable[4];
    enum Difficulty difficulty;
    enum GameMode gamemode;

};
