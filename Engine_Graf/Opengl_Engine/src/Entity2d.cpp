#include "Entity2d.h"

#include "ImGuiEngine.h"

DllExport Entity2d::Entity2d(glm::vec3 initialPosition) : Entity(initialPosition)
{
	_va = NULL;
	_vb = NULL;
	layout = NULL;
	_ib = NULL;
	shader = NULL;
	shaderType = ShaderType::noTexture; 
	vertices[0] = glm::vec3();
	vertices[1] = glm::vec3();
	vertices[2] = glm::vec3();
	vertices[3] = glm::vec3();
}

DllExport Entity2d::~Entity2d()
{
	delete _va;
	delete _vb;
	delete layout;
	delete _ib;
	delete shader;
}

DllExport glm::vec3* Entity2d::getVertices()
{
	return vertices;
}

DllExport void Entity2d::draw()
{
	ImGuiEngine::getImGuiEngine()->imGuiDrawObject(this, getLocalId());

	glm::mat4 mvp = Renderer::getRenderer()->getProjectionMatrix() * Renderer::getRenderer()->getRenderer()->getViewMatrix() * getModelMatrix();

	shader->Bind();
	shader->SetUniformsMat4f("u_MVP", mvp);

	Renderer::getRenderer()->Draw(_va, _ib, shader);
}