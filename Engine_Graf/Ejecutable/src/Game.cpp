#include "Game.h"

Game::Game()
{
	_sprite = NULL;
	_triangleShape = NULL;
}

Game::~Game()
{

}

void Game::init()
{
	_sprite = new Sprite("Logo.jpg", glm::vec3(800.0f, 200.0f, 0.0f));
	_triangleShape = new TriangleShape(glm::vec4(40, 200, 80, 1), glm::vec3(200.0f, 200.0f, 0.0f));
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

	_triangleShape->draw();
}

void Game::deinit()
{
	delete _sprite;
	delete _triangleShape;
}