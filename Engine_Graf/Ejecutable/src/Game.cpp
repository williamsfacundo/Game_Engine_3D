#include "Game.h"

Game::Game()
{
	_staticSprite = NULL;
	_playerSprite = NULL;

	_playerFront = vec3(0.0f);
	_cameraOffset = vec3(0.0f);

	_firstPerson = true;
}

Game::~Game()
{

}

void Game::init()
{
	_playerFront = vec3(0.0f, 0.0f, -1.0f);
	_cameraOffset = vec3(0.0f, 200.0f, 500.0f);

	_staticSprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, -300.0f));
	_playerSprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, 0.0f));	
}

void Game::input()
{
	SwitchPlayerView();
}

void Game::update()
{
	_staticSprite->addRotation(vec3(0.0f, glm::radians(-10.0f), 0.0f));

	if(_firstPerson)
	{
		Camera::getCamera()->firstPersonCameraFollow(_playerSprite->getPosition(), _playerFront);
	}
	else
	{
		Camera::getCamera()->thirdPersonCameraFollow(_playerSprite->getPosition(), _cameraOffset);
	}
}

void Game::draw()
{
	((Sprite*)_staticSprite)->drawTexture();
	((Sprite*)_playerSprite)->drawTexture();
}

void Game::deinit()
{
	delete _staticSprite;	
	delete _playerSprite;
}

void Game::SwitchPlayerView()
{
	if (Input::getKeyPressed(GLFW_KEY_SPACE))
	{
		_firstPerson = !_firstPerson;
	}
}

void Game::MovePlayer()
{
		
}