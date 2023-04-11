#include "Camera.h"

Camera* Camera::_camera = NULL;

Camera::Camera() : Entity()
{
	setPosition(InitialPosition);	

	setFront(DefaultFront);

	_cameraOffset = DefaultOffset;

	_cameraStyle = CameraStyle::FREE;
	
	updateView();
}

DllExport void Camera::setTarget(Entity* target)
{
	_target = target;
}

DllExport void Camera::setCameraStyle(CameraStyle cameraStyle)
{
	switch (cameraStyle)
	{
	case CameraStyle::FIRST_PERSON:
		
		if (_target != NULL)
		{
			_cameraStyle = cameraStyle;
		}

		break;
	case CameraStyle::THIRD_PERSON:
		
		if (_target != NULL)
		{
			_cameraStyle = cameraStyle;
		}

		break;
	case CameraStyle::FREE:
		
		_cameraStyle = cameraStyle;		

		break;
	default:

		_cameraStyle = cameraStyle;

		break;
	}

	if(_target != NULL)
	{
		_cameraStyle = cameraStyle;
	}

}

DllExport Camera* Camera::getCamera()
{
	if (_camera == NULL)
	{
		_camera = new Camera();
	}

	return _camera;
}

DllExport mat4 Camera::getView()
{
	return _view;
}

DllExport CameraStyle Camera::getCameraStyle()
{
	return _cameraStyle;
}

DllExport void Camera::updateView()
{
	switch (_cameraStyle)
	{
	case CameraStyle::FIRST_PERSON:
			
		setPosition(_target->getPosition());

		setFront(_target->getFront());

		_view = lookAt(getPosition(), getPosition() + getFront(), WorldUp);
		
		break;
	case CameraStyle::THIRD_PERSON:
		
		setPosition(_target->getPosition() + _cameraOffset);

		setFront(_target->getPosition());

		_view = lookAt(getPosition(), getFront(), WorldUp);
		
		break;
	case CameraStyle::FREE:
		
		_view = lookAt(getPosition(), getPosition() + getFront(), WorldUp);
		
		break;
	default:
		break;
	}
}