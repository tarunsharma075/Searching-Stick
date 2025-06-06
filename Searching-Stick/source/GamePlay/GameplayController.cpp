#include"../../include/GamePlay/GameplayController.h"
#include"../../include/GamePlay/GameplayView.h"
namespace GamePlay {
	GamePlayController::GamePlayController()
	{
		gameplayView = new GamePlayView();
	}
	GamePlayController::~GamePlayController()
	{
		delete(gameplayView);
	}
	void GamePlay::GamePlayController::Intialize()
	{
		gameplayView->intialize(this);
		Reset();
	
	}

	void GamePlay::GamePlayController::Update()
	{
		gameplayView->Update();
	}

	void GamePlay::GamePlayController::Render()
	{
		gameplayView->Render();
	}

	void GamePlay::GamePlayController::Reset()
	{
		
	}
	
}