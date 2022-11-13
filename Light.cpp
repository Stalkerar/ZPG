#include "Light.h"

glm::vec3 Light::get_ambient()
{
	return this->ambient;
}

glm::vec3 Light::get_specular()
{
	return this->specular;
}

glm::vec3 Light::get_diffuse()
{
	return this->diffuse;
}