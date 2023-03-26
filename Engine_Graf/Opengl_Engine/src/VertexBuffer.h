#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "DDLExport.h"

#include "MyAssert.h"

class VertexBuffer
{
private:
	unsigned int _vertexBufferId;

public:
	DllExport VertexBuffer(const void* data, unsigned int size);
	DllExport ~VertexBuffer();

	DllExport void updateVertexBufferData(const void* data, unsigned int size);

	DllExport void bind();
	DllExport void unbind();
};

#endif