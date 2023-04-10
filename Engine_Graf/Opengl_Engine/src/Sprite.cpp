#include "Sprite.h"

Sprite::Sprite(std::string imageName) : Entity2d()
{	
	initSprite();

	setTexture(imageName);
}

Sprite::~Sprite()
{
	if(_texture != NULL)
	{
		delete _texture;
	}
}

void Sprite::setVertices()
{
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

void Sprite::setIndices()
{
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	_indices[3] = 2;
	_indices[4] = 3;
	_indices[5] = 0;
}

void Sprite::initSprite()
{
	setVertices();
	setIndices();

	setShaderType(ShaderType::whithTexture);
	
	setVertexArray(new VertexArray());
	setVertexBuffer(new VertexBuffer(_positions, 4 * 4 * sizeof(float)));
	setVertexBufferLayout(new VertexBufferLayout());
	setIndexBuffer(new IndexBuffer(_indices, 6));
	setShader(new Shader(getShaderType()));
	
	getVertexArray()->bind();	
	getVertexBuffer()->bind();
	getIndexBuffer()->bind();
	getShader()->bind();

	getVertexBufferLayout()->Push<float>(2);		 
	getVertexBufferLayout()->Push<float>(2);

	getVertexArray()->AddBuffer(*getVertexBuffer(), getVertexBufferLayout());

	getVertexArray()->unbind();
	getVertexBuffer()->unbind();
	getIndexBuffer()->unbind();
	getShader()->unbind();
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

	getShader()->bind();

	getShader()->setUniforms1i("u_Texture", 0);

	getShader()->unbind();

	_texture->unbind();
}

void Sprite::drawTexture()
{
	_texture->bind(0);

	draw();

	_texture->unbind();
}