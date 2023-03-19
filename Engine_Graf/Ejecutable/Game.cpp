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
	_sprite = new Sprite("Logo.jpg", 300, 200);	
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