#include "historyscene.h"
#include "newScene.h"
#include "Game.h"
#include "Global.h"

HistoryScene::HistoryScene( Game* game) : Scene( game ) {
    nextScene = NULL;

    ExerciseHistoryButton = QRect(175, 75, 150, 50);
    OlympicHistoryButton = QRect(475, 75, 150, 50);
}

HistoryScene::~HistoryScene() {

}

Scene* HistoryScene::update() {
    return nextScene;
}

bool HistoryScene::mouseEvent(int x, int y, MouseFunction) {

    return false;
}
