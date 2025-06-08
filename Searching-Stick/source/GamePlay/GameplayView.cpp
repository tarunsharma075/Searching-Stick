#include"../../include/GamePlay/GameplayView.h"
#include"../../include/GamePlay/GameplayController.h"
#include"../../include/Global/ServiceLocator.h"
#include"../../include/Global/Config.h"
namespace GamePlay {
	using namespace Global;
	GamePlay::GamePlayView::GamePlayView()
	{
		background = new UI::UIElement::ImageView();
	}

	GamePlay::GamePlayView::~GamePlayView()
	{
		delete(background);
	}

	void GamePlay::GamePlayView::intialize(GamePlayController* gameplayController)
	{
		this->gameplayController = gameplayController;
		initializeBackgroundImage();

	}

	void GamePlay::GamePlayView::Update()
	{
		background->update();
	}

	void GamePlayView::initializeBackgroundImage()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		background->initialize(Config::background_texture_path,
			gameWindow->getSize().x,
			gameWindow->getSize().y,
			sf::Vector2f(0, 0));
		/*background->setImageAlpha(backGroudAlpha);*/
	}

	void GamePlay::GamePlayView::Render()
	{
		background->render();
	}
}