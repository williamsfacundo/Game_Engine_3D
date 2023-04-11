#include "baseGame.h"

DllExport BaseGame::BaseGame()
{	
	_window = NULL;
	_renderer = NULL;	
	_timer = NULL;	
	_camera = NULL;
}

DllExport BaseGame::~BaseGame()
{
	if (_window != NULL) { delete _window; }
	if (_renderer != NULL) { delete _renderer; }	
	if (_timer != NULL) { delete _timer; }
	if (_camera != NULL) { delete _camera; }
}

DllExport void BaseGame::setBaseGameClases()
{
	_window = Window::getWindow();
	_renderer = Renderer::getRenderer();	
	_timer = Timer::getTimer();
	_camera = Camera::getCamera();
}

DllExport void BaseGame::runEngine()
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

DllExport float BaseGame::getDeltaTime()
{
	return _timer->timeBetweenFrames();
}