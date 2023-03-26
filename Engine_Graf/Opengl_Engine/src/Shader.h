#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "ShaderType.h"
#include "MyAssert.h"

using namespace std;
using namespace glm;

class Shader
{
private:	
	unsigned int _shaderId;

	unordered_map<string, int> _uniformLocationCache;
		
	string _fragmentSource;

#pragma region Shaders
	string vertexShader =
		//"#shader vertex\n"
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"layout(location = 1) in vec2 texCoord;"
		"\n"
		"out vec2 v_TexCoord;\n"
		"uniform mat4 u_MVP;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = u_MVP * position;\n"
		"	v_TexCoord = texCoord;\n"
		"};\n";

	string fragmentShaderWithTexture =
		//"#shader fragment\n"
		"#version 330 core\n"
		"\n"
		"	layout(location = 0) out vec4 color;"
		"\n"
		"	in vec2 v_TexCoord;"
		"\n"
		"	uniform vec4 u_Color;"
		"\n"
		"	uniform sampler2D u_Texture;"
		"\n"
		"void main()\n"
		"{\n"
		"	vec4 texColor = texture(u_Texture, v_TexCoord);"
		"\n"
		"	color = texColor;"
		"};\n";

	string fragmentShaderNoTexture =
		//"#shader fragment\n"
		"#version 330 core\n"
		"\n"
		"	layout(location = 0) out vec4 color;"
		"\n"
		"	uniform vec4 u_Color;"
		"\n"
		"void main()\n"
		"{\n"
		"	color = u_Color;"
		"};\n";
#pragma endregion

	DllExport unsigned int createShader(string& vertexShader, string& fragmentShader);
	DllExport unsigned int compileShader(unsigned int type, string& source);
	DllExport unsigned int getUniformLocation(string& name);

public:
	DllExport Shader(ShaderType shaderType);
	DllExport ~Shader();

	DllExport void bind();
	DllExport void unbind();
	
	DllExport void setUniforms1f(string name, float value);
	DllExport void setUniforms1i(string name, int value);
	DllExport void setUniforms4f(string name, float v0, float v1, float v2, float v3);
	DllExport void setUniformsMat4f(string name, mat4& matrix);
};

#endif