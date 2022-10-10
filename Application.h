#pragma once
#ifndef _APPLICATION
#define _APPLICATION

#include <stdio.h>
#include <iostream>
//#include "drawobj.h"
#include"Obj_model.h"
#include"Shader_manager.h"
#include "Shader.h"

using namespace std;

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  


//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  

#include <stdlib.h>
#include "Object.h"
#include "Renderer.h"


class Application
{
public:
	void cursor_pos_callback(GLFWwindow* , double , double );
	void run_scene();
	void add_Object(Object*);
	Application();
	~Application();
	Object* get_Object(int);


private:
	GLFWwindow* window;
	Object_model* drawModel;
	Shader_Manager* sh_manager;
	Object_model* drawModel_2;
	Object** objects_arr;
	Renderer* renderer;
	int obj_indx = 0;






};
#endif 
