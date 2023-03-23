#ifndef RENDERER_H
#define RENDERER_H

#include "glm/gtc/matrix_transform.hpp"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
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
	static Renderer* _renderer;
	
	glm::mat4 _projectionMatrix;
	glm::mat4 _viewMatrix;
	
	DllExport Renderer();

public:	
	DllExport ~Renderer();

	DllExport void initRenderer();
	
	DllExport static Renderer* getRenderer();
	
	DllExport glm::mat4 getProjectionMatrix();
	DllExport glm::mat4 getViewMatrix();

	DllExport Renderer(Renderer& other) = delete;
	DllExport void operator=(const Renderer&) = delete;

	DllExport void Clear() const;
	DllExport void Draw(const VertexArray* va, const IndexBuffer* ib, const Shader* shader)const;
};

#endif