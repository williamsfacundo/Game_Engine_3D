#ifndef SPRITE_H
#define SPRITE_H

#include "Entity2d.h"
#include "Texture.h"

class Sprite : public Entity2d
{
private:
	Texture* _texture;
	
	float _positions[16];

	unsigned int _indices[6];

	DllExport void setVertices();

	DllExport void setIndices();	

	DllExport void initSprite();	

public:
	DllExport Sprite(std::string imageName);
	DllExport ~Sprite();

	DllExport void setTexture(std::string imageName);

	DllExport void drawTexture();
};

#endif