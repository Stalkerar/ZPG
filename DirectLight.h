#pragma once
#ifndef _DIRECTLIGHT
#define _DIRECTLIGHT

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "Light.h"

class DirectLight: public Light
{
public:
	DirectLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	glm::vec3 get_direction();

private:
	glm::vec3 direction;

};


#endif // !