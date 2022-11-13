#pragma once
#ifndef _POINTLIGHT
#define _POINTLIGHT

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "DirectLight.h"

class PointLight : public DirectLight
{
public:
	PointLight(glm::vec3 position, glm::vec3, glm::vec3, glm::vec3,float constant,float linear,float quadratic);
	glm::vec3 get_postion();
	float get_constant();
	float get_linear();
	float get_quadratic();
	
private:
	glm::vec3 position;
	float constant;
	float linear;
	float quadratic;

};


#endif // !