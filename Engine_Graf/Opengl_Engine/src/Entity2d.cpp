#include "Entity2d.h"

#include "ImGuiEngine.h"

DllExport Entity2d::Entity2d(glm::vec3 initialPosition) : Entity(initialPosition)
{
	_va = NULL;
	_vb = NULL;
	_layout = NULL;
	_ib = NULL;
	_shader = NULL;

	_shaderType = ShaderType::noTexture; 

	_vertices[0] = glm::vec3();
	_vertices[1] = glm::vec3();
	_vertices[2] = glm::vec3();
	_vertices[3] = glm::vec3();
}

DllExport Entity2d::~Entity2d()
{
	delete _va;
	delete _vb;
	delete _layout;
	delete _ib;
	delete _shader;
}

DllExport glm::vec3* Entity2d::getVertices()
{
	return _vertices;
}

DllExport void Entity2d::draw()
{
	ImGuiEngine::getImGuiEngine()->imGuiDrawObject(this, getLocalId());

	glm::mat4 mvp = Renderer::getRenderer()->getProjectionMatrix() * Camera::getCamera()->getViewMatrix() * getModelMatrix();

	_shader->bind();
	_shader->setUniformsMat4f("u_MVP", mvp);

	Renderer::getRenderer()->Draw(_va, _ib, _shader);
}