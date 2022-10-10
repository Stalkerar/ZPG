#pragma once
#ifndef _SHADER_M
#define _SHADER_M
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Shader.h"
#include "Object.h"
#include "ShaderProgram.h"

class Shader_Manager
{
public:
	Shader_Manager();
	~Shader_Manager();
	void run();
	void addShader(const std::string& , const std::string& );
	ShaderProgram* getShaderProgram(int );

private:
	
	ShaderProgram** shaders;
	int shaderCount = 0;

};

#endif // !1#pragma once
