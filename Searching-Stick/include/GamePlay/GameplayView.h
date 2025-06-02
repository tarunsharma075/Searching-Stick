#pragma once
#include"../../include/UI/UIElement/ImageView.h"
#include<SFML/Graphics.hpp>
namespace GamePlay {
class GamePlayController;
class GamePlayView {
private:
	const float backGroudAlpha = 0.5;
	UI::UIElement::ImageView* background;
	sf::Font font;
	GamePlayController* gameplayController;
public:
	GamePlayView();
	~GamePlayView();
	void intialize(GamePlayController* gameplayController);
	void Update();
	void initializeBackgroundImage();
    void Render();
};
}