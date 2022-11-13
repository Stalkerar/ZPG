#include "Scene.h"


Scene::Scene(GLFWwindow* in, Shader_Manager* insm,Light_manager* inlm, Texture_manager* intxt)
{
	this->window = in;
	this->shaderManager = insm;
	this->lightManager = inlm;
	this->textureManager = intxt;
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

void Scene::setLight(PointLight* in)
{
	this->pointlight = in;
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

	this->mouseOffsetX = this->mouseX - this->lastMouseX;
	this->mouseOffsetY = this->lastMouseY - this->mouseY;


	this->lastMouseX = this->mouseX;
	this->lastMouseY = this->mouseY;

	
}


void Scene::updateKeyboardInput()
{
	
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->window, GLFW_TRUE);
	}

	
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
/*
void Scene::addObject(Object* in)
{
	this->objects[this->objectCount] = in;
	this->objectCount++;

}
*/

int Scene::getCountObject()
{
	return this->objectCount;
}


void Scene::initUniforms(Object* obj_in)
{


	this->ViewMatrix = this->camera->getCamera();
	this->camPosition = this->camera->getPosition();
	this->textureManager->initexture();

	/*
	*/

	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(0)->get_postion(), "pointlights[0].position");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(0)->get_ambient(), "pointlights[0].ambient");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(0)->get_diffuse(), "pointlights[0].diffuse");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(0)->get_specular(), "pointlights[0].specular");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(0)->get_constant(), "pointlights[0].constant");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(0)->get_linear(), "pointlights[0].linearv");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(0)->get_quadratic(), "pointlights[0].quadratic");

	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(1)->get_postion(), "pointlights[1].position");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(1)->get_ambient(), "pointlights[1].ambient");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(1)->get_diffuse(), "pointlights[1].diffuse");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(1)->get_specular(), "pointlights[1].specular");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(1)->get_constant(), "pointlights[1].constant");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(1)->get_linear(), "pointlights[1].linearv");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(1)->get_quadratic(), "pointlights[1].quadratic");

	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(2)->get_postion(), "pointlights[2].position");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(2)->get_ambient(), "pointlights[2].ambient");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(2)->get_diffuse(), "pointlights[2].diffuse");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getPointLight(2)->get_specular(), "pointlights[2].specular");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(2)->get_constant(), "pointlights[2].constant");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(2)->get_linear(), "pointlights[2].linearv");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getPointLight(2)->get_quadratic(), "pointlights[2].quadratic");


	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getDirectLight()->get_direction(), "dirLight.direction");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getDirectLight()->get_ambient(), "dirLight.ambient");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getDirectLight()->get_diffuse(), "dirLight.diffuse");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getDirectLight()->get_specular(), "dirLight.specular");

	shaderManager->getShaderProgram(2)->setVec3f(this->camera->getFront(), "spotLight.direction");
	shaderManager->getShaderProgram(2)->setVec3f(this->camPosition, "spotLight.position");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getSpotLight()->get_ambient(), "spotLight.ambient");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getSpotLight()->get_diffuse(), "spotLight.diffuse");
	shaderManager->getShaderProgram(2)->setVec3f(this->lightManager->getSpotLight()->get_specular(), "spotLight.specular");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getSpotLight()->get_constant(), "spotLight.constant");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getSpotLight()->get_linear(), "spotLight.linearv");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getSpotLight()->get_quadratic(), "spotLight.quadratic");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getSpotLight()->getcutOff(), "spotLight.cutOff");
	shaderManager->getShaderProgram(2)->setFloat(this->lightManager->getSpotLight()->getouterCutOff(), "spotLight.outerCutOff");


	obj_in->getShaderProgram()->setMat4fv(this->ViewMatrix, "viewMatrix");
	//obj_in->getShaderProgram()->setMat4fv(obj_in->getMatrix(), "modelMatrix");
	if (obj_in->getShaderProgram()->getStatus() == "dynamic")
	{
		obj_in->getShaderProgram()->setVec3f(glm::vec3(0.0f, 0.0f, 0.0f), "lightPosition");//ANO
		obj_in->getShaderProgram()->setVec3f(this->camera->getPosition(), "posCamera"); //NE POPTAT
	}
	if (obj_in->getShaderProgram()->getStatus() == "special")
	{
		obj_in->getShaderProgram()->setVec3f(glm::vec3(0.0f, 0.0f, 0.0f), "lightPosition");//ANO
	}

	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);


	this->ProjectionMatrix = glm::perspective(
		glm::radians(this->fov),
		static_cast<float>(this->framebufferWidth) / this->framebufferHeight,
		this->nearPlane,
		this->farPlane
	);

	shaderManager->getShaderProgram(2)->setInteger(this->textureManager->getImage(), "textureUnitID");
	
	obj_in->getShaderProgram()->setMat4fv(this->ProjectionMatrix, "projectionMatrix");
}

void Scene::updateUniforms(Object* obj_in)
{
	
	this->ViewMatrix = this->camera->getCamera();
	this->camPosition = this->camera->getPosition();

	shaderManager->getShaderProgram(2)->setVec3f(this->camera->getFront(), "spotLight.direction");
	shaderManager->getShaderProgram(2)->setVec3f(this->camPosition, "spotLight.position");
	shaderManager->getShaderProgram(2)->setInteger(this->textureManager->getImage(), "textureUnitID");








	obj_in->getShaderProgram()->setMat4fv(this->ViewMatrix, "viewMatrix");
	obj_in->getShaderProgram()->setMat4fv(obj_in->getMatrix(), "modelMatrix");
	if (obj_in->getShaderProgram()->getStatus() == "dynamic")
	{
		obj_in->getShaderProgram()->setVec3f(glm::vec3(0.0f, 0.0f, 0.0f), "lightPosition");//ANO
		obj_in->getShaderProgram()->setVec3f(this->camera->getPosition(), "posCamera"); //NE POPTAT
	}
	if (obj_in->getShaderProgram()->getStatus() == "special")
	{
		obj_in->getShaderProgram()->setVec3f(glm::vec3(0.0f, 0.0f, 0.0f), "lightPosition");//ANO
	}

	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);

	this->ProjectionMatrix = glm::perspective(
		glm::radians(this->fov),
		static_cast<float>(this->framebufferWidth) / this->framebufferHeight,
		this->nearPlane,
		this->farPlane
	);

	obj_in->getShaderProgram()->setMat4fv(this->ProjectionMatrix, "projectionMatrix");

	


	//this->shaderManager->getShaderProgram(0)->setBool(true, "useBlinn");



	


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