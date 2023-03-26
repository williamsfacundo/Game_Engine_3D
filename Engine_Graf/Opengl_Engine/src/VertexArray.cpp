#include "VertexArray.h"

#include "VertexBufferLayout.h"
#include "Renderer.h"

DllExport VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &_vertexArrayId));
}

DllExport VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &_vertexArrayId));
}

DllExport void VertexArray::AddBuffer(VertexBuffer& vb, VertexBufferLayout* layout)
{
	bind();
	vb.bind();
	const auto& elements = layout->GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout->GetStride(), (const void*)offset));
		offset += element.count * VertexbufferElement::GetSizeOfType(element.type);
	}
}

DllExport void VertexArray::bind()
{
	GLCall(glBindVertexArray(_vertexArrayId));
}

DllExport void VertexArray::unbind()
{
	GLCall(glBindVertexArray(0));
}