#include "Game.h"

Game::Game()
{
	_sprite = NULL;	
}

Game::~Game()
{

}

void Game::init()
{
	_sprite = new Sprite("Logo.jpg", glm::vec3(0.0f, 0.0f, -300.0f));	
}

void Game::input()
{
	
}

void Game::update()
{
	_sprite->addRotation(glm::vec3(glm::radians(-10.0f), glm::radians(-10.0f), glm::radians(-10.0f)));
}

void Game::draw()
{
	((Sprite*)_sprite)->drawTexture();	
}

void Game::deinit()
{
	delete _sprite;	
}