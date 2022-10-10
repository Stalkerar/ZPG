#pragma once
#ifndef _SHADER
#define _SHADER
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Shader.h"

class Shader
{
public:
	Shader();
	~Shader();
	unsigned int GetCompiledShader(unsigned int type, const std::string& shader_sourc);

private:

};


#endif // !1#pragma once

