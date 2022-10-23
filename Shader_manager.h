#pragma once
#ifndef _SHADER_M
#define _SHADER_M
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Object.h"
#include "ShaderProgram.h"

class Shader_Manager
{
public:
	Shader_Manager();
	~Shader_Manager();
	void run();
	void addShader(const std::string&, const std::string&, Object*);
	ShaderProgram* getShaderProgram(int);
	int getCount();

private:
	
	ShaderProgram** shaders;
	int shaderCount = 0;

};

#endif // !1#pragma once
