#include "baseGame.h"

DllExport BaseGame::BaseGame()
{	
	_window = NULL;
	_renderer = NULL;
	_imGuiEngine = NULL;
	_timer = NULL;
}

DllExport BaseGame::~BaseGame()
{
	if (_window != NULL) { delete _window; }
	if (_renderer != NULL) { delete _renderer; }
	if (_imGuiEngine != NULL) { delete _imGuiEngine; }
	if (_timer != NULL) { delete _timer; }
}

DllExport void BaseGame::setBaseGameClases()
{
	_window = Window::getWindow();
	_renderer = Renderer::getRenderer();
	_imGuiEngine = ImGuiEngine::getImGuiEngine();
	_timer = Timer::getTimer();
}

DllExport void BaseGame::runEngine()
{
	setBaseGameClases();	
	
	init();
		
	while (!_window->getWindowsShouldClose())
	{
		_renderer->Clear();

		_timer->updateDeltaTime();

		_imGuiEngine->imGuiStartDraw();	

		input();

		update();

		draw();

		_imGuiEngine->imGuiEndDraw();
		
		glfwSwapBuffers(_window->getGLFWwindow());
		
		glfwPollEvents();
	}

	deinit();
}