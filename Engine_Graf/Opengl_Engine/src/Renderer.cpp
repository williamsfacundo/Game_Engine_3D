
#include "Renderer.h"

Renderer* Renderer::_renderer = NULL;

DllExport Renderer::Renderer()
{
	initRenderer();
}

Renderer::~Renderer()
{
	delete _renderer;
}

DllExport void Renderer::initRenderer()
{
	_projectionMatrix = glm::ortho(0.0f, (float)Window::getWindow()->GetScreenWidth(), 0.0f, (float)Window::getWindow()->GetScreenHeight(), -1.0f, 1.0f);
	
	_viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
	shader->Bind();
	va->Bind();	
	ib->Bind();	

	GLCall(glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, NULL));

	shader->Unbind();
	va->Unbind();
	ib->UnBind();
}

DllExport void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}