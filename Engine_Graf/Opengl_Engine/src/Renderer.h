#ifndef RENDERER_H
#define RENDERER_H

#include "glm/gtc/matrix_transform.hpp"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Window.h"
#include "MyAssert.h"

class Renderer
{
private:	
	static Renderer* _renderer;
	
	glm::mat4 _projectionMatrix;	
	
	DllExport Renderer();

public:	
	DllExport ~Renderer();

	DllExport void initRenderer();
	
	DllExport static Renderer* getRenderer();
	
	DllExport glm::mat4 getProjectionMatrix();	
	
	DllExport void Draw(VertexArray* va, IndexBuffer* ib, Shader* shader);
	
	DllExport void Clear();
};

#endif