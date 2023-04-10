#ifndef ENTITY_H
#define ENTITY_H

#include <glm/vec3.hpp>

#include "DDLExport.h"

using namespace glm;

class Entity
{
private:	
	vec3 _position;
	vec3 _rotation;
	vec3 _scale;

	vec3 _right;
	vec3 _up;
	vec3 _front;

protected:
	DllExport Entity();

public:
	DllExport ~Entity();

	DllExport void addPosition(vec3 value);
	DllExport void addScale(vec3 value);
	DllExport void addRotation(vec3 value);

	DllExport void addRight(vec3 value);
	DllExport void addUp(vec3 value);
	DllExport void addFront(vec3 value);
	
	DllExport void setPosition(vec3 newPosition);
	DllExport void setRotation(vec3 newRotation);
	DllExport void setScale(vec3 newScale);

	DllExport void setRight(vec3 newRight);
	DllExport void setUp(vec3 newUp);
	DllExport void setFront(vec3 newFront);

	DllExport vec3 getPosition();
	DllExport vec3 getRotation();
	DllExport vec3 getScale();

	DllExport vec3 getRight();
	DllExport vec3 getUp();
	DllExport vec3 getFront();
};

#endif