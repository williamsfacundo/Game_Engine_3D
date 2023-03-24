#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	 ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* funtion, const char* file, int line);

#endif