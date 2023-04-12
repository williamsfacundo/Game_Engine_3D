#ifndef ENGINE_H
#define ENGINE_H

#include "Renderer.h"
#include "window.h"
#include "DeltaTime.h"
#include "Input.h"
#include "Camera.h"

class Engine
{
private:
	Window* _window;
	Renderer* _renderer;	
	DeltaTime* _timer;
	Camera* _camera;
	
	DllExport void setBaseGameClases();

protected:	
	DllExport Engine();

	DllExport ~Engine();

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