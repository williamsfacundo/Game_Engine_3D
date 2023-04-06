#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

#include "DDLExport.h"
#include "Input.h"
#include "Timer.h"
#include "MoveTypeEnum.h"

using namespace glm;

class Camera
{
private:
	static Camera* _camera;

	const vec3 InitialPosition = vec3(0.0f, 0.0f, 10.0f);
	const vec3 WorldOrigin = vec3(0.0f, 0.0f, 0.0f);
	const vec3 WorldUp = vec3(0.0f, 1.0f, 0.0f);

	const float BaseSpeed = 100.0f;

	Timer* _timer;

	MoveTypeEnum _depthMovement;
	MoveTypeEnum _sidewaysMovement;

	vec3 _position;
	vec3 _direction;
	vec3 _right;
	vec3 _up;
	vec3 _front;

	mat4 _view;

	float _moveSpeed;

	Camera();

public:

	DllExport static Camera* getCamera();	

	DllExport void addPosition(vec3 newPos);

	DllExport void subtractPosition(vec3 newPos);

	DllExport mat4 getView();

	DllExport void updateView();

	DllExport void cameraInput();

	DllExport void cameraMovement();
};

#endif