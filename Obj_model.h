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

private:

	GLuint VBO = 0;
	GLuint VAO = 0;
};



#endif // !1

