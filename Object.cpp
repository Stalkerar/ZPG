#include "Object.h"


Object::Object()
{

	float angle = 0.80;


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
	


	

}



void Object::setTeselation(glm::vec3 input)
{
	Model = glm::translate(glm::mat4(1.0f), input);
}




glm::mat4  Object::getMatrix()
{
	return Model;
}

//TO DO SHADER MANAGER // UDELAT MOZNO TRANFORMATION MANAGER
unsigned int Object::inicialize(unsigned int programID)
{
	GLint idModelTransform = glGetUniformLocation(programID, "modelMatrix");// DAT DO SHADERPROGRAM ?
	if (idModelTransform == -1)
	{
		cerr << "Unable to get uniform matrix location" << endl;
		return -1;
	}
	glUseProgram(programID);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &Model[0][0]);

	return 0;
}