#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

#include "DDLExport.h"

using namespace glm;

class Camera
{
private:
	const vec3 UpVector = vec3(0.0f, 1.0f, 0.0f);
	const vec3 FrontVector = vec3(0.0f, 0.0f, -1.0f);
	
	static Camera* _camera;

	vec3 _cameraPosition;
	vec3 _cameraTarget;
	vec3 _cameraReverseDirection;
	vec3 _cameraRight;
	vec3 _cameraUp;

	mat4 _viewMatrix;

	DllExport Camera();

public:
	DllExport ~Camera();

	DllExport static Camera* getCamera();

	DllExport void addCameraPosition(vec3 newValue);

	DllExport void setCameraPosition(vec3 newPosition);
	DllExport void setCameraTarget(vec3 newTarget);

	DllExport vec3 getCameraPosition();
	DllExport vec3 getCameraTarget();
	DllExport mat4 getViewMatrix();

	DllExport void calculateViewMatrix();

	DllExport void firstPersonCameraFollow(vec3 objectPosition, vec3 objectDirection);

	DllExport void thirdPersonCameraFollow(vec3 objectPosition, vec3 offset);
};

#endif