#ifndef TIMER_H
#define TIMER_H

#include "glfw3.h"

#include "DDLExport.h"

class Timer
{
private:
	static Timer* _timer;
	
	double _deltaTime;
	double _oldTime;

	DllExport Timer();

public:
	DllExport ~Timer();

	DllExport static Timer* getTimer();

	DllExport double timeBetweenFrames();

	DllExport void updateDeltaTime();
};

#endif