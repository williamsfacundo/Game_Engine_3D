#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"
#include "Player.h"

class Game : public BaseGame
{
private:
	Player* _player;

	Sprite* _staticSprite;

public:
	Game();	

	void init();
	void input();
	void update();
	void draw();
	void deinit();

	void ChangeCameraStyleInput();
};

#endif