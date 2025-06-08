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
	enum class SearchType;
public:
	GamePlayService();
	~GamePlayService();
	void Intialize();
	void Update();
	void Render();
	void Reset();
	void IntializeRandomSeed();
	void SearchElenment(Collection::SearchType searchtype);
	Collection::SearchType getCurrentSearchtype();
	int GetNUmberOfComprisons();
	int GetNumberOfArrayAccess();
	int GetDelayMilliseconds();
	int getNumberOfSticks();
	sf::String getTimeComplexity();
	
};

}