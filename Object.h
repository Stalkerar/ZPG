#pragma once
#ifndef _OBJECT
#define _OBJECT

#include <stdio.h>
#include <iostream>
//#include "drawobj.h"
#include"Obj_model.h"
#include"Shader_manager.h"
#include "Shader.h"

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





class Object
{
public:

	Object();
	void setTeselation(glm::vec3);
	unsigned int inicialize(unsigned int);
	glm::mat4 getMatrix();
	~Object();
private:
	glm::mat4 Model = glm::mat4(1.0f);;

};

#endif // !1