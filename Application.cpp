#include "Application.h"



GLFWwindow* Application::getWindow()
{
	return this->window;
}





static void error_callback(int error, const char* description) { fputs(description, stderr); }


Application::Application()
{
	renderer = new Renderer();
	camera = new Camera(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f),nullptr);
	Trotate*  trotation = new Trotate();
	Trotate* trotation_2 = new Trotate();
	Ttranslate* tmove = new Ttranslate(); 
	Ttranslate* tmove2 = new Ttranslate();

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
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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



	
	sh_manager = new Shader_Manager();
	
	
	trotation->setRotation(45, glm::vec3(0.3f));
	trotation_2->setRotation(0.14, glm::vec3(0.7f));
	tmove->setTranslation(glm::vec3(1.5f, 2.f, 1.5f));
	Transformation* object_1 = new Transformation();
	Transformation* object_2 = new Transformation();
	Transformation* object_3 = new Transformation();
	Transformation* object_4 = new Transformation();

	object_2->addTransformation(tmove);
	tmove2->setTranslation(glm::vec3(1.5f, -2.f, 1.5f));
	object_3->addTransformation(tmove2);


	object_1->setModalMatrix();
	object_2->setModalMatrix();
	object_3->setModalMatrix();

	tmove2->setTranslation(glm::vec3(-1.5f, -2.f, 1.5f));
	object_4->addTransformation(tmove2);
	object_4->setModalMatrix();
	

	sh_manager->addShader("shaders/vs.shader", "shaders/fs.shader", object_1);
	//sh_manager->addShader("shaders/vs.shader", "shaders/fs.shader", object_2);

	drawModel = new Object_model();
	drawModel->inicialize();

	sh_manager->getShaderProgram(0)->setCamera(camera);


	scene = new Scene(window, sh_manager);
	scene->setCamera(camera);
	scene->addObject(object_1);
	scene->addObject(object_2);
	scene->addObject(object_3);
	scene->addObject(object_4);
}



void Application::run_scene()
{
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		
		// update other events like input handling
		this->scene->update();
	    
		renderer->draw(drawModel->get_VAO(), this->scene);
		

		

		//glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
		glFlush();

		glBindVertexArray(0);
		glUseProgram(0);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}