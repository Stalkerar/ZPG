#include "ShaderProgram.h"


void ShaderProgram::Update(glm::mat4 view,glm::vec3 pos )
{

	

	


	//setMat4fv(view, "viewMatrix");

	//if(this->getStatus())
	//setVec3f(pos, "posCamera");




	this->toUpdate = true;
}

void ShaderProgram::reset()
{
	this->toUpdate = false;
}

bool ShaderProgram::getUpdate()
{
	return this->toUpdate;
}

ShaderProgram::~ShaderProgram()  {

}



string ShaderProgram::getStatus() {
	if (this->dynamic_state == true)
	{
		return "dynamic";
	}
	else if (this->static_state == true)
	{
		return "static";
	}
	else
	{
		return "special";
	}
}

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

	glUseProgram(0);


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


void ShaderProgram::setInteger(GLuint value, const GLchar* name)
{
	this->use();
	GLint idModelTransform = glGetUniformLocation(this->programId, name);
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
	}
	glUniform1i(idModelTransform, (value));

	this->unuse();


}

void ShaderProgram::setBool(bool value, const GLchar* name)
{
	this->use();
	GLint idModelTransform = glGetUniformLocation(this->programId, name);
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
	}
	glUniform1i(idModelTransform, (value));

	this->unuse();
}

void ShaderProgram::setFloat(float value, const GLchar* name)
{
	this->use();
	GLint idModelTransform = glGetUniformLocation(this->programId, name);
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
	}
	glUniform1f(idModelTransform, (value));
	this->unuse();
}

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile,bool _static_state,bool _dynamic_state)
{
	this->dynamic_state = _dynamic_state;
	this->static_state = _static_state;

	this->programId = this->loadShaderProgram(vertexShaderFile, fragmentShaderFile);
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


