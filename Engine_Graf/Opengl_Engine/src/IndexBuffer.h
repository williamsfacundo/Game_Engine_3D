#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "DDLExport.h"

class IndexBuffer
{
private:
	unsigned int _rendererID;
	unsigned int _count;

public:
	DllExport IndexBuffer(const unsigned* data, unsigned int count);
	DllExport ~IndexBuffer();

	DllExport void bind();
	DllExport void unbind();

	DllExport unsigned int getCount();
};

#endif