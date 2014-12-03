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

	// tb
    void setPoint(int _point);
    void setCharacterAvailable(int index, bool _available);
    int getPoint();
    bool getCharacterAvailable(int index);
    void loadGame(QString filename);
    void saveGame(QString filename);
    // tb

private:
	Window* window;
	Scene* nowScene;
	
	void setScene( Scene* );
	void deleteNowScene();
	void drawNowScene( QPainter* canvas );
    int point;
    bool characterAvailable[5];
    enum Difficulty difficulty;
    enum GameMode gamemode;

    // exercise mode history
    int easy_level_history[5];
    int normal_level_history[5];
    int hard_level_history[5];

    // olympic mode history
    bool played[5]; // if true --> player played the game
    // in olympic mode, if all elemnets in played array are true
    // then olympic_cnt++ and played[i] = false for all i
    int olympic_cnt; // total number of olympic, need for loading
    // class for olympic data

};
