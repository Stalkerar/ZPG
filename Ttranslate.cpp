#include "Ttranslate.h"


void Ttranslate::setTranslation( glm::vec3 in_vec)
{
	this->Model = glm::translate(glm::mat4(1.0f), in_vec);
}

glm::mat4 Ttranslate::getMatrix()
{
	return this->Model;
}