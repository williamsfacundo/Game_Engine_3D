#ifndef TEXTURE_H
#define TEXTURE_H

#include <stb_image/stb_image.h>

#include "Renderer.h"
#include "MyAssert.h"

using namespace std;

class Texture
{
private:
	unsigned int _textureId;

	unsigned char* _localBuffer;
	
	string _filePath;

	int _width; 
	int _height; 
	int _BPP;

public:
	DllExport Texture(const string& path);
	DllExport ~Texture();

	DllExport int getWidth();
	DllExport int getHeight();

	DllExport void bind(unsigned int slot = 0) const;
	DllExport void unbind() const;
};

#endif