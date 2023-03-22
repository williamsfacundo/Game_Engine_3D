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
	_sprite = new Sprite("Logo.jpg", glm::vec3(800.0f, 200.0f, 0.0f));
}

void Game::input()
{
	
}

void Game::update()
{

}

void Game::draw()
{
	((Sprite*)_sprite)->drawTexture();
}

void Game::deinit()
{
	delete _sprite;
}