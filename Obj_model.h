#pragma once
#ifndef _myObj
#define _myObj
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  


class Object_model
{
public:


	Object_model();
	~Object_model();
	void draw_object();
	void set_VAO(GLuint);
	GLuint get_VAO();
	void inicialize(GLuint, int);

private:
	int neco = 0;
	GLuint VBO = 0;
	GLuint VAO = 0;
	GLuint VAO_2 = 0;
};



#endif // !1
#pragma once
