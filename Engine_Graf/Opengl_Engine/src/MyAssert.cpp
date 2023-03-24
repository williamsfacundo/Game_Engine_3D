#include "Assert.h"

#include <iostream>

#include "glfw3.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* funtion, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error (" << error << "); " << funtion <<
			" " << file << ":" << line << std::endl;
		return false;
	}

	return true;
}