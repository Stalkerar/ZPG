#pragma once
#ifndef _SCENE
#define _SCENE
#include <stdio.h>
#include <iostream>

#include "Camera.h"
#include "Shader_manager.h"

class Scene
{
public:
	void updateMouseInput();
	void updateInput();
	void updateKeyboardInput();
	void setCamera(Camera *);
	Scene(GLFWwindow*,Shader_Manager*);
	void updateUniforms(Object*);
	void runModel();
	void updateDt();
	void update();
	void addObject(Object*);
	Object* getObject(int);
	int getCountObject();

private:
	GLFWwindow* window;
	//const int WINDOW_WIDTH;
	//const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;
	int objectCount = 0;
	//OpenGL Context
	//const int GL_VERSION_MAJOR;
	//const int GL_VERSION_MINOR;

	//Delta time
	float dt;
	float curTime;
	float lastTime;

	//Mouse Input
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	//Camera
	Camera* camera;
	Shader_Manager* shaderManager;
	Object** objects;

	//Matrices
	glm::mat4 ViewMatrix = glm::mat4(1.f);
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;

	glm::mat4 ProjectionMatrix = glm::mat4(1.f);
	float fov;
	float nearPlane;
	float farPlane;

	//Shaders



};






#endif // !
