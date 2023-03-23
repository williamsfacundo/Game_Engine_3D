#ifndef ENTITY_H
#define ENTITY_H

#include "DDLExport.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class Entity
{
private:	
	static int entitiesCount;
	
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;

	int _localId;

protected:
	
	glm::mat4 TRS = glm::mat4(1);

public:
	DllExport Entity(glm::vec3 initialPosition);
	DllExport ~Entity();

	DllExport void UpdateTRSMat();

	DllExport virtual void draw() = 0;

	DllExport void addPosition(glm::vec3 positionToAdd);
	DllExport void addScale(glm::vec3 scaleToAdd);
	DllExport void addRotation(glm::vec3 rotationToAdd);
	
	DllExport void setPosition(glm::vec3 newPosition);
	DllExport void setRotation(glm::vec3 newRotation);
	DllExport void setScale(glm::vec3 newScale);

	DllExport void setPositionX(float posX);
	DllExport void setPositionY(float posY);
	DllExport void setPositionZ(float posZ);

	DllExport void  setScaleX(float scalX);
	DllExport void  setScaleY(float scalY);
	DllExport void  setScaleZ(float scalZ);

	DllExport void  setRotationX(float rotX);
	DllExport void  setRotationY(float rotY);
	DllExport void  setRotationZ(float rotZ);

	DllExport glm::vec3 getPosition();
	DllExport glm::vec3 getRotation();
	DllExport glm::vec3 getScale();

	DllExport float getPositionX();
	DllExport float getPositionY();
	DllExport float getPositionZ();

	DllExport float getScaleX();
	DllExport float getScaleY();
	DllExport float getScaleZ();

	DllExport float getRotationX();
	DllExport float getRotationY();
	DllExport float getRotationZ();

	DllExport int getLocalId();
};

#endif