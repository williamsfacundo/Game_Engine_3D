#include "TriangleShape.h"

DllExport TriangleShape::TriangleShape(glm::vec4 RGBA, glm::vec3 initialPosition) : Shape(initialPosition)
{
	setVertices();
	setIndixs();

	_va = new VertexArray();
	_vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	_layout = new VertexBufferLayout();
	_layout->Push<float>(2);		 //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
	_va->AddBuffer(*_vb, _layout);
	_va->Bind();

	_ib = new IndexBuffer(indices, 3);

	_shaderType = ShaderType::noTexture;

	_shader = new Shader(_shaderType);
	_shader->Bind();
	_shader->SetUniforms4f("u_Color", RGBA.x, RGBA.y, RGBA.z, RGBA.w);

	//texture = new Texture("res/textures/Logo.jpg");
	//texture->Bind();
	//shader->SetUniforms1i("u_Texture", 0);

	_va->Unbind();
	_vb->unbind();
	_ib->UnBind();
	_shader->Unbind();
}

DllExport void TriangleShape::setVertices()
{
	positions[0] = -50.0f;
	positions[1] = -50.0f;
	
	positions[2] = 50.0f;
	positions[3] = -50.0f;
	
	positions[4] = 0.0f;
	positions[5] = 50.0f;
}

DllExport void TriangleShape::setIndixs()
{
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}