/*#include "TriangleShape.h"

DllExport TriangleShape::TriangleShape(glm::vec4 RGBA) : Entity2d()
{
	setVertices();

	setIndices();
	
	_shaderType = ShaderType::noTexture;
	
	_vertexArray = new VertexArray();
	_vertexBuffer = new VertexBuffer(_positions, 4 * 4 * sizeof(float));
	_vertexBufferLayout = new VertexBufferLayout();
	_shader = new Shader(_shaderType);
	_indexBuffer = new IndexBuffer(_indices, 3);
		
	_vertexArray->bind();
	_shader->bind();
	
	_vertexBufferLayout->Push<float>(2);

	_vertexArray->AddBuffer(*_vertexBuffer, _vertexBufferLayout);
	
	_shader->setUniforms4f("u_Color", RGBA.x, RGBA.y, RGBA.z, RGBA.w);

	_vertexArray->unbind();
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

DllExport void TriangleShape::setIndixs()
{
	
}

DllExport void TriangleShape::calculateVertices()
{
	
}*/