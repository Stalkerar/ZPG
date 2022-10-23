#include "Scene.h"


Scene::Scene(GLFWwindow* in, Shader_Manager* insm)
{
	this->window = in;
	this->shaderManager = insm;
	this->objects = new Object*[100];

	
	this->framebufferWidth = 640;
	this->framebufferHeight = 480;

	this->camPosition = glm::vec3(0.f, 0.f, 1.f);

	this->lastMouseX = 0.0;
	this->lastMouseY = 0.0;
	this->mouseX = 0.0;
	this->mouseY = 0.0;
	this->mouseOffsetX = 0.0;
	this->mouseOffsetY = 0.0;
	this->firstMouse = true;


	this->fov = 90.f;
	this->nearPlane = 0.1f;
	this->farPlane = 1000.f;
}


void Scene::setCamera(Camera* in)
{
	this->camera = in;
}

void Scene::updateDt()
{
	this->curTime = static_cast<float>(glfwGetTime());
	this->dt = this->curTime - this->lastTime;
	this->lastTime = this->curTime;
}


void Scene::updateMouseInput()
{
	glfwGetCursorPos(this->window, &this->mouseX, &this->mouseY);
	
	if (this->firstMouse)
	{
		this->lastMouseX = this->mouseX;
		this->lastMouseY = this->mouseY;
		this->firstMouse = false;
	}

	//Calc offset
	this->mouseOffsetX = this->mouseX - this->lastMouseX;
	this->mouseOffsetY = this->lastMouseY - this->mouseY;

	//Set last X and Y
	this->lastMouseX = this->mouseX;
	this->lastMouseY = this->mouseY;

	/*
	//Move light
	if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
	{
		this->pointLights[0]->setPosition(this->camera.getPosition());
	}
	*/
}


void Scene::updateKeyboardInput()
{
	//Program
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->window, GLFW_TRUE);
	}

	//Camera
	if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->camera->updateKeyboardInput(this->dt, FORWARD);
	}
	if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->camera->updateKeyboardInput(this->dt, BACK);
	}
	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->camera->updateKeyboardInput(this->dt, LEFT);
	}
	if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->camera->updateKeyboardInput(this->dt, RIGHT);
	}
	if (glfwGetKey(this->window, GLFW_KEY_C) == GLFW_PRESS)
	{
		this->camPosition.y -= 0.05f;
	}
	if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		this->camPosition.y += 0.05f;
	}
}


Object* Scene::getObject(int idx)
{
	return this->objects[idx];
}

void Scene::addObject(Object* in)
{
	this->objects[this->objectCount] = in;
	this->objectCount++;

}

int Scene::getCountObject()
{
	return this->objectCount;
}

void Scene::updateUniforms(int idx)
{
	//Update view matrix (camera)
	this->ViewMatrix = this->camera->getCamera();
	this->camPosition = this->camera->getPosition();
	int size = this->objectCount;


	
	//this->shaders[SHADER_CORE_PROGRAM]->setVec3f(this->camera.getPosition(), "cameraPos");


	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);

	this->ProjectionMatrix = glm::perspective(
		glm::radians(this->fov),
		static_cast<float>(this->framebufferWidth) / this->framebufferHeight,
		this->nearPlane,
		this->farPlane
	);



	this->shaderManager->getShaderProgram(0)->setVec3f(this->camPosition, "lightPosition");
	this->shaderManager->getShaderProgram(0)->setMat4fv(this->getObject(idx)->getMatrix(), "modelMatrix");

	
	this->shaderManager->getShaderProgram(0)->setMat4fv(this->ProjectionMatrix, "projectionMatrix");
	this->shaderManager->getShaderProgram(0)->setMat4fv(this->ViewMatrix, "viewMatrix");


}
void Scene::update()
{
	this->updateDt();
	this->updateInput();

}

void Scene::updateInput()
{
	glfwPollEvents();

	this->updateKeyboardInput();
	this->updateMouseInput();
	this->camera->updateInput(dt, -1, this->mouseOffsetX, this->mouseOffsetY);
}