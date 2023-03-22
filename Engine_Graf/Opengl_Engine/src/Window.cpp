#include "Window.h"

Window* Window::_window = NULL;

DllExport Window::Window()
{
	createWindow();
}

DllExport Window* Window::getWindow()
{
	if (_window == NULL)
	{
		_window = new Window();
	}

	return _window;
}

DllExport Window::~Window()
{
	glfwTerminate();
}

DllExport int Window::initGlfw()
{
	return glfwInit();
}

DllExport void Window::initGlew()
{
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew initialization failed!" << std::endl;
	}
}

DllExport int Window::createWindow() //Aca se puede pedir el tamaño de la pantalla
{
	if (!initGlfw())
		return -1;

	_glfwWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGl_Engine", NULL, NULL);

	if (!_glfwWindow)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(_glfwWindow);

	glfwSwapInterval(1);

	initGlew();
}

DllExport GLFWwindow* Window::getNativeWindow()
{
	return _glfwWindow;
}
	
DllExport int Window::GetScreenWidth()
{
	return WINDOW_WIDTH;
}

DllExport int Window::GetScreenHeight()
{
	return WINDOW_HEIGHT;
}

DllExport bool Window::getWindowsShouldClose()
{
	return glfwWindowShouldClose;
}