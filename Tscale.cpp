#include "Tscale.h"


void Tscale::setScale(glm::vec3 in_vec)
{
	this->Model = glm::scale(glm::mat4(1.0f), in_vec);
}

glm::mat4 Tscale::getMatrix()
{
	return this->Model;
}