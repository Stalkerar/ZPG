#pragma once
#ifndef _TRANSLATE
#define _TRANSLATE

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Object.h"

class Ttranslate : public Object
{
public:
	void setTranslation(glm::vec3);
	glm::mat4 getMatrix();

private:
	glm::mat4 Model;

};

#endif