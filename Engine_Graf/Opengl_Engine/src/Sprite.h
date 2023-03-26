#ifndef SPRITE_H
#define SPRITE_H

#include <vector>

#include "Entity2d.h"

class Sprite : public Entity2d
{
private:
	unsigned int _indices[6];
	
	Texture* _texture;

	float _positions[16];
	
	int _width;
	int _height;

	DllExport void setVertices();
	DllExport void setIndixs();
	DllExport void calculateVertices();

	DllExport void initSprite();

public:
	DllExport Sprite(std::string imageName, glm::vec3 initialPosition);
	DllExport ~Sprite();

	DllExport void setTexture(std::string imageName);

	DllExport void drawTexture();
};

#endif