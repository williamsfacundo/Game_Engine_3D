#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Player.h"

class Game : public Engine
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