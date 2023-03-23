#include "Game.h"

int main()
{
	Game* game = new Game();	

	game->runEngine();

	delete game;

	return 0;
}