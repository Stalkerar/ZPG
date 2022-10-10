#include "ShaderProgram.h"

GLuint  ShaderProgram::loadShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	GLuint bufferID = 0;


	std::ifstream is_vs(vertexShaderFile);
	const std::string f_vs((std::istreambuf_iterator<char>(is_vs)), std::istreambuf_iterator<char>());

	std::ifstream is_fs(fragmentShaderFile);
	const std::string f_fs((std::istreambuf_iterator<char>(is_fs)), std::istreambuf_iterator<char>());

	bufferID = glCreateProgram();

	Shader* buffer1 = new Shader();
	Shader* buffer2 = new Shader();

	vs = buffer1->GetCompiledShader(GL_VERTEX_SHADER, f_vs);
	fs = buffer2->GetCompiledShader(GL_FRAGMENT_SHADER, f_fs);

	glAttachShader(bufferID, vs);
	glAttachShader(bufferID, fs);

	glLinkProgram(bufferID);
	glValidateProgram(bufferID);




	glDeleteShader(vs);
	glDeleteShader(fs);

	return bufferID;
}

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	programId = loadShaderProgram(vertexShaderFile, fragmentShaderFile);
}
