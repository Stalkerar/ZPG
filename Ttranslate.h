#pragma once
#ifndef _TRANSLATE
#define _TRANSLATE

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


#include <fstream>
#include <iostream>


#include "Transformation.h"

class Ttranslate : public Transformation
{
public:
	void setTranslation(glm::vec3);
	glm::mat4 getMatrix();

private:
	glm::mat4 Model;

};

#endif