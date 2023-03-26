#include "Sprite.h"

Sprite::Sprite() : Entity2d(glm::vec3(0.0f))
{
	initSprite();
}

Sprite::Sprite(std::string imageName, glm::vec3 initialPosition) : Entity2d(initialPosition)
{	
	initSprite();

	setTexture(imageName);
}

Sprite::~Sprite()
{
	
}

void Sprite::setVertices()
{
	_width = 100;
	_height = 100;

	positions[0] = -50.0f;
	positions[1] = -50.0f;
	positions[5] = -50.0f;
	positions[4] = 50.0f;
	positions[8] = 50.0f;
	positions[9] = 50.0f;
	positions[12] = -50.0f;
	positions[13] = 50.0f;

	positions[2] = 0.0f;
	positions[3] = 0.0f;
	positions[6] = 1.0f;
	positions[7] = 0.0f;
	positions[10] = 1.0f;
	positions[11] = 1.0f;
	positions[14] = 0.0f;
	positions[15] = 1.0f;
}

void Sprite::setIndixs()
{
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;
}

void Sprite::calculateVertices()
{

}

void Sprite::initSprite()
{
	setVertices();
	setIndixs();

	_va = new VertexArray();
	_vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	_layout = new VertexBufferLayout();
	_layout->Push<float>(2);		 
	_layout->Push<float>(2);

	_va->AddBuffer(*_vb, _layout);
	_va->bind();

	_ib = new IndexBuffer(indices, 6);

	_shaderType = ShaderType::whithTexture;

	_shader = new Shader(_shaderType);

	_va->unbind();
	_vb->unbind();
	_ib->UnBind();
}

void Sprite::setTexture(std::string imageName)
{
	if (_texture == NULL)
	{
		_texture = new Texture("res/textures/" + imageName);
	}
	else
	{
		delete _texture;

		_texture = new Texture("res/textures/" + imageName);
	}

	_texture->Bind();

	_shader->Bind();

	_shader->SetUniforms1i("u_Texture", 0);

	_shader->Unbind();
}

void Sprite::drawTexture()
{
	_texture->Bind();

	draw();

	_texture->UnBind();
}