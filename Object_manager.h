#pragma once
#ifndef _OBJECT_MANAGER
#define _OBJECT_MANAGER

#include <stdio.h>
#include <iostream>
//#include "drawobj.h"


using namespace std;

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  


//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  

#include <stdlib.h>
#include "Obj_model.h"


class Object_manager
{
public:
	Object_manager();
	int getmodelCount();
	Object_model* getModel(int);
	void addModel(int);


private:
	int objectCount = 0;
	Object_model** modelArr;




};

#endif