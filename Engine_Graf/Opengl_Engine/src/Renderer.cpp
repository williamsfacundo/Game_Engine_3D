
#include "Renderer.h"

Renderer* Renderer::_renderer = NULL;

DllExport Renderer::Renderer()
{
	initRenderer();
}

Renderer::~Renderer()
{
		
}

DllExport void Renderer::initRenderer()
{
	_projectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 1000.0f);	
}

DllExport Renderer* Renderer::getRenderer()
{
	if (_renderer == NULL)
	{
		_renderer = new Renderer();
	}

	return _renderer;
}

DllExport glm::mat4 Renderer::getProjectionMatrix()
{
	return _projectionMatrix;
}

DllExport void Renderer::Draw(VertexArray* va, IndexBuffer* ib, Shader* shader)
{
	shader->bind();
	va->bind();	
	ib->bind();	

	GLCall(glDrawElements(GL_TRIANGLES, ib->getCount(), GL_UNSIGNED_INT, NULL));

	shader->unbind();
	va->unbind();
	ib->unbind();
}

DllExport void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}