#include "Player.h"

Player::Player()
{
	_playerSprite = new Sprite("Logo.jpg");

	_timer = Timer::getTimer();

	_depthMovement = MoveTypeEnum::NONE;

	_sidewaysMovement = MoveTypeEnum::NONE;

	_moveSpeed = BaseMoveSpeed;

	_playerSprite->setFront(-_playerSprite->getFront());

	_lastCursorX = Input::getMousePosition().x;

	_lastCursorY = Input::getMousePosition().y;

	_xCursorOffset = 0.0f;

	_yCursorOffset = 0.0f;

	_playerSprite->setRotation(vec3(0.0f, -90.0f, 0.0f));
}

Player::~Player()
{
	delete _playerSprite;
}

Sprite* Player::getPlayerSprite()
{
	return _playerSprite;
}

void Player::playerInput()
{
	moveInput();
}

void Player::moveInput()
{
	if (Input::getKeyPressed(GLFW_KEY_W))
	{
		_depthMovement = MoveTypeEnum::FORWARD;
	}
	else if (Input::getKeyPressed(GLFW_KEY_S))
	{
		_depthMovement = MoveTypeEnum::BACKWARD;
	}
	else
	{
		_depthMovement = MoveTypeEnum::NONE;
	}

	if (Input::getKeyPressed(GLFW_KEY_A))
	{
		_sidewaysMovement = MoveTypeEnum::LEFT;
	}
	else if (Input::getKeyPressed(GLFW_KEY_D))
	{
		_sidewaysMovement = MoveTypeEnum::RIGHT;
	}
	else
	{
		_sidewaysMovement = MoveTypeEnum::NONE;
	}
}

void Player::playerUpdate()
{
	playerFrontFollowsCursor();

	playerMove();
}

void Player::playerMove()
{
	switch (_depthMovement)
	{
	case MoveTypeEnum::FORWARD:

		_playerSprite->addPosition(_moveSpeed * _playerSprite->getFront() * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	case MoveTypeEnum::BACKWARD:

		_playerSprite->subtractPosition(_moveSpeed * _playerSprite->getFront() * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	default:
		break;
	}

	switch (_sidewaysMovement)
	{
	case MoveTypeEnum::LEFT:

		_playerSprite->subtractPosition(normalize(cross(_playerSprite->getFront(), _playerSprite->getUp())) * _moveSpeed * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	case MoveTypeEnum::RIGHT:

		_playerSprite->addPosition(normalize(cross(_playerSprite->getFront(), _playerSprite->getUp())) * _moveSpeed * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	default:
		break;
	}
}

void Player::playerFrontFollowsCursor()
{
	_xCursorOffset = (Input::getMousePosition().x - _lastCursorX) * Sensitivity;

	_yCursorOffset = (_lastCursorY - Input::getMousePosition().y) * Sensitivity;

	_lastCursorX = Input::getMousePosition().x;

	_lastCursorY = Input::getMousePosition().y;

	updateEulerAngles();

	_playerSprite->setFront(eulerToDirection(_playerSprite->getRotation().y, _playerSprite->getRotation().x));

	_playerSprite->setRight(normalize(cross(_playerSprite->getFront(), vec3(0.0f, 1.0f, 0.0f)))); //Second vec = World up

	_playerSprite->setUp(normalize(cross(_playerSprite->getRight(), _playerSprite->getFront())));
}

void Player::updateEulerAngles()
{
	_playerSprite->addRotation(vec3(_yCursorOffset, _xCursorOffset, 0.0f));
	
	if (_playerSprite->getRotation().x > MaxPitch)
	{
		_playerSprite->setRotationX(MaxPitch);
	}
	else if (_playerSprite->getRotation().x < MinPitch)
	{
		_playerSprite->setRotationX(MaxPitch);
	}
}

vec3 Player::eulerToDirection(float yaw, float pitch)
{
	return normalize(vec3(cos(radians(yaw)) * cos(radians(pitch)), sin(radians(pitch)), sin(radians(yaw))) * cos(radians(pitch)));
}

void Player::playerDraw()
{
	_playerSprite->drawSprite();
}