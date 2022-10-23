#include "Obj_model.h"
#include "suzi_flat.h"


Object_model::Object_model()
{
	float positions[] = {
		100.0f, 100.0f, 0.0f, 0.0f, //0
		200.0f, 100.0f, 1.0f, 0.0f, //1
		200.0f, 200.0f, 1.0f, 1.0f, //2
		100.0f, 200.0f, 0.0f, 1.0f	//3
	};

	float points[] = {
			 0.0f, 0.5f, 0.5f,
			 0.5f, 0.5f, 0.0f,
		     0.0f, -0.5f, 0.5f
	};
	
	float points_1[] = {
	  0.0f, 0.0f, -0.5f,
	  -0.5f, 0.0f, 0.0f,
	 -0.5f, -0.5f, 0.5f
	};
	
	
	
	

	//GLuint VAO = 0;
	//glGenVertexArrays(1, &VAO); //generate the VAO



	//glBindVertexArray(VAO); //bind the VAO

	//glBindVertexArray(VAO_2);

	//glEnableVertexAttribArray(0); //enable vertex attributes



	
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(points), (GLvoid*)0);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	

}

Object_model::~Object_model()
{
}

void Object_model::draw_object()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	
	//glBindVertexArray(VAO_2);
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



	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)3);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}