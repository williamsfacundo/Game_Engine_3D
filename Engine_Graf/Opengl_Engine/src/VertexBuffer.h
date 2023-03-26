#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "DDLExport.h"

class VertexBuffer
{
private:
	unsigned int _vertexBufferID;

public:
	DllExport VertexBuffer(const void* data, unsigned int size);
	DllExport ~VertexBuffer();

	DllExport void updateVertexBufferData(const void* data, unsigned int size);

	DllExport void bind();
	DllExport void unbind();
};

#endif