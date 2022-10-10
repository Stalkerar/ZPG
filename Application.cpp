#include "Application.h"


static void error_callback(int error, const char* description) { fputs(description, stderr); }



// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// Camera matrix
glm::mat4 View = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
);
// Model matrix : an identity matrix (model will be at the origin)
//glm::mat4 Model = glm::mat4(1.0f);
//Model = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));




Application::Application()
{
	objects_arr = new Object*[100];
	renderer = new Renderer();


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "ZPG", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	glewExperimental = GL_TRUE;
	glewInit();


	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);


	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);


	

	//drawModel_2 = new Object_model(0);

	//type 1 -> fragment, type 2 -> vertex
	sh_manager = new Shader_Manager();
	//sh_manager->Load("shaders/vs.shader", "shaders/fs.shader");
	add_Object(new Object());
	add_Object(new Object());
	add_Object(new Object());
	




	drawModel_2 = new Object_model();
	drawModel_2->inicialize(0,0);
	get_Object(this->obj_indx - 3)->setTeselation(glm::vec3(0, 1, 0));
	//get_Object(this->obj_indx - 1)->inicialize(sh_manager->Load("shaders/vs.shader", "shaders/fs.shader"));
	

	drawModel = new Object_model();
	drawModel->inicialize(0, 0);
	//drawModel->set_VAO(5);
	//drawModel->inicialize();
	get_Object(this->obj_indx - 2)->setTeselation(glm::vec3(0, 0, 0));
	//get_Object(this->obj_indx - 2)->inicialize(sh_manager->Load("shaders/vs.shader", "shaders/fs.shader"));
	
	get_Object(this->obj_indx - 1)->setTeselation(glm::vec3(0.6f, 0, 0));




}

void Application::add_Object(Object* input)
{
	this->objects_arr[this->obj_indx] = input;
	this->obj_indx++;

}


Object* Application::get_Object(int idx)
{
	return this->objects_arr[idx];
}



void Application::cursor_pos_callback(GLFWwindow* window, double mouseX, double mouseY) {
    printf("cursor_pos_callback %d, %d; %d, %d\n", (int)mouseX, (int)mouseY);
}

void Application::run_scene()
{
	//unsigned int shader = sh_manager;

	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
/*

		renderer->draw(drawModel->get_VAO(), get_Object(this->obj_indx - 2), shader);
		renderer->draw(drawModel->get_VAO(), get_Object(this->obj_indx - 1), shader);
		renderer->draw(drawModel->get_VAO(), get_Object(this->obj_indx - 3), shader);
	*/	
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}