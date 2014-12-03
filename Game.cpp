#include "Game.h"
#include "Scene.h"
#include "StartScene.h"
#include "qfile.h" // tb
#include "qtextstream.h" // tb

Game::Game( Window* _window ) : window( _window )
{
    nowScene = NULL;
    Scene* scene = new StartScene(this);
    setScene( scene );
    point = 0;

    for (int i = 0 ;  i<4; i++) characterAvailable[i]= false;
    // 여기서 초기화 시키면 나중에 load 하고나서 변심해서 다시 new 시작해버리면
    // 초기화 안되고 나중에 load된 애가 불려와짐
    // 초기화하는 함수 따로 만들어서 new 클릭되는 순간 호출되게끔 해야할 듯!
}
Game::~Game()
{
	deleteNowScene();
}

bool Game::mouseEvent( int x, int y, MouseFunction function )
{
	return nowScene->mouseFunction( x, y, function );
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
    QStringList tmpList = tmp.split(" ");
    point = tmpList[0].toInt();
    characterAvailable[0] = (bool)(tmpList[1].toInt());
    characterAvailable[1] = (bool)(tmpList[1].toInt());
    characterAvailable[2] = (bool)(tmpList[1].toInt());
    characterAvailable[3] = (bool)(tmpList[1].toInt());

    file->close();
}

void Game::saveGame(QString filename) {
    QFile* file = new QFile;
    file->setFileName(filename);
    file->open(QIODevice::WriteOnly);

    QString tmp = QString("%1 %2 %3 %4 %5\n")
            .arg(point)
            .arg((int)characterAvailable[0])
            .arg((int)characterAvailable[1])
            .arg((int)characterAvailable[2])
            .arg((int)characterAvailable[3]);
    QByteArray str;
    str.append(tmp);
    file->write(str);

    file->close();
}

// tb
