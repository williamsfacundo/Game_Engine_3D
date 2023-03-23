#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"entity.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"
#include "ShaderType.h"

class Entity2d : public Entity
{
protected:
	VertexArray* _va;

	VertexBuffer* _vb;
	
	VertexBufferLayout* _layout;
	
	IndexBuffer* _ib;
	
	Shader* _shader;

	ShaderType _shaderType;

	glm::vec3 _vertices[4];

	DllExport virtual void  setVertices() = 0;
	DllExport virtual void  setIndixs() = 0;

public:
	DllExport Entity2d(glm::vec3 initialPosition);
	DllExport ~Entity2d();

	DllExport glm::vec3* getVertices();

	DllExport void draw();
	DllExport virtual void calculateVertices() = 0;
};

#endif