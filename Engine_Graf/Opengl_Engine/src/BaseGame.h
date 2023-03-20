#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "GL/glew.h"
#include "glfw3.h"
#include "DDLExport.h"
#include "Renderer.h"
#include "window.h"
#include "Timer.h"
#include "ImGuiEngine.h"

class BaseGame
{

private:

	Window* window;
	Renderer* renderer;
	ImGuiEngine* imGuiEngine;
	Timer* timer;

protected:
	
	DllExport BaseGame();
	DllExport ~BaseGame();

public:
	
	DllExport void run();

	DllExport virtual void init() = 0;
	DllExport virtual void input() = 0;
	DllExport virtual void update() = 0;
	DllExport virtual void draw() = 0;
	DllExport virtual void deinit() = 0;
};

#endif