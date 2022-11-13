#pragma once
#ifndef _SPOTLIGHT
#define _SPOTLIGHT

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "PointLight.h"

class SpotLight : public PointLight
{
public:
	SpotLight(glm::vec3 position, glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic,float cutOff,float outerCutOff);
	glm::vec3 getDirection();
	float getcutOff();
	float getouterCutOff();

private:
	glm::vec3 direction;
	float cutOff;
	float outerCutOff;

};


#endif // !