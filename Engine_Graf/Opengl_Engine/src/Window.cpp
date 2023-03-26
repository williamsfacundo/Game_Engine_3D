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

DllExport void Window::createWindow()
{
	if (!initGlfw())
	{
		return;
	}

	_glfwWindow = glfwCreateWindow(WindowWidth, WindowHeight, WindowName, NULL, NULL);

	if (!_glfwWindow)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(_glfwWindow);

	glfwSwapInterval(1);

	initGlew();
}

DllExport GLFWwindow* Window::getNativeWindow()
{
	return _glfwWindow;
}
	
DllExport int Window::getScreenWidth()
{
	return WindowWidth;
}

DllExport int Window::getScreenHeight()
{
	return WindowHeight;
}

DllExport bool Window::getWindowsShouldClose()
{
	return static_cast<bool>(glfwWindowShouldClose);
}