#ifndef TIMER_H
#define TIMER_H

#include "glfw3.h"

#include "DDLExport.h"

class Timer
{
private:
	static Timer* _timer;
	
	double deltaTime;
	double oldTime;

	DllExport Timer();

public:
	DllExport ~Timer();

	DllExport static Timer* getTimer();

	DllExport double timeBetweenFrames();

	DllExport void updateDeltaTime();
};

#endif