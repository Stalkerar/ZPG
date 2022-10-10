#pragma once
#ifndef _SHADERPROGRAM
#define _SHADERPROGRAM
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include"Shader.h"





class ShaderProgram
{

public:
	ShaderProgram(const std::string&, const std::string&);
	~ShaderProgram();
	GLuint loadShaderProgram(const std::string& , const std::string& );

private:
	GLuint programId,vs, fs;





};

#endif // !_SHADERPROGRAM