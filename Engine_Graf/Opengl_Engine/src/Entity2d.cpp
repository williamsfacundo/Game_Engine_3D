#include "Entity2d.h"

#include "ImGuiEngine.h"

DllExport Entity2d::Entity2d(glm::vec3 initialPosition) : Entity(initialPosition)
{
	_va = NULL;
	_vb = NULL;
	_ib = NULL;
	shader = NULL;
}

DllExport Entity2d::~Entity2d()
{
	delete _va;
	delete _vb;
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