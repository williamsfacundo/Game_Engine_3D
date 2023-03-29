#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"
#include "Shape.h"
#include "RectangleShape.h"
#include "Sprite.h"
#include "TriangleShape.h"

class Game : public BaseGame
{
private:
	Entity2d* _sprite;	

public:
	Game();
	~Game();

	void init();
	void input();
	void update();
	void draw();
	void deinit();
};

#endif