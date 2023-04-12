#include "DeltaTime.h"

DeltaTime* DeltaTime::_timer = NULL;

DeltaTime::DeltaTime()
{
	_deltaTime = 0.0f;
	_oldTime = 0.0f;
}

DeltaTime::~DeltaTime()
{

}

DllExport DeltaTime* DeltaTime::getTimer()
{
	if (_timer == NULL)
	{
		_timer = new DeltaTime();
	}

	return _timer;
}

DllExport double DeltaTime::timeBetweenFrames()
{
	return _deltaTime;
}

DllExport void DeltaTime::updateDeltaTime()
{
	_deltaTime = glfwGetTime() - _oldTime;
	_oldTime = glfwGetTime();
}