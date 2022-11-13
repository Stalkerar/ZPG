#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 position, glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic, float cutOff, float outerCutOff) : PointLight(position, ambient, diffuse, specular, constant, linear, quadratic)
{
	this->direction = direction;
	this->cutOff = cutOff;
	this->outerCutOff = outerCutOff;
}

glm::vec3 SpotLight::getDirection()
{
	return this->direction;
}

float SpotLight::getcutOff()
{
	return this->cutOff;
}

float SpotLight::getouterCutOff()
{
	return this->outerCutOff;
}