#include "VertexBuffer.h"

#include "Renderer.h"

DllExport VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &_vertexBufferId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

DllExport VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &_vertexBufferId));
}

DllExport void VertexBuffer::updateVertexBufferData(const void* data, unsigned int size)
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId));
	GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}

DllExport void VertexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId));
}

DllExport void VertexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}