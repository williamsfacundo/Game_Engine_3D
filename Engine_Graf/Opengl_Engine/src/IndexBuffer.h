#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "DDLExport.h"

class IndexBuffer
{
private:
	unsigned int _rendererID;
	unsigned int _count;

public:
	DllExport IndexBuffer(const unsigned* data, unsigned int count); //Video: Abstracing OPENGL into Classes - Min: 14.43
	DllExport ~IndexBuffer();

	DllExport void Bind();
	DllExport void UnBind();

	DllExport unsigned int GetCount();
};

#endif