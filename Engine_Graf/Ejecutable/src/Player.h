#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "MoveTypeEnum.h"
#include "Timer.h"

class Player
{
private:
	const float BaseMoveSpeed = 100.0f;

	Sprite* _playerSprite;

	Timer* _timer;

	MoveTypeEnum _depthMovement;
	MoveTypeEnum _sidewaysMovement;

	const float Sensitivity = 0.1f;
	const float MaxPitch = 89.0f;
	const float MinPitch = -89.0f;

	float _moveSpeed;

	float _lastCursorX;
	float _lastCursorY;

	float _xCursorOffset;
	float _yCursorOffset;

public:
	Player();
	~Player();

	Sprite* getPlayerSprite();

	void playerInput();

	void moveInput();

	void playerUpdate();

	void playerMove();

	void playerFrontFollowsCursor();

	void updateEulerAngles();

	vec3 eulerToDirection(float yaw, float pitch);

	void playerDraw();
};

#endif