#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

class Window
{
private:
	static const int WINDOW_WIDTH = 1080;
	static const int WINDOW_HEIGHT = 720;
	
	static Window* _window;
	
	GLFWwindow* _glfwWindow;
	
	DllExport Window();

public:
	DllExport static Window* getWindow();
	DllExport ~Window();

	DllExport int initGlfw();
	DllExport void initGlew();

	DllExport int createWindow();

	DllExport GLFWwindow* getNativeWindow();

	DllExport static int GetScreenWidth();
	DllExport static int GetScreenHeight();

	DllExport bool getWindowsShouldClose();
};

#endif