#pragma once
#ifndef _RENDERER
#define _RENDERER


#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Shader.h"
#include "Object.h"
#include "Shader_manager.h"
#include "Obj_model.h"


class Renderer
{
public:
	void draw(GLuint, Object*, unsigned int);
	Renderer();
	~Renderer();


};


#endif // !1