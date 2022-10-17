#include "Trotate.h"


void Trotate::setRotation(float angle, glm::vec3 in_vec)
{
	this->Model = glm::rotate(glm::mat4(1.0f), angle, in_vec);
}

glm::mat4 Trotate::getMatrix()
{
	return this->Model;
}