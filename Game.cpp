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
    for (int i=0; i<4; i++) {
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

void Game::setSingleDifficulty(enum Difficulty diff){
    singledifficulty = diff;
}

enum Difficulty Game::getSingleDifficulty(){
    return singledifficulty;
}

void Game::setOlympicDifficulty(enum Difficulty diff){
    olympicdifficulty = diff;
}

enum Difficulty Game::getOlympicDifficulty(){
    return olympicdifficulty;
}

void Game::setGamemode(enum GameMode mode){

    gamemode = mode;

}

enum GameMode Game::getGamemode(){
    return gamemode;
}

void Game::setCharacterInUse(CharacterType character){
    characterInUse = character;
}

enum CharacterType Game::getCharacterInUse(){
    return characterInUse;
}

enum GameType Game::getGametype() {
    return gametype;
}

void Game::setGametype(enum GameType type) {
    gametype = type;
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
    for (int i=0; i<4; i++)
        easy_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine(); // read normal level highest scores
    tmpList = tmp.split(" ");
    for (int i=0; i<4; i++)
        normal_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine(); // read hard level highest scores
    tmpList = tmp.split(" ");
    for (int i=0; i<4; i++)
        hard_level_history[i] = tmpList[i].toInt();

    tmp = read.readLine();
    olympic_cnt = tmp.toInt();

    tmp = read.readLine(); // read played array
    tmpList = tmp.split(" ");
    for (int i=0; i<3; i++)
        played[i] = (bool)tmpList[i].toInt();

    for (int i=0; i<=olympic_cnt; i++) {
        tmp = read.readLine(); // read difficulty
        OlympicHistory[i].setDiff((enum Difficulty)(tmp.toInt()));

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

    // Game class data setting
    singledifficulty = NONE;
    olympicdifficulty = OlympicHistory[olympic_cnt].getDifficulty();

    file->close();
}

void Game::saveGame(QString filename) {
    QFile* file = new QFile;
    file->setFileName(filename);
    file->open(QIODevice::WriteOnly);

    QString tmp = QString("%1\n").arg(point);
    QByteArray str;
    str.append(tmp);

    tmp = QString("%1 %2 %3 %4 %5\n")
            .arg((int)characterAvailable[0])
            .arg((int)characterAvailable[1])
            .arg((int)characterAvailable[2])
            .arg((int)characterAvailable[3])
            .arg((int)characterAvailable[4]);
    str.append(tmp);

    tmp = QString("%1 %2 %3 %4\n")
            .arg(easy_level_history[0])
            .arg(easy_level_history[1])
            .arg(easy_level_history[2])
            .arg(easy_level_history[3]);
    str.append(tmp);

    tmp = QString("%1 %2 %3 %4\n")
            .arg(normal_level_history[0])
            .arg(normal_level_history[1])
            .arg(normal_level_history[2])
            .arg(normal_level_history[3]);
    str.append(tmp);

    tmp = QString("%1 %2 %3 %4\n")
            .arg(hard_level_history[0])
            .arg(hard_level_history[1])
            .arg(hard_level_history[2])
            .arg(hard_level_history[3]);
    str.append(tmp);

    tmp = QString("%1\n").arg(olympic_cnt);
    str.append(tmp);

    tmp = QString("%1 %2 %3 %4\n")
            .arg(played[0])
            .arg(played[1])
            .arg(played[2])
            .arg(played[3]);
    str.append(tmp);

    for (int i=0; i<=olympic_cnt; i++) {
        tmp = QString("%1\n")
                .arg((int)(OlympicHistory[i].getDifficulty()));
        str.append(tmp);

        tmp = QString("%1 %2 %3\n")
                .arg(OlympicHistory[i].getSchoolMedal(POSTECH, GOLD))
                .arg(OlympicHistory[i].getSchoolMedal(POSTECH, SILVER))
                .arg(OlympicHistory[i].getSchoolMedal(POSTECH, BRONZE));
        str.append(tmp);

        tmp = QString("%1 %2 %3\n")
                .arg(OlympicHistory[i].getSchoolMedal(KAIST, GOLD))
                .arg(OlympicHistory[i].getSchoolMedal(KAIST, SILVER))
                .arg(OlympicHistory[i].getSchoolMedal(KAIST, BRONZE));
        str.append(tmp);

        tmp = QString("%1 %2 %3\n")
                .arg(OlympicHistory[i].getSchoolMedal(UNIST, GOLD))
                .arg(OlympicHistory[i].getSchoolMedal(UNIST, SILVER))
                .arg(OlympicHistory[i].getSchoolMedal(UNIST, BRONZE));
        str.append(tmp);

        tmp = QString("%1 %2 %3\n")
                .arg(OlympicHistory[i].getSchoolMedal(GIST, GOLD))
                .arg(OlympicHistory[i].getSchoolMedal(GIST, SILVER))
                .arg(OlympicHistory[i].getSchoolMedal(GIST, BRONZE));
        str.append(tmp);
    }

    file->write(str);
    file->close();
}

// have to make some functions to set new data
// becouse each game has different score type
// ex: swimming --> lower value is better
//     soccer --> higher value is better
void Game::setNewHistory(int _score) {
    switch (singledifficulty) {
        case EASY:
            if (gametype == SWIMMING) {
                if (easy_level_history[gametype] > _score)
                    easy_level_history[gametype] = _score;
            }
            else {
                if (easy_level_history[gametype] < _score)
                    easy_level_history[gametype] = _score;
            }
            break;
        case NORMAL:
            if (gametype == SWIMMING) {
                if (normal_level_history[gametype] > _score)
                    normal_level_history[gametype] = _score;
            }
            else {
                if (normal_level_history[gametype] < _score)
                    normal_level_history[gametype] = _score;
            }
        break;
        case HARD:
            if (gametype == SWIMMING) {
                if (hard_level_history[gametype] > _score)
                    hard_level_history[gametype] = _score;
            }
            else {
                if (hard_level_history[gametype] < _score)
                    hard_level_history[gametype] = _score;
            }
        break;
    }
}

int Game::getHistory() {
    switch (singledifficulty) {
        case EASY:
            return easy_level_history[gametype];
        case NORMAL:
            return normal_level_history[gametype];
        case HARD:
            return hard_level_history[gametype];
    }
}

// for historyscene
int Game::getHistory(enum Difficulty diff, enum GameType type) {
    switch (diff) {
        case EASY:
            return easy_level_history[type];
        case NORMAL:
            return normal_level_history[type];
        case HARD:
            return hard_level_history[type];
    }
}

OlympicData* Game::getOlympicData(int _index) {
    return &OlympicHistory[_index];
}

int Game::getOlympicCnt() {
    return olympic_cnt;
}

// tb
