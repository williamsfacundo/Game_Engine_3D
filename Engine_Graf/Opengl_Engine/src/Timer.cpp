#include "Timer.h"

Timer* Timer::_timer = NULL;

Timer::Timer()
{
	deltaTime = 0.0f;
	oldTime = 0.0f;
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
	return deltaTime;
}

DllExport void Timer::updateDeltaTime()
{
	deltaTime = glfwGetTime() - oldTime;
	oldTime = glfwGetTime();
}