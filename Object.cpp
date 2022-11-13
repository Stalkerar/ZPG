#include "Object.h"



Object::Object(ShaderProgram* in_sh,Texture* in_tx)
{
	this->myShader = in_sh;
	this->texture = in_tx;
}

Texture* Object::getTexture()
{
	return this->texture;
}

ShaderProgram* Object::getShaderProgram()
{
	return this->myShader;
}


glm::mat4 Object::getMatrix()
{
	return Model;
}



void Object::addTransformation(Transformation* t)
{
	this->transformations.push_back(t);
}

void Object::setModalMatrix()
{

	glm::mat4 buffer = this->Model;

	for (int i = 0; i < this->transformations.size(); i++)
	{
		buffer *= this->transformations[i]->getMatrix();
	}
	this->Model = buffer;
}



	/*
	glm::vec4 Position = glm::vec4(glm::vec3(0.0f), 1.0f);
	glm::mat4 Model = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f));
	glm::vec4 Transformed = Model * Position;
	*/
	

	//Model = glm::mat4(1.0f);
	//Model = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(2.0f, 1.0f, 1.0f));
	//Model = glm::rotate(Model, angle, glm::vec3(1.0f, 4.0f, 3.0f));
	//Model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0));
	//Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.9f));
	


	




//glm::mat4 Object::getMatrix(){ return glm::mat4(1.0f); }
//glm::mat4 Object::getModalMatrix() { return glm::mat4(1.0f); }
