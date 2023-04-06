#include "Game.h"

Game::Game()
{
	_staticSprite = NULL;
}

void Game::init()
{	
	_staticSprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, -300.0f));	
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
}

void Game::deinit()
{
	delete _staticSprite;		
}