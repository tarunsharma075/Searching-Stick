#pragma once
#include<SFML/Graphics.hpp>
namespace GamePlay {
class GamePlayController;
class GamePlayService {
private:
GamePlayController* gameplayController;
public:
GamePlayService();
~GamePlayService();
void Intialize();
void Update();
void Render();
void Reset();
};

}