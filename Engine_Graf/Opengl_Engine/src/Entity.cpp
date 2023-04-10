#include "Entity.h"

DllExport Entity::Entity()
{
	_position = vec3(0.0f, 0.0f, 0.0f);

	_rotation = vec3(0.0f, 0.0f, 0.0f);

	_scale = vec3(1.0f, 1.0f, 1.0f);

	_right = vec3(1.0f, 0.0f, 0.0f);

	_up = vec3(0.0f, 1.0f, 0.0f);

	_front = vec3(0.0f, 0.0f, 1.0f);
}

DllExport Entity::~Entity()
{

}

DllExport void Entity::addPosition(glm::vec3 value)
{
	_position += value;
}

DllExport void Entity::addScale(glm::vec3 value)
{
	_scale += value;
}

DllExport void Entity::addRotation(glm::vec3 value)
{
	_rotation += value;
}

DllExport void Entity::addRight(vec3 value)
{
	_right += value;
}

DllExport void Entity::addUp(vec3 value)
{
	_up += value;
}

DllExport void Entity::addFront(vec3 value)
{
	_front += value;
}

DllExport void Entity::setPosition(glm::vec3 newPosition)
{
	_position = newPosition;	
}

DllExport void Entity::setRotation(glm::vec3 newRotation)
{
	_rotation = newRotation;	
}

DllExport void Entity::setScale(glm::vec3 newScale)
{
	_scale = newScale;	
}

DllExport void Entity::setRight(vec3 newRight)
{
	_right = newRight;
}

DllExport void Entity::setUp(vec3 newUp)
{
	_up = newUp;
}

DllExport void Entity::setFront(vec3 newFront)
{
	_front = newFront;
}

DllExport vec3 Entity::getPosition()
{
	return _position;
}

DllExport vec3 Entity::getRotation()
{
	return _rotation;
}

DllExport vec3 Entity::getScale()
{
	return _scale;
}

DllExport vec3 Entity::getRight()
{
	return _right;
}

DllExport vec3 Entity::getUp()
{
	return _up;
}

DllExport vec3 Entity::getFront()
{
	return _front;
}