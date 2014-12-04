#include "Game.h"
#include "Scene.h"
#include "StartScene.h"
#include "qfile.h" // tb
#include "qtextstream.h" // tb
#include "OlympicData.h" // tb

Game::Game( Window* _window ) : window( _window )
{
    nowScene = NULL;
    Scene* scene = new StartScene(this);
    setScene( scene );

    OlympicHistory = new OlympicData[10];
}
Game::~Game()
{
	deleteNowScene();
    delete[] OlympicHistory;
}
void Game::initialize(){
    point = 0;
    for (int i = 0 ;  i<5; i++)
        characterAvailable[i]= false;
    for (int i=0; i<5; i++) {
        easy_level_history[i] = 0;
        normal_level_history[i] = 0;
        hard_level_history[i] = 0;
        played[i] = false;
    }
    olympic_cnt = 0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<4; j++) {
            OlympicHistory[i].setMedal((School)j,0,0,0);
        }
    }
}

bool Game::mouseEvent( int x, int y, MouseFunction function )
{
	return nowScene->mouseFunction( x, y, function );
}

bool Game::keyEvent(QKeyEvent* input){
    return nowScene->keyFunction(input);
}

void Game::onDraw( QPainter* canvas )
{
	drawNowScene( canvas );
}
void Game::setScene( Scene* newScene)
{
	deleteNowScene();
	nowScene = newScene;
}
void Game::deleteNowScene()
{
    if( nowScene != NULL )
		delete nowScene;
}
void Game::drawNowScene( QPainter* canvas )
{
	Scene* newScene;

    if( nowScene != NULL )
		newScene = nowScene->update( canvas );

    if( newScene != NULL )
		setScene( newScene );
}

void Game::setDifficulty(enum Difficulty diff){
    difficulty = diff;
}

enum Difficulty Game::getDifficulty(){
    return difficulty;
}

void Game::setGamemode(enum GameMode mode){

    gamemode = mode;

}

enum GameMode Game::getGamemode(){
    return gamemode;
}

// tb
void Game::setPoint(int _point) {
    point = _point;
}

void Game::setCharacterAvailable(int index, bool _available) {
    characterAvailable[index] = _available;
}

int Game::getPoint() {
    return point;
}

bool Game::getCharacterAvailable(int index) {
    return characterAvailable[index];
}

void Game::loadGame(QString filename) {
    QFile* file = new QFile;
    file->setFileName(filename);
    file->open(QIODevice::ReadOnly);
    QTextStream read(file);

    QString tmp = read.readLine();
    point = tmp.toInt();

    tmp = read.readLine();
    QStringList tmpList = tmp.split(" ");
    for (int i=0; i<5; i++)
        characterAvailable[i] = (bool)(tmpList[i].toInt());

    tmp = read.readLine(); // read easy level highest scores
    tmpList = tmp.split(" ");
    for (int i=0; i<5; i++)
        easy_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine(); // read normal level highest scores
    tmpList = tmp.split(" ");
    for (int i=0; i<5; i++)
        normal_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine(); // read hard level highest scores
    tmpList = tmp.split(" ");
    for (int i=0; i<5; i++)
        hard_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine();
    olympic_cnt = tmp.toInt();

    tmp = read.readLine(); // read played array
    tmpList = tmp.split(" ");
    for (int i=0; i<5; i++)
        played[i] = (bool)tmpList[i].toInt();

    for (int i=0; i<olympic_cnt; i++) {
        tmp = read.readLine(); // read postech data
        tmpList = tmp.split(" ");
        OlympicHistory[i].setMedal(POSTECH, tmpList[0].toInt(), tmpList[1].toInt(), tmpList[2].toInt());

        tmp = read.readLine(); // read kaist data
        tmpList = tmp.split(" ");
        OlympicHistory[i].setMedal(KAIST, tmpList[0].toInt(), tmpList[1].toInt(), tmpList[2].toInt());

        tmp = read.readLine(); // read unist data
        tmpList = tmp.split(" ");
        OlympicHistory[i].setMedal(UNIST, tmpList[0].toInt(), tmpList[1].toInt(), tmpList[2].toInt());

        tmp = read.readLine(); // read gist data
        tmpList = tmp.split(" ");
        OlympicHistory[i].setMedal(GIST, tmpList[0].toInt(), tmpList[1].toInt(), tmpList[2].toInt());
    }

    file->close();
}

void Game::saveGame(QString filename) {
    QFile* file = new QFile;
    file->setFileName(filename);
    file->open(QIODevice::WriteOnly);

    QString tmp = QString("%1 %2 %3 %4 %5 %6\n")
            .arg(point)
            .arg((int)characterAvailable[0])
            .arg((int)characterAvailable[1])
            .arg((int)characterAvailable[2])
            .arg((int)characterAvailable[3])
            .arg((int)characterAvailable[4]);
    QByteArray str;
    str.append(tmp);
    file->write(str);

    file->close();
}

void Game::setNewHistory(enum GameType _gametype, int _score) {
    switch (difficulty) {
        case EASY:
            easy_level_history[_gametype] = _score;
        case NORMAL:
            normal_level_history[_gametype] = _score;
        case HARD:
            hard_level_history[_gametype] = _score;
    }
}

int Game::getEasyLevelHistory(enum GameType _gametype) {
    return easy_level_history[_gametype];
}

int Game::getNormalLevelHistory(enum GameType _gametype) {
    return normal_level_history[_gametype];
}

int Game::getHardLevelHistory(enum GameType _gametype) {
    return hard_level_history[_gametype];
}

OlympicData* Game::getOlympicData(int _index) {
    return &OlympicHistory[_index];
}

// tb
