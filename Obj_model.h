#pragma once
#ifndef _myObj
#define _myObj
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <vector>
#include "Object.h"

class Object_model
{
public:


	Object_model(int);
	~Object_model();
	void draw_object(int);
	void set_VAO(GLuint);
	GLuint get_VAO();
	void inicialize();
	void addObject(Object*);
	int getCount();
	Object* getObject(int);
	GLsizei getDrawCount();
private:
	int objectCount = 0;
	vector <Object*> objects;
	GLuint VBO = 0;
	GLuint VAO = 0;
	GLsizei drawCount = 0;
	
};



#endif // !1

