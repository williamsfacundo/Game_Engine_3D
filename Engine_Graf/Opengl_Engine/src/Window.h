#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

class Window
{
private:
	static const int WindowWidth = 960;
	static const int WindowHeight = 960;

	const char* WindowName = "WILLIAMS";
	
	static Window* _window;
	
	GLFWwindow* _glfwWindow;
	
	DllExport Window();

public:
	DllExport static Window* getWindow();
	DllExport ~Window();

	DllExport int initGlfw();
	DllExport void initGlew();

	DllExport void createWindow();

	DllExport GLFWwindow* getNativeWindow();

	DllExport static int getScreenWidth();
	DllExport static int getScreenHeight();

	DllExport bool getWindowsShouldClose();
};

#endif