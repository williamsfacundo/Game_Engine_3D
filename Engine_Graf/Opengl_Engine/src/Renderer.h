#ifndef RENDERER_H
#define RENDERER_H

#include "GL/glew.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Window.h"

#pragma region Assert

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	 ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* funtion, const char* file, int line);

#pragma endregion

class Renderer
{
private:	
	DllExport Renderer();
	static Renderer* S_Renderer;

public:
	glm::mat4 proj;
	glm::mat4 view;
	
	DllExport ~Renderer();

	DllExport static Renderer* getRenderer();
	DllExport void initRenderer();

	DllExport Renderer(Renderer& other) = delete;
	DllExport void operator=(const Renderer&) = delete;

	DllExport void Clear() const;
	DllExport void Draw(const VertexArray* va, const IndexBuffer* ib, const Shader* shader)const;
};

#endif