#pragma once
#include<SFML/Graphics.hpp>
#include"../../include/GamePlay/Stick/StickCollectionController.h"

namespace GamePlay {
using namespace Collection;
class GamePlayController;
class GamePlayService {
private:
	GamePlayController* gameplayController;
	StickCollectionController* stickCollectionController;
public:
	GamePlayService();
	~GamePlayService();
	void Intialize();
	void Update();
	void Render();
	void Reset();
	void IntializeRandomSeed();
};

}