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




unsigned int ShaderProgram::sendModelShader()
{
	GLint idModelTransform = glGetUniformLocation(programId, "modelMatrix");
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
		return -1;
	}
	glUseProgram(programId);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &object->getMatrix()[0][0]);

	return 0;
}

unsigned int ShaderProgram::sendViewShader()
{
	GLint idModelTransform = glGetUniformLocation(programId, "viewMatrix");
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
		return -1;
	}
	glUseProgram(programId);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &camera->getCamera()[0][0]);

	return 0;
}

unsigned int ShaderProgram::sendProjectionShader()
{
	GLint idModelTransform = glGetUniformLocation(programId, "projectionMatrix");
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
		return -1;
	}
	glUseProgram(programId);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &camera->getCamera()[0][0]);

	return 0;
}


