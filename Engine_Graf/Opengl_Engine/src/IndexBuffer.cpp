#include "IndexBuffer.h"

#include "Renderer.h"
#include "MyAssert.h"

DllExport IndexBuffer::IndexBuffer(const unsigned* data, unsigned int count) : _count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLCall(glGenBuffers(1, &_rendererID));

	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));

	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

DllExport IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &_rendererID));
}

DllExport void IndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
}

DllExport void IndexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

DllExport unsigned int IndexBuffer::GetCount()
{
	return _count;
}