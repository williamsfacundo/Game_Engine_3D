#ifndef CUBE_H
#define CUBE_H

#include "Entity3d.h"

class Cube : Entity3d
{	
private:
	DllExport virtual void setVertices() = 0;

	DllExport virtual void setIndices() = 0;

public:
	Cube();
	~Cube();
};

#endif