#include "TriangleShape.h"

DllExport TriangleShape::TriangleShape(glm::vec4 RGBA, glm::vec3 initialPosition) : Shape(initialPosition)
{
	setVertices();

	setIndices();

	_va = new VertexArray();
	_vb = new VertexBuffer(_positions, 4 * 4 * sizeof(float));

	_layout = new VertexBufferLayout();
	_layout->Push<float>(2);
	_va->AddBuffer(*_vb, _layout);
	_va->bind();

	_ib = new IndexBuffer(_indices, 3);

	_shaderType = ShaderType::noTexture;

	_shader = new Shader(_shaderType);
	_shader->bind();
	_shader->setUniforms4f("u_Color", RGBA.x, RGBA.y, RGBA.z, RGBA.w);

	_va->unbind();
	_vb->unbind();
	_ib->unbind();
	_shader->unbind();
}

DllExport void TriangleShape::setVertices()
{
	_positions[0] = -50.0f;
	_positions[1] = -50.0f;
	
	_positions[2] = 50.0f;
	_positions[3] = -50.0f;
	
	_positions[4] = 0.0f;
	_positions[5] = 50.0f;
}

DllExport void TriangleShape::setIndices()
{
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
}