#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray
{
private:
	unsigned int _vertexArrayId;

public:
	DllExport VertexArray();
	DllExport ~VertexArray();

	DllExport void AddBuffer(VertexBuffer& vb, VertexBufferLayout* layout);

	DllExport void bind();
	DllExport void unbind();
};

#endif