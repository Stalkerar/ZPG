#pragma once
#ifndef _TROTATE
#define _TROTATE

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Object.h"

class Trotate: public Object
{
public:
	void setRotation(float,glm::vec3);
	glm::mat4 getMatrix();
	
private:
	glm::mat4 Model;

};

#endif