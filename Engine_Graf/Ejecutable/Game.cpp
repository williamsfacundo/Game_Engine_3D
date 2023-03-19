#include "Game.h"

Game::Game()
{
	_sprite = NULL;
	//_rectangleShape = NULL;
}

Game::~Game()
{

}

void Game::init()
{	
	_sprite = new Sprite("Logo.jpg", 300, 200);

	//((Sprite*)_sprite)->setTexture("Logo.jpg");

	//_rectangleShape = new RectangleShape(200, 300);

	//_rectangleShape->setScale(glm::vec3(0.2f, 0.2f, 1.0f));
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

	//_rectangleShape->draw();
}

void Game::deinit()
{
	delete _sprite;
	//delete _rectangleShape;
}