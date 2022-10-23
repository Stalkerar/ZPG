#pragma once
#ifndef _RENDERER
#define _RENDERER


#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Obj_model.h"
#include "Scene.h"

class Renderer
{
public:
	void draw(GLuint,Scene*);
	Renderer();
	~Renderer();

private:
	int objCount = 0;

};


#endif // !1