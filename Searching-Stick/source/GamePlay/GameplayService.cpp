#include"../../include/GamePlay/GameplayController.h"
#include"../../include/GamePlay/GameplayService.h"
namespace GamePlay {
	GamePlayService::GamePlayService()
	{
		gameplayController = new GamePlayController();
	}
	GamePlayService::~GamePlayService()
	{
		delete(gameplayController);
	}
	void GamePlay::GamePlayService::Intialize()

{
		gameplayController->Intialize();
}
	void GamePlayService::Update()
	{
		gameplayController->Update();
	}
	void GamePlayService::Render()
	{
		gameplayController->Render();
	}
	void GamePlayService::Reset()
	{
		gameplayController->Reset();
	}
}