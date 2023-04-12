#include "Engine.h"

DllExport Engine::Engine()
{	
	_window = NULL;
	_renderer = NULL;	
	_timer = NULL;	
	_camera = NULL;
}

DllExport Engine::~Engine()
{
	if (_window != NULL) { delete _window; }
	if (_renderer != NULL) { delete _renderer; }	
	if (_timer != NULL) { delete _timer; }
	if (_camera != NULL) { delete _camera; }
}

DllExport void Engine::setBaseGameClases()
{
	_window = Window::getWindow();
	_renderer = Renderer::getRenderer();	
	_timer = DeltaTime::getTimer();
	_camera = Camera::getCamera();
}

DllExport void Engine::runEngine()
{
	setBaseGameClases();	
	
	Input::hideCursor();

	init();
	
	while (!_window->getWindowsShouldClose())
	{
		_renderer->Clear();
				
		input();
		
		_timer->updateDeltaTime();		
		
		update();		

		_camera->updateView();
		
		draw();
		
		glfwSwapBuffers(_window->getGLFWwindow());
		
		glfwPollEvents();
	}

	deinit();
}

DllExport float Engine::getDeltaTime()
{
	return _timer->timeBetweenFrames();
}