#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "Renderer.h"
#include "window.h"
#include "Timer.h"
#include "ImGuiEngine.h"
#include "Input.h"

class BaseGame
{
private:
	Window* _window;
	Renderer* _renderer;
	ImGuiEngine* _imGuiEngine;
	Timer* _timer;

	DllExport void setBaseGameClases();

protected:	
	DllExport BaseGame();
	DllExport ~BaseGame();

public:	
	DllExport void runEngine();
	
	DllExport virtual void init() = 0;
	DllExport virtual void input() = 0;
	DllExport virtual void update() = 0;
	DllExport virtual void draw() = 0;
	DllExport virtual void deinit() = 0;
};

#endif