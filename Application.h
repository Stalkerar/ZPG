#pragma once
#ifndef _APPLICATION
#define _APPLICATION

#include <stdio.h>
#include <iostream>


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
#include"Obj_model.h"
#include"Shader_manager.h"
#include "Shader.h"
#include "Object.h"
#include "Renderer.h"
#include "Transformation.h"
#include "Trotate.h"
#include "Camera.h"
#include "Scene.h"
#include "Ttranslate.h"
#include "Object_manager.h"

class Application
{
public:
	static void cursor_pos_callback(GLFWwindow* , double , double );
	void run_scene();
	Application(int);
	~Application();
	GLFWwindow* getWindow();
	void inicialization();


private:
	GLFWwindow* window;
	Shader_Manager* sh_manager;
	Object_manager* ob_manager;
	Renderer* renderer;
	Camera* camera;
	Scene* scene;
	






};
#endif 
