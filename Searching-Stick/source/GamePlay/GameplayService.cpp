#include"../../include/GamePlay/GameplayController.h"
#include"../../include/GamePlay/GameplayService.h"

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
}