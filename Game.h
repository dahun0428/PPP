#pragma once
#include "Global.h"

class QKeyEvent;
class Window;
class QPainter;
class Scene;
class OlympicData;

class Game
{
public:
	Game( Window* );
	~Game();
	void onDraw( QPainter* canvas );
	bool mouseEvent( int x, int y, MouseFunction );
    bool keyEvent( QKeyEvent *);
    void initialize();

	Window* getWindow(){ return window; }

    void setSingleDifficulty(enum Difficulty);
    enum Difficulty getSingleDifficulty();

    void setOlympicDifficulty(enum Difficulty);
    enum Difficulty getOlympicDifficulty();

    void setGamemode(GameMode gamemode);
    enum GameMode getGamemode();

    void setGametype(GameType gametype);
    enum GameType getGametype();

    void setCharacterInUse(CharacterType character);
    enum CharacterType getCharacterInUse();

	// tb
    void setPoint(int _point);
    void setCharacterAvailable(int index, bool _available);
    int getPoint();
    bool getCharacterAvailable(int index);
    void loadGame(QString filename);
    void saveGame(QString filename);

    // exercise mode data get&set
    void setNewHistory(int _score);
    int getHistory();
    int getHistory(enum Difficulty diff, enum GameType type);
    OlympicData* getOlympicData(int _index);
    // tb
    int getOlympicCnt();

private:
	Window* window;
	Scene* nowScene;
	
	void setScene( Scene* );
	void deleteNowScene();
	void drawNowScene( QPainter* canvas );
    int point;
    bool characterAvailable[5];
    enum Difficulty singledifficulty;
    enum Difficulty olympicdifficulty;
    enum GameMode gamemode;
    enum GameType gametype;
    enum CharacterType characterInUse;

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
    OlympicData* OlympicHistory;


};
