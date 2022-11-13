#include "DirectLight.h"

DirectLight::DirectLight(glm::vec3 in_direction, glm::vec3 in_ambient, glm::vec3 in_diffuse, glm::vec3 in_specular) : Light(in_ambient, in_diffuse, in_specular)
{
	
	this->direction = in_direction;
}


glm::vec3 DirectLight::get_direction()
{
	return this->direction;
}
