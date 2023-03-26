#include "RectangleShape.h"

DllExport RectangleShape::RectangleShape(glm::vec3 initialPosition) : Shape(initialPosition)
{
	setVertices();
	setIndixs();
	calculateVertices();

	_va = new VertexArray();
	_vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	_layout = new VertexBufferLayout();
	_layout->Push<float>(2);		 //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
	_va->AddBuffer(*_vb, _layout);
	_va->bind();

	_ib = new IndexBuffer(indices, 6);

	_shaderType = ShaderType::noTexture;

	_shader = new Shader(_shaderType);
	_shader->bind();
	_shader->setUniforms4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);

	_va->unbind();
	_vb->unbind();
	_ib->unbind();
	_shader->unbind();
}

DllExport void RectangleShape::setColor(glm::vec4 RGBA)
{
	_shader->bind();

	_shader->setUniforms4f("u_Color", RGBA.x, RGBA.y, RGBA.z, RGBA.w);

	_shader->unbind();
}

DllExport void RectangleShape::setVertices()
{
	width = 100;
	height = 100;

	positions[0] = -50.0f;
	positions[1] = -50.0f;

	positions[2] = 50.0f;
	positions[3] = -50.0f;

	positions[4] = 50.0f;
	positions[5] = 50.0f;

	positions[6] = -50.0f;
	positions[7] = 50.0f;
}

DllExport void RectangleShape::setIndixs()
{
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;
}

DllExport void RectangleShape::calculateVertices()
{
	_vertices[0] = getPosition() + (-glm::vec3(1.0f * getScaleX() * width / 2, 0.0f, 0.0f)) + (glm::vec3(0.0f, 1.0f *  getScaleY() * height / 2, 0.0f));
	_vertices[1] = getPosition() + (glm::vec3(1.0f * getScaleX() * width / 2, 0.0f, 0.0f)) + (glm::vec3(0.0f, 1.0f *   getScaleY() * height / 2, 0.0f));
	_vertices[2] = getPosition() + (glm::vec3(1.0f * getScaleX() * width / 2, 0.0f, 0.0f)) + (-glm::vec3(0.0f, 1.0f *  getScaleY() * height / 2, 0.0f));
	_vertices[3] = getPosition() + (-glm::vec3(1.0f * getScaleX() * width / 2, 0.0f, 0.0f)) + (-glm::vec3(0.0f, 1.0f * getScaleY() * height / 2, 0.0f));
}