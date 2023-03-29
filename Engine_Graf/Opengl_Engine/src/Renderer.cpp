
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

	//First vector = position of the camera, second = position the camera is looking at, last = where in the world is the up
	_viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 250.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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

DllExport glm::mat4 Renderer::getViewMatrix()
{
	return _viewMatrix;
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