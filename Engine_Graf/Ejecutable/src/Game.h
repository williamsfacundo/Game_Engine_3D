#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"

#include "Sprite.h"

class Game : public BaseGame
{
private:
	Entity2d* _staticSprite;

public:
	Game();	

	void init();
	void input();
	void update();
	void draw();
	void deinit();	
};

#endif