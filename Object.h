#pragma once
#ifndef _OBJECT
#define _OBJECT


//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "ShaderProgram.h"
//#include "Transformation.h"
#include "Trotate.h"
#include "Ttranslate.h"
#include "Texture.h"


class Object
{
public:

	Object(ShaderProgram*,Texture*);
	void addTransformation(Transformation* t);
	glm::mat4 getMatrix();
	void setModalMatrix();
	ShaderProgram* getShaderProgram();
	Texture* getTexture();


private:
	vector <Transformation*> transformations;
	glm::mat4 Model = glm::mat4(1.0f);
	ShaderProgram* myShader;
	Texture* texture;
	//virtual glm::mat4 getMatrix() = 0;
	//virtual ShaderProgram* getShaderProgram() = 0;
	//virtual glm::mat4 getModalMatrix() = 0;
	//~Object();


};

#endif 