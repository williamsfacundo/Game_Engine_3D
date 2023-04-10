#include "Camera.h"

Camera* Camera::_camera = NULL;

Camera::Camera()
{
	_timer = Timer::getTimer();

	_depthMovement = MoveTypeEnum::NONE;

	_sidewaysMovement = MoveTypeEnum::NONE;

	_position = InitialPosition;

	_direction = normalize(_position - WorldOrigin);

	_right = normalize(cross(WorldUp, _direction));

	_up = normalize(cross(_direction, _right));

	_front = normalize(WorldOrigin - _position);

	updateView();

	_moveSpeed = BaseSpeed;

	_yaw = -90.0f;

	_pitch = 0.0f;

	_lastCursorX = Input::getMousePosition().x;

	_lastCursorY = Input::getMousePosition().y;

	_xCursorOffset = 0.0f;

	_yCursorOffset = 0.0f;
}

DllExport Camera* Camera::getCamera()
{
	if (_camera == NULL)
	{
		_camera = new Camera();
	}

	return _camera;
}

DllExport void Camera::addPosition(vec3 newPos)
{
	_position += newPos;

	updateView();
}

DllExport void Camera::subtractPosition(vec3 newPos)
{
	_position -= newPos;

	updateView();
}

DllExport mat4 Camera::getView()
{
	return _view;
}

DllExport void Camera::updateView()
{
	_view = lookAt(_position, _position + _front, WorldUp);
}

DllExport void Camera::updateFront()
{
	_xCursorOffset = (Input::getMousePosition().x - _lastCursorX) * Sensitivity;

	_yCursorOffset = (_lastCursorY - Input::getMousePosition().y) * Sensitivity;

	_lastCursorX = Input::getMousePosition().x;

	_lastCursorY = Input::getMousePosition().y;

	updateEulerAngles();

	_front = eulerToDirection(_yaw, _pitch);

	updateView();
}

DllExport void Camera::updateEulerAngles()
{
	_yaw += _xCursorOffset;

	_pitch += _yCursorOffset;

	if (_pitch > MaxPitch)
	{
		_pitch = MaxPitch;
	}
	else if (_pitch < MinPitch)
	{
		_pitch = MinPitch;
	}
}

DllExport void Camera::cameraInput()
{
	if (Input::getKeyPressed(GLFW_KEY_W))
	{
		_depthMovement = MoveTypeEnum::FORWARD;
	}
	else if (Input::getKeyPressed(GLFW_KEY_S))
	{
		_depthMovement = MoveTypeEnum::BACKWARD;
	}
	else
	{
		_depthMovement = MoveTypeEnum::NONE;
	}

	if (Input::getKeyPressed(GLFW_KEY_A))
	{
		_sidewaysMovement = MoveTypeEnum::LEFT;
	}
	else if (Input::getKeyPressed(GLFW_KEY_D))
	{
		_sidewaysMovement = MoveTypeEnum::RIGHT;
	}
	else
	{
		_sidewaysMovement = MoveTypeEnum::NONE;
	}
}

DllExport void Camera::cameraMovement()
{
	switch (_depthMovement)
	{
	case MoveTypeEnum::FORWARD:

		addPosition(_moveSpeed * _front * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	case MoveTypeEnum::BACKWARD:

		subtractPosition(_moveSpeed * _front * static_cast<float>(_timer->timeBetweenFrames()));

		break;
	default:
		break;
	}

	switch (_sidewaysMovement)
	{
	case MoveTypeEnum::LEFT:

		subtractPosition(normalize(cross(_front, _up)) * _moveSpeed * static_cast<float>(_timer->timeBetweenFrames()));
		
		break;
	case MoveTypeEnum::RIGHT:

		addPosition(normalize(cross(_front, _up)) * _moveSpeed * static_cast<float>(_timer->timeBetweenFrames()));
		
		break;	
	default:
		break;
	}
}

DllExport vec3 Camera::eulerToDirection(float yaw, float pitch)
{
	return vec3(cos(radians(yaw)) * cos(radians(pitch)), sin(radians(pitch)), sin(radians(yaw))) * cos(radians(pitch));
}