#include "Timer.h"

Timer* Timer::_timer = NULL;

Timer::Timer()
{
	_deltaTime = 0.0f;
	_oldTime = 0.0f;
}

Timer::~Timer()
{

}

DllExport Timer* Timer::getTimer()
{
	if (_timer == NULL)
	{
		_timer = new Timer();
	}

	return _timer;
}

DllExport double Timer::timeBetweenFrames()
{
	return _deltaTime;
}

DllExport void Timer::updateDeltaTime()
{
	_deltaTime = glfwGetTime() - _oldTime;
	_oldTime = glfwGetTime();
}