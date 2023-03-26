#include "Texture.h"

DllExport Texture::Texture(const std::string& path)
{	
	_textureId = 0;
	_filePath = path;
	_width = 0;
	_height = 0;
	_BPP = 0;

	stbi_set_flip_vertically_on_load(1);
	_localBuffer = stbi_load(path.c_str(), &_width, &_height, &_BPP, 4);
	
	GLCall(glEnable(GL_BLEND));

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); 

	GLCall(glGenTextures(1, &_textureId));

	GLCall(glBindTexture(GL_TEXTURE_2D, _textureId));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer));

	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (_localBuffer)
	{
		stbi_image_free(_localBuffer);
	}
}

DllExport Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &_textureId));
}

DllExport int Texture::getWidth() 
{
	return _width;
}

DllExport int Texture::getHeight() 
{
	return _height;
}

DllExport void Texture::bind(unsigned int slot)
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));

	GLCall(glBindTexture(GL_TEXTURE_2D, _textureId));
}

DllExport void Texture::unbind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}