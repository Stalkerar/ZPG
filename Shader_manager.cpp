#include "Shader_manager.h"
#include <stdio.h>
#include <iostream>

using namespace std;


Shader_Manager::Shader_Manager()
{
	ShaderProgram** shaders = new ShaderProgram * [100];

}

Shader_Manager::~Shader_Manager()
{

}

void Shader_Manager::addShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	shaders[shaderCount] = new ShaderProgram(vertexShaderFile, fragmentShaderFile);
	shaderCount++;

}



ShaderProgram* Shader_Manager::getShaderProgram(int idx)
{
	return shaders[idx];
}