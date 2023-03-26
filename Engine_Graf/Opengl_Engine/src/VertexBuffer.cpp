#include "VertexBuffer.h"
#include "Renderer.h"
#include "MyAssert.h"

DllExport VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &_vertexBufferID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

DllExport VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &_vertexBufferID));
}

DllExport void VertexBuffer::updateVertexBufferData(const void* data, unsigned int size)
{

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID));
	GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}

DllExport void VertexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID));
}

DllExport void VertexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}