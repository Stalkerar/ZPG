#pragma once
#ifndef _TRANSFORMATION
#define _TRANSFORMATION

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "Object.h"
#include "Trotate.h"



class Transformation: public Object
{
public:

	void addTransformation(Object* t);
	glm::mat4 getMatrix();
	void setModalMatrix();

private:
	vector <Object*> transformations;
	glm::mat4 Model = glm::mat4(1.0f);
};





#endif 