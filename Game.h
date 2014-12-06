#pragma once
#include "Global.h"

class QKeyEvent;
class Window;
class QPainter;
class Scene;
class OlympicData;
class Character;

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
    Character getRealCharacterInUse();

    void setScore(int _score);
    int getScore();

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
    int score;
    bool characterAvailable[6];
    enum Difficulty singledifficulty;
    enum Difficulty olympicdifficulty;
    enum GameMode gamemode;
    enum GameType gametype;
    enum CharacterType characterInUse;
    Character* Characters;

    // exercise mode history
    int easy_level_history[4];
    int normal_level_history[4];
    int hard_level_history[4];

    // olympic mode history
    bool played[4]; // if true --> player played the game
    // in olympic mode, if all elemnets in played array are true
    // then olympic_cnt++ and played[i] = false for all i
    int olympic_cnt; // total number of olympic, need for loading
    // class for olympic data
    OlympicData* OlympicHistory;


};
