#include "Game.h"

Game::Game()
{
	_player = NULL;

	_staticSprite = NULL;
}

void Game::init()
{
	_player = new Player();
	
	Camera::getCamera()->setTarget(_player->getPlayerSprite());

	Camera::getCamera()->setCameraStyle(CameraStyle::FIRST_PERSON);

	_staticSprite = new Sprite("Logo.jpg");

	_staticSprite->setPosition(vec3(0.0f, 0.0f, -300.0f));
}

void Game::input()
{
	_player->playerInput();

	ChangeCameraStyleInput();
}

void Game::update()
{
	_player->playerUpdate();
}

void Game::draw()
{
	if(Camera::getCamera()->getCameraStyle() != CameraStyle::FIRST_PERSON)
	{
		_player->playerDraw();
	}

	_staticSprite->drawSprite();
}

void Game::deinit()
{
	delete _player;

	delete _staticSprite;
}

void Game::ChangeCameraStyleInput()
{
	if(Input::getKeyPressed(GLFW_KEY_1))
	{
		Camera::getCamera()->setCameraStyle(CameraStyle::FIRST_PERSON);
	}
	else if (Input::getKeyPressed(GLFW_KEY_2))
	{
		Camera::getCamera()->setCameraStyle(CameraStyle::THIRD_PERSON);
	}
	else if(Input::getKeyPressed(GLFW_KEY_3))
	{
		Camera::getCamera()->setCameraStyle(CameraStyle::FREE);
	}
}