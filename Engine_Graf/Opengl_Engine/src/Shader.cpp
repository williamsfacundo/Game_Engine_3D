#include "Shader.h"

#include "Renderer.h"

DllExport Shader::Shader(ShaderType shaderType)
{
	_shaderId = 0;
		
	if (shaderType == ShaderType::whithTexture)
	{
		_fragmentSource = fragmentShaderWithTexture;
	}
	else if (shaderType == ShaderType::noTexture)
	{
		_fragmentSource = fragmentShaderNoTexture;
	}

	_shaderId = createShader(vertexShader, _fragmentSource);
}

DllExport Shader::~Shader()
{
	GLCall(glDeleteProgram(_shaderId));
}

DllExport void Shader::bind()
{
	GLCall(glUseProgram(_shaderId));
}

DllExport void Shader::unbind()
{
	GLCall(glUseProgram(0));
}

DllExport void Shader::setUniforms4f(string name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

DllExport void Shader::setUniformsMat4f(string name, mat4& matrix)
{
	GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

DllExport void Shader::setUniforms1f(string name, float value)
{
	GLCall(glUniform1f(getUniformLocation(name), value));
}

DllExport void Shader::setUniforms1i(string name, int value)
{
	GLCall(glUniform1i(getUniformLocation(name), value));
}

DllExport unsigned int Shader::getUniformLocation(string& name)
{
	if (_uniformLocationCache.find(name) != _uniformLocationCache.end())
	{
		return _uniformLocationCache[name];
	}

	GLCall(int location = glGetUniformLocation(_shaderId, name.c_str()));
	if (location == -1)
		cout << "Warning: uniform " << name << " doesn't exist!" << endl;

	_uniformLocationCache[name] = location;
	return location;
}

DllExport unsigned int Shader::compileShader(unsigned int type, string& source)
{
	GLCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

	if (result == GL_FALSE)
	{
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
		cout << message << std::endl;
		GLCall(glDeleteShader(id));
		return 0;
	}

	return id;	
}

DllExport unsigned int Shader::createShader(string& vertexShader, string& fragmentShader)
{
	GLCall(unsigned int program = glCreateProgram());
	
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}