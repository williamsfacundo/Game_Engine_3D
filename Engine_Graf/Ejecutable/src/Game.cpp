#include "Game.h"

Game::Game()
{
	_staticSprite = NULL;
	//_playerSprite = NULL;
}

void Game::init()
{	
	_staticSprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, -300.0f));

	//_playerSprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, 0.0f));	
}

void Game::input()
{
	
}

void Game::update()
{
	
}

void Game::draw()
{
	((Sprite*)_staticSprite)->drawTexture();

	//((Sprite*)_playerSprite)->drawTexture();
}

void Game::deinit()
{
	delete _staticSprite;	

	//delete _playerSprite;
}