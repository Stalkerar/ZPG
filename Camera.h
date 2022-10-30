#pragma once
#ifndef _CAMERA
#define _CAMERA
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
#include <vector>
#include "ShaderProgram.h"

enum direction {FORWARD = 0, BACK,LEFT,RIGHT};

class ShaderProgram;
class Camera
{
public:
	Camera(glm::vec3, glm::vec3, glm::vec3, ShaderProgram*);
	glm::mat4 getCamera();
	glm::mat4 getProjection();
	const glm::vec3 getPosition();
	void updateInput(const float&, const int, const double&, const double&);
	void updateMouseInput(const float&, const double&, const double&);
	void updateKeyboardInput(const float&, const int);

private:
	GLfloat movementSpeed;
	GLfloat sensitivity;
	ShaderProgram* m_shader;
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	void updateCameraVectors();
	glm::vec3 position;
	glm::vec3 front = glm::vec3(1.0f);
	glm::vec3 up = glm::vec3(1.0f);
	glm::vec3 right = glm::vec3(1.0f);
	glm::vec3 worldUp;
	GLfloat pitch;
	GLfloat yaw;
	GLfloat roll;
};

#endif