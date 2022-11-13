#pragma once
#ifndef _RENDERER
#define _RENDERER


#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Object_manager.h"
#include "Scene.h"

class Renderer
{
public:
	void draw(Object_manager*,Scene*);
	void init(Object_manager*, Scene*);

	Renderer();
	~Renderer();

private:
	int objCount = 0;
	int modelCount = 0;
};


#endif // !1