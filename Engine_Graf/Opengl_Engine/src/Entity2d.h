#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"Entity.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "ShaderType.h"
#include "Camera.h"

class Entity2d : public Entity
{
private:
	VertexArray* _vertexArray;
	VertexBuffer* _vertexBuffer;	
	VertexBufferLayout* _vertexBufferLayout;	
	IndexBuffer* _indexBuffer;	
	Shader* _shader;
	ShaderType _shaderType;

	mat4 _xRotationMatrix;
	mat4 _yRotationMatrix;
	mat4 _zRotationMatrix;

	mat4 _translationMatrix;
	mat4 _rotationMatrix;
	mat4 _scalingMatrix;

	mat4 _modelMatrix;

	mat4 _mvpMatrix;	

	DllExport void updateModelMatrix();	
	DllExport void updateMVPMatrix();

protected:
	DllExport Entity2d();

	DllExport virtual void setVertices() = 0;

	DllExport virtual void setIndices() = 0;

	void setVertexArray(VertexArray* vertexArray);
	void setVertexBuffer(VertexBuffer* vertexBuffer);
	void setVertexBufferLayout(VertexBufferLayout* vertexBufferLayout);
	void setIndexBuffer(IndexBuffer* indexBuffer);
	void setShader(Shader* shader);
	void setShaderType(ShaderType shaderType);

	VertexArray* getVertexArray();
	VertexBuffer* getVertexBuffer();
	VertexBufferLayout* getVertexBufferLayout();
	IndexBuffer* getIndexBuffer();
	Shader* getShader();
	ShaderType getShaderType();
public:
	DllExport ~Entity2d();	

	DllExport void draw();
};

#endif