#pragma once
#ifndef _TEXTURE_MANAGER
#define _TEXTURE_MANAGER

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
#include <vector>
#include <SOIL2/SOIL2.h>
#include "ShaderProgram.h"


class Texture_manager
{
public:
	Texture_manager();
	void initexture();
	void addTexture(int);
	GLint getImage();

private:
	
	GLuint image = 0;



};

#endif