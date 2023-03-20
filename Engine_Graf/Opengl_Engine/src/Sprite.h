#pragma once

#include "Entity2d.h"
#include <vector>

class Sprite : public Entity2d
{

private:

	Texture* _texture;

	int _width;
	int _height;

	unsigned int indices[6];

	DllExport void setVertices();	
	DllExport void setIndixs();	
	DllExport void calculateVertices();

	DllExport void initSprite();

protected:

	float positions[16];

public:

	DllExport Sprite();
	DllExport Sprite(std::string imageName, int initPositionX, int initPositionY);
	DllExport ~Sprite();

	DllExport void setTexture(std::string imageName);	
	
	DllExport void drawTexture();
};