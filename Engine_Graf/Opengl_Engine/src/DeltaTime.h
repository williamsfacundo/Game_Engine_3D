#ifndef DELTA_TIME_H
#define DELTA_TIME_H

#include "glfw3.h"

#include "DDLExport.h"

class DeltaTime
{
private:
	static DeltaTime* _timer;

	double _deltaTime;
	double _oldTime;

	DllExport DeltaTime();

public:
	DllExport ~DeltaTime();

	DllExport static DeltaTime* getTimer();

	DllExport double timeBetweenFrames();

	DllExport void updateDeltaTime();
};

#endif