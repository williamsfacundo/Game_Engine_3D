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
	Entity2d* _staticSprite;
	Entity2d* _playerSprite;

	vec3 _playerFront;
	vec3 _cameraOffset;

	bool _firstPerson;

public:
	Game();
	~Game();

	void init();
	void input();
	void update();
	void draw();
	void deinit();

	void SwitchPlayerView();

	void MovePlayer();
};

#endif