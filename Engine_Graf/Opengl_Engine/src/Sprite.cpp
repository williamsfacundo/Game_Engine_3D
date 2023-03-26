#include "Sprite.h"

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

	_positions[0] = -50.0f;
	_positions[1] = -50.0f;
	_positions[5] = -50.0f;
	_positions[4] = 50.0f;
	_positions[8] = 50.0f;
	_positions[9] = 50.0f;
	_positions[12] = -50.0f;
	_positions[13] = 50.0f;

	_positions[2] = 0.0f;
	_positions[3] = 0.0f;
	_positions[6] = 1.0f;
	_positions[7] = 0.0f;
	_positions[10] = 1.0f;
	_positions[11] = 1.0f;
	_positions[14] = 0.0f;
	_positions[15] = 1.0f;
}

void Sprite::setIndixs()
{
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	_indices[3] = 2;
	_indices[4] = 3;
	_indices[5] = 0;
}

void Sprite::calculateVertices()
{

}

void Sprite::initSprite()
{
	setVertices();
	setIndixs();

	_shaderType = ShaderType::whithTexture;
	
	_va = new VertexArray();
	_vb = new VertexBuffer(_positions, 4 * 4 * sizeof(float));
	_layout = new VertexBufferLayout();
	_ib = new IndexBuffer(_indices, 6);
	_shader = new Shader(_shaderType);
	
	_va->bind();	
	_vb->bind();
	_ib->Bind();
	_shader->Bind();

	_layout->Push<float>(2);		 
	_layout->Push<float>(2);

	_va->AddBuffer(*_vb, _layout);

	_va->unbind();
	_vb->unbind();
	_ib->UnBind();
	_shader->Unbind();
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

	_texture->bind(0);

	_shader->Bind();

	_shader->SetUniforms1i("u_Texture", 0);

	_shader->Unbind();

	_texture->unbind();
}

void Sprite::drawTexture()
{
	_texture->bind(0);

	draw();

	_texture->unbind();
}