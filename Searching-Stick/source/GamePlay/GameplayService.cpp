#include"../../include/GamePlay/GameplayController.h"
#include"../../include/GamePlay/GameplayService.h"
#include<random>
#include<time.h>

namespace GamePlay {
	using namespace Collection;
	GamePlayService::GamePlayService()
	{
		gameplayController = new GamePlayController();
		stickCollectionController = new StickCollectionController();
	}
	GamePlayService::~GamePlayService()
	{
		delete(gameplayController);
		delete(stickCollectionController);
	}
	void GamePlay::GamePlayService::Intialize()

{
		gameplayController->Intialize();
		stickCollectionController->Intialize();
		IntializeRandomSeed();
}
	void GamePlayService::Update()
	{
		gameplayController->Update();
		stickCollectionController->Update();
	}
	void GamePlayService::Render()
	{
		gameplayController->Render();
		stickCollectionController->Render();
	}
	void GamePlayService::Reset()
	{
		gameplayController->Reset();
		stickCollectionController->reset();
	}
	void GamePlayService::IntializeRandomSeed()
	{
		std::srand(static_cast<unsigned int>(time(nullptr)));

	}
	void GamePlayService::SearchElenment(Collection::SearchType searchtype)
	{
		stickCollectionController->SetSearchType(searchtype);
	}
	Collection::SearchType GamePlayService::getCurrentSearchtype()
	{
		return stickCollectionController->GetSearchtype();
	}
	int GamePlayService::GetNUmberOfComprisons()
	{
		return stickCollectionController->GetnumberOfComparisons();
	}
	int GamePlayService::GetNumberOfArrayAccess()
	{
		return stickCollectionController->Getnumberofarrayaccess();
	}
	int GamePlayService::GetDelayMilliseconds()
	{
		return stickCollectionController->GetDelayMilliSeconds();
	}
	int GamePlayService::getNumberOfSticks()
	{
		return stickCollectionController->GetNumberOfElements();
	}
	sf::String GamePlayService::getTimeComplexity()
	{
		return stickCollectionController->gettimeComplexity();
	}
}