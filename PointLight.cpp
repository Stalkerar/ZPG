#include "PointLight.h"

PointLight::PointLight(glm::vec3 in_positon, glm::vec3 in_ambient, glm::vec3 in_diffuse, glm::vec3 in_specular,float in_constat,float in_linear,float in_quadratic) : DirectLight(in_positon, in_ambient, in_diffuse, in_specular)
{
	this->position = in_positon;
	this->constant = in_constat;
	this->quadratic = in_quadratic;
	this->linear = in_linear;

}

glm::vec3 PointLight::get_postion()
{
	return this->position;
}

float PointLight::get_constant()
{
	return this->constant;
}

float PointLight::get_quadratic()
{
	return this->quadratic;
}

float PointLight::get_linear()
{
	return this->linear;
}