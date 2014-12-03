#include "Game.h"
#include "Scene.h"
#include "StartScene.h"

Game::Game( Window* _window ) : window( _window )
{
    nowScene = NULL;
    Scene* scene = new StartScene(this);
    setScene( scene );
    point = 0;

    for (int i = 0 ;  i<4; i++) characterAvailable[i]= false;
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
