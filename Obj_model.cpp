#include "Obj_model.h"
#include "models/sphere.h"
#include "models/bushes.h"
#include "models/tree.h"
#include "models/gift.h"
#include "models/suzi_flat.h"
#include "models/plain.h"


Object_model::Object_model(int type)
{
	this->drawCount = (sizeof(tree) / sizeof(float))/6;
	switch (type) {
		case 1:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);
			this->drawCount = (sizeof(sphere) / sizeof(float)) / 6;
			break;
		case 2:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(plain), plain, GL_STATIC_DRAW);
			this->drawCount = (sizeof(plain) / sizeof(float)) / 6;
			break;
		case 3:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(tree), tree, GL_STATIC_DRAW);
			this->drawCount = (sizeof(tree) / sizeof(float)) / 6;
			break;
		case 4:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(gift), gift, GL_STATIC_DRAW);
			this->drawCount = (sizeof(gift) / sizeof(float)) / 6;
			break;
		case 5:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(suzi_flat), suzi_flat, GL_STATIC_DRAW);
			this->drawCount = (sizeof(suzi_flat) / sizeof(float)) / 6;
			break;
		case 6:
			glGenBuffers(1, &VBO); // generate the VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(plain1), plain1, GL_STATIC_DRAW);
			this->drawCount = (sizeof(plain1) / sizeof(float)) / 6;
			break;
		default:
			cerr << "Error model choise" << endl;
			break;


	}

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	
	
	

}

Object_model::~Object_model()
{
}

void Object_model::addObject(Object* in)
{
	this->objects.push_back(in);
	this->objectCount++;
}

int Object_model::getCount()
{
	return this->objectCount;
}

Object* Object_model::getObject(int idx)
{
	return this->objects[idx];
}


GLsizei Object_model::getDrawCount()
{
	return this->drawCount;
}


void Object_model::draw_object()
{

	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, this->drawCount);
	

}

void Object_model::set_VAO(GLuint input)
{
	VAO = input;

}

GLuint Object_model::get_VAO()
{
	return VAO;
}

void Object_model::inicialize()
{
	//2880
	//glDrawArrays(GL_TRIANGLES, 0, 2880);

}