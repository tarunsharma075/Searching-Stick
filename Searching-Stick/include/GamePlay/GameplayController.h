#pragma once
namespace GamePlay {
class GamePlayView;

class GamePlayController {
private:
GamePlayView* gameplayView;
public:
GamePlayController();
~GamePlayController();
void Intialize();
void Update();
void Render();
void Reset();

};
}