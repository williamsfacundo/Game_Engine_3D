#ifndef TIMER_H
#define TIMER_H

#include "glfw3.h"

#include "DDLExport.h"

class Timer
{
private:
	static Timer* _timer;
	
	float deltaTime;
	float oldTime;

	DllExport Timer();

public:
	DllExport ~Timer();

	DllExport static Timer* getTimer();

	DllExport float timeBetweenFrames();

	DllExport void updateDeltaTime();
};

#endif