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

void ShaderProgram::use()
{
	glUseProgram(this->programId);
}

void ShaderProgram::unuse()
{
	glUseProgram(0);
}


void ShaderProgram::setVec4f(glm::vec4 value, const GLchar* name)
{
	this->use();

	glUniform4fv(glGetUniformLocation(this->programId, name), 1, glm::value_ptr(value));

	this->unuse();
}




void ShaderProgram::setVec3f(glm::vec3 value, const GLchar* name)
{
	this->use();

	GLint idModelTransform = glGetUniformLocation(this->programId, name);
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
	}
	glUniform3fv(idModelTransform, 1, glm::value_ptr(value));
	this->unuse();
}


void ShaderProgram::setMat4fv(glm::mat4 value, const GLchar* name)
{
	this->use();
	GLint idModelTransform = glGetUniformLocation(this->programId, name);
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
	}

	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, glm::value_ptr(value));

	//this->unuse();
}







ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile,Object* in_object)
{
	this->programId = this->loadShaderProgram(vertexShaderFile,fragmentShaderFile);
	this->object = in_object;
}

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, Camera* in_camera)
{
	this->programId = this->loadShaderProgram(vertexShaderFile, fragmentShaderFile);
	this->camera = in_camera;
}


void ShaderProgram::setCamera(Camera* in)
{
	this->camera = in;
}



Object* ShaderProgram::getObject()
{
	return this->object;
}
