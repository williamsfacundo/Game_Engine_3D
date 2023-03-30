#include "Camera.h"

Camera* Camera::_camera = NULL;

DllExport Camera::Camera()
{
	_cameraPosition = vec3(0.0f, 0.0f, 250.0f);
	_cameraTarget = vec3(0.0f, 0.0f, 0.0f);
	_cameraReverseDirection = normalize(_cameraPosition - _cameraTarget);
	_cameraRight = normalize(cross(UpVector, _cameraReverseDirection));
	_cameraUp = cross(_cameraReverseDirection, _cameraRight);
	
	_viewMatrix = lookAt(_cameraPosition, _cameraTarget, _cameraUp);
}

DllExport Camera::~Camera()
{

}

DllExport Camera* Camera::getCamera()
{
	if (_camera == NULL)
	{
		_camera = new Camera();
	}

	return _camera;
}

DllExport void Camera::addCameraPosition(vec3 newValue)
{
	_cameraPosition += newValue;
}

DllExport void Camera::setCameraPosition(vec3 newPosition)
{
	_cameraPosition = newPosition;
}

DllExport void Camera::setCameraTarget(vec3 newTarget)
{
	_cameraTarget = newTarget;
}

DllExport vec3 Camera::getCameraPosition()
{
	return _cameraPosition;
}

DllExport vec3 Camera::getCameraTarget()
{
	return _cameraTarget;
}

DllExport mat4 Camera::getViewMatrix()
{
	return _viewMatrix;
}

DllExport void Camera::calculateViewMatrix()
{
	_cameraReverseDirection = normalize(_cameraPosition - _cameraTarget);
	_cameraRight = normalize(cross(UpVector, _cameraReverseDirection));
	_cameraUp = cross(_cameraReverseDirection, _cameraRight);

	_viewMatrix = lookAt(_cameraPosition, _cameraTarget, _cameraUp);
}

DllExport void Camera::firstPersonCameraFollow(vec3 objectPosition, vec3 objectDirection)
{
	_cameraPosition = objectPosition;

	_cameraTarget = _cameraPosition + objectDirection;

	calculateViewMatrix();
}

DllExport void Camera::thirdPersonCameraFollow(vec3 objectPosition, vec3 offset)
{
	_cameraPosition = objectPosition + offset;
	
	_cameraTarget = objectPosition;

	calculateViewMatrix();
}