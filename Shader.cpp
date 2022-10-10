#include "Shader.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Shader::Shader()
{
	
}


Shader::~Shader()
{

}

unsigned int Shader::GetCompiledShader(unsigned int type, const std::string& shader_source)
{
	unsigned int id = glCreateShader(type);

	const char* c_source = shader_source.c_str();
	glShaderSource(id, 1, &c_source, nullptr);
	glCompileShader(id);

	GLint result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		GLchar* strInfoLog = new GLchar[length + 1];
		glGetShaderInfoLog(id, length, &length, strInfoLog);

		fprintf(stderr, "Compilation error in shader: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	return id;
}
