#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

#include "DDLExport.h"
#include "Input.h"
#include "Entity.h"
#include "MoveTypeEnum.h"

using namespace glm;

enum class CameraStyle
{
	FIRST_PERSON = 0,
	THIRD_PERSON = 1,
	FREE = 2
};

class Camera : Entity
{
private:
	static Camera* _camera;

	const vec3 InitialPosition = vec3(0.0f, 0.0f, 0.0f);
	const vec3 WorldUp = vec3(0.0f, 1.0f, 0.0f);
	const vec3 DefaultFront = vec3(0.0f, 0.0f, -1.0f);
	const vec3 DefaultOffset = vec3(0.0f, 50.0f, -250);
	
	Entity* _target;
	
	mat4 _view;		

	vec3 _cameraOffset;

	CameraStyle _cameraStyle;

	Camera();
	
public:	
	DllExport static Camera* getCamera();	

	DllExport void setTarget(Entity* target);

	DllExport void setCameraStyle(CameraStyle cameraStyle);

	DllExport mat4 getView();

	DllExport CameraStyle getCameraStyle();

	DllExport void updateView();
};

#endif