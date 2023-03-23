
#include "Renderer.h"

#pragma region Assert

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

#pragma endregion

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
	Window* window = Window::getWindow();

	_projectionMatrix = glm::ortho(0.0f, (float)window->GetScreenWidth(), 0.0f, (float)window->GetScreenHeight(), -1.0f, 1.0f);
	//proj = glm::perspective(glm::radians(45.0f), static_cast<float>(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);
	_viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
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

DllExport void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

DllExport void Renderer::Draw(const VertexArray* va, const IndexBuffer* ib, const Shader* shader)
{
	shader->Bind();
	va->Bind();
	ib->Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr));
}