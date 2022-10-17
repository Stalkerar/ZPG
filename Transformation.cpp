#include "Transformation.h"



glm::mat4 Transformation::getMatrix()
{
	return Model;
}



void Transformation::addTransformation(Object* t)
{
	this->transformations.push_back(t);
}

void Transformation::setModalMatrix()
{
	
	glm::mat4 buffer = this->Model;

	for (int i = 0; i < this->transformations.size(); i++)
	{
		buffer *= this->transformations[i]->getMatrix();
	}
	this->Model = buffer;
}