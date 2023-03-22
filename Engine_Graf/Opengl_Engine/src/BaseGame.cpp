#include "baseGame.h"

DllExport BaseGame::BaseGame()
{	
	window = NULL;
	renderer = NULL;
	imGuiEngine = NULL;
	timer = NULL;
}

DllExport BaseGame::~BaseGame()
{
	if (window != NULL) { delete window; }
	if (renderer != NULL) { delete renderer; }
	if (imGuiEngine != NULL) { delete imGuiEngine; }
	if (timer != NULL) { delete timer; }
}

DllExport void BaseGame::setBaseGameClases()
{
	window = Window::getWindow();
	renderer = Renderer::getRenderer();
	imGuiEngine = ImGuiEngine::getImGuiEngine();
	timer = Timer::getTimer();
}

DllExport void BaseGame::runEngine()
{
	setBaseGameClases();	
	
	init();

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();

		timer->updateDeltaTime();

		imGuiEngine->imGuiStartDraw();	

		input();

		update();

		draw();

		imGuiEngine->imGuiEndDraw();
		
		glfwSwapBuffers(window->getNativeWindow());
		
		glfwPollEvents();
	}

	deinit();
}