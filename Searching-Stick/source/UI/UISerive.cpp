#include "UI/UIService.h"
#include "Main/GameService.h"
#include "UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace UIElement;
	using namespace Interface;
	using namespace GamePlayUI;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
		gameplayController = new GameplayUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		gameplayController->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;
		case GameState::GamePlay:
				return gameplayController;

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete(splash_screen_controller);
		delete(main_menu_controller);
	}
}