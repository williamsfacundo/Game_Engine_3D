#include "Entity3d.h"

DllExport Entity3d::Entity3d() : Entity()
{
	_vertexArray = NULL;

	_vertexBuffer = NULL;

	_vertexBufferLayout = NULL;

	_indexBuffer = NULL;

	_shader = NULL;

	_shaderType = ShaderType::noTexture; 

	_xRotationMatrix = mat4();

	_yRotationMatrix = mat4();

	_zRotationMatrix = mat4();

	_translationMatrix = mat4();

	_rotationMatrix = mat4();

	_scalingMatrix = mat4();

	_modelMatrix = mat4();

	_mvpMatrix = mat4();	
}

DllExport Entity3d::~Entity3d()
{
	if(_vertexArray != NULL) { delete _vertexArray; }
	if (_vertexBuffer != NULL) { delete _vertexBuffer; }
	if (_vertexBufferLayout != NULL) { delete _vertexBufferLayout; }
	if (_indexBuffer != NULL) { delete _indexBuffer; }
	if (_shader != NULL) { delete _shader; }	
}

DllExport void Entity3d::updateModelMatrix()
{
	_translationMatrix = translate(mat4(1.0f), getPosition());

	_scalingMatrix = scale(mat4(1.0f), getScale());

	_xRotationMatrix = rotate(mat4(1.0f), radians(getRotation().x), vec3(1.0f, 0.0f, 0.0f));

	_yRotationMatrix = rotate(mat4(1.0f), radians(getRotation().y), vec3(0.0f, 1.0f, 0.0f));

	_zRotationMatrix = rotate(mat4(1.0f), radians(getRotation().z), vec3(0.0f, 0.0f, 1.0f));

	_rotationMatrix = _xRotationMatrix * _yRotationMatrix * _zRotationMatrix;

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;
}

DllExport void Entity3d::updateMVPMatrix()
{
	_mvpMatrix = Renderer::getRenderer()->getProjectionMatrix() * Camera::getCamera()->getView() * _modelMatrix;
}

void Entity3d::setVertexArray(VertexArray* vertexArray)
{
	_vertexArray = vertexArray;
}

void Entity3d::setVertexBuffer(VertexBuffer* vertexBuffer)
{
	_vertexBuffer = vertexBuffer;
}

void Entity3d::setVertexBufferLayout(VertexBufferLayout* vertexBufferLayout)
{
	_vertexBufferLayout = vertexBufferLayout;
}

void Entity3d::setIndexBuffer(IndexBuffer* indexBuffer)
{
	_indexBuffer = indexBuffer;
}

void Entity3d::setShader(Shader* shader)
{
	_shader = shader;
}

void Entity3d::setShaderType(ShaderType shaderType)
{
	_shaderType = shaderType;
}

VertexArray* Entity3d::getVertexArray()
{
	return _vertexArray;
}

VertexBuffer* Entity3d::getVertexBuffer()
{
	return _vertexBuffer;
}

VertexBufferLayout* Entity3d::getVertexBufferLayout()
{
	return _vertexBufferLayout;
}

IndexBuffer* Entity3d::getIndexBuffer()
{
	return _indexBuffer;
}

Shader* Entity3d::getShader()
{
	return _shader;
}

ShaderType Entity3d::getShaderType()
{
	return _shaderType;
}

DllExport void Entity3d::draw()
{
	updateModelMatrix();

	updateMVPMatrix();

	_shader->bind();

	_shader->setUniformsMat4f("u_MVP", _mvpMatrix);

	Renderer::getRenderer()->Draw(_vertexArray, _indexBuffer, _shader);

	_shader->unbind();
}