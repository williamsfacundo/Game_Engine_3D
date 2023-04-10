#include "RectangleShape.h"

DllExport RectangleShape::RectangleShape() : Entity2d()
{
	setVertices();
	setIndices();

	setVertexArray(new VertexArray());

	setVertexBuffer(new VertexBuffer(_positions, 4 * 4 * sizeof(float)));

	setVertexBufferLayout(new VertexBufferLayout());

	getVertexBufferLayout()->Push<float>(2);

	getVertexArray()->AddBuffer(*getVertexBuffer(), getVertexBufferLayout());

	getVertexArray()->bind();

	setIndexBuffer(new IndexBuffer(_indices, 6));

	setShaderType(ShaderType::noTexture);

	setShader(new Shader(getShaderType()));
	
	getShader()->bind();
	
	getShader()->setUniforms4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);

	getVertexArray()->unbind();
	
	getVertexBuffer()->unbind();
	
	getIndexBuffer()->unbind();
	
	getShader()->unbind();
}

DllExport void RectangleShape::setColor(glm::vec4 RGBA)
{
	getShader()->bind();

	getShader()->setUniforms4f("u_Color", RGBA.x, RGBA.y, RGBA.z, RGBA.w);

	getShader()->unbind();
}

DllExport void RectangleShape::setVertices()
{
	_width = 100;
	_height = 100;

	_positions[0] = -50.0f;
	_positions[1] = -50.0f;

	_positions[2] = 50.0f;
	_positions[3] = -50.0f;

	_positions[4] = 50.0f;
	_positions[5] = 50.0f;

	_positions[6] = -50.0f;
	_positions[7] = 50.0f;
}

DllExport void RectangleShape::setIndices()
{
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	_indices[3] = 2;
	_indices[4] = 3;
	_indices[5] = 0;
}