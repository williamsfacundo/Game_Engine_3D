#include "Entity.h"

DllExport Entity::Entity(glm::vec3 initialPosition)
{	
	_modelMatrix = glm::mat4();

	_translation = initialPosition;

	_rotation = glm::vec3(0, 0, 0);

	_scale = glm::vec3(1, 1, 0);
	
	UpdateTRSMat();
}

DllExport Entity::~Entity()
{
	
}

DllExport void Entity::UpdateTRSMat()
{
	_translationMatrix = glm::translate(glm::mat4(1.0f), _translation);

	_scalingMatrix = glm::scale(glm::mat4(1.0f), _scale);

	_xRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	_yRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	_zRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	_rotationMatrix = _xRotationMatrix * _yRotationMatrix * _zRotationMatrix;

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;
}

DllExport void Entity::addPosition(glm::vec3 positionToAdd)
{
	_translation += positionToAdd;

	UpdateTRSMat();
}

DllExport void Entity::addScale(glm::vec3 scaleToAdd)
{
	_scale += scaleToAdd;

	UpdateTRSMat();
}

DllExport void Entity::addRotation(glm::vec3 rotationToAdd)
{
	_rotation += rotationToAdd;

	UpdateTRSMat();
}

DllExport void Entity::setPosition(glm::vec3 newPosition)
{
	_translation = newPosition;

	UpdateTRSMat();
}

DllExport void Entity::setRotation(glm::vec3 newRotation)
{
	_rotation = newRotation;

	UpdateTRSMat();
}

DllExport void Entity::setScale(glm::vec3 newScale)
{
	_scale = newScale;

	UpdateTRSMat();
}

DllExport void Entity::setPositionX(float posX)
{
	_translation.x = posX;

	UpdateTRSMat();
}

DllExport void Entity::setPositionY(float posY)
{
	_translation.y = posY;

	UpdateTRSMat();
}

DllExport void Entity::setPositionZ(float posZ)
{
	_translation.z = posZ;

	UpdateTRSMat();
}

DllExport void Entity::setScaleX(float scalX)
{
	_scale.x = scalX;

	UpdateTRSMat();
}

DllExport void Entity::setScaleY(float scalY)
{
	_scale.y = scalY;

	UpdateTRSMat();
}

DllExport void  Entity::setScaleZ(float scalZ)
{
	_scale.z = scalZ;

	UpdateTRSMat();
}

DllExport void  Entity::setRotationX(float rotX)
{
	_rotation.x = rotX;

	UpdateTRSMat();
}

DllExport void  Entity::setRotationY(float rotY)
{
	_rotation.y = rotY;

	UpdateTRSMat();
}

DllExport void Entity::setRotationZ(float rotZ)
{
	_rotation.z = rotZ;

	UpdateTRSMat();
}

DllExport glm::vec3 Entity::getPosition()
{
	return _translation;
}

DllExport glm::vec3 Entity::getRotation()
{
	return _rotation;
}

DllExport glm::vec3 Entity::getScale()
{
	return _scale;
}

DllExport float Entity::getPositionX()
{
	return _translation.x;
}

DllExport float Entity::getPositionY()
{
	return _translation.y;
}

DllExport float Entity::getPositionZ()
{
	return _translation.z;
}
	  
DllExport float Entity::getScaleX()
{
	return _scale.x;
}

DllExport float Entity::getScaleY()
{
	return _scale.y;
}

DllExport float Entity::getScaleZ()
{
	return _scale.z;
}

DllExport float Entity::getRotationX()
{
	return _rotation.x;
}

DllExport float Entity::getRotationY()
{
	return _rotation.y;
}

DllExport float Entity::getRotationZ()
{
	return _rotation.z;
}

DllExport glm::mat4 Entity::getModelMatrix()
{
	return _modelMatrix;
}