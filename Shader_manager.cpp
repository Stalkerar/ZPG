#include "Shader_manager.h"



using namespace std;


Shader_Manager::Shader_Manager()
{
	this->shaders = new ShaderProgram*[sizeof(ShaderProgram)*100];

}

Shader_Manager::~Shader_Manager()
{

}

void Shader_Manager::addShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	this->shaders[this->shaderCount] = new ShaderProgram(vertexShaderFile, fragmentShaderFile);
	this->shaderCount++;

}

int Shader_Manager::getCount()
{
	return this->shaderCount;
}

ShaderProgram* Shader_Manager::getShaderProgram(int idx)
{
	return this->shaders[idx];
}

