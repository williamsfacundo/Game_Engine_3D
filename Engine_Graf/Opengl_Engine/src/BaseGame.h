#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "Renderer.h"
#include "window.h"
#include "Timer.h"
#include "Input.h"
#include "Camera.h"

class BaseGame
{
private:
	Window* _window;
	Renderer* _renderer;	
	Timer* _timer;
	Camera* _camera;

	DllExport void setBaseGameClases();

protected:	
	DllExport BaseGame();
	DllExport ~BaseGame();

public:	
	DllExport void runEngine();

	DllExport float getDeltaTime();
	
	DllExport virtual void init() = 0;
	DllExport virtual void input() = 0;
	DllExport virtual void update() = 0;
	DllExport virtual void draw() = 0;
	DllExport virtual void deinit() = 0;
};

#endif