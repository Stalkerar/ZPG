#include "Application.h"



GLFWwindow* Application::getWindow()
{
	return this->window;
}





static void error_callback(int error, const char* description) { fputs(description, stderr); }



void Application::inicialization()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	window = glfwCreateWindow(1280, 720, "ZPG", NULL, NULL);
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
}



Application::Application(int option)
{
	this->inicialization();
	sh_manager = new Shader_Manager();
	ob_manager = new Object_manager();
	renderer = new Renderer();
	camera = new Camera(glm::vec3(-0.4f, 0.3f, 6.0f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f),nullptr);
	Ttranslate* tmove = new Ttranslate(); 

	if (option == 1)
	{
		Transformation* object_1 = new Transformation();
		Transformation* object_2 = new Transformation();
		Transformation* object_3 = new Transformation();
		Transformation* object_4 = new Transformation();

		sh_manager->addShader("shaders/vs.shader", "shaders/fs_wong.shader");
		ob_manager->addModel(1); // 1 -> model sphere

		tmove->setTranslation(glm::vec3(1.5f, -1.5f, 0.f));
		object_1->addTransformation(tmove);
		object_1->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_1);

		tmove->setTranslation(glm::vec3(1.5f, 1.5f, 0.f));
		object_2->addTransformation(tmove);
		object_2->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_2);

		tmove->setTranslation(glm::vec3(-1.5f, 1.5f, 0.f));
		object_3->addTransformation(tmove);
		object_3->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_3);

		tmove->setTranslation(glm::vec3(-1.5f, -1.5f, 0.f));
		object_4->addTransformation(tmove);
		object_4->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_4);


	}
	if (option == 2)
	{
		Transformation* object_1 = new Transformation();
		sh_manager->addShader("shaders/vs.shader", "shaders/fs.shader");
		ob_manager->addModel(1); // 1 -> model sphere
		tmove->setTranslation(glm::vec3(1.f, 0.f, 1.f));
		object_1->addTransformation(tmove);
		object_1->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_1);


	}
	if (option == 3)
	{
		Transformation* object_1 = new Transformation();
		sh_manager->addShader("shaders/vs.shader", "shaders/fs_nocheck.shader");
		ob_manager->addModel(1); // 1 -> model sphere
		tmove->setTranslation(glm::vec3(1.f, 0.f, 1.f));
		object_1->addTransformation(tmove);
		object_1->setModalMatrix();
		ob_manager->getModel(0)->addObject(object_1);

	}
	if (option == 4)
	{
		sh_manager->addShader("shaders/vs.shader", "shaders/fs_wong.shader");
		ob_manager->addModel(1); // 1 -> model sphere
		ob_manager->addModel(2);
		ob_manager->addModel(3);
		ob_manager->addModel(4);
		ob_manager->addModel(5);
		ob_manager->addModel(6);
		
		
		for (int i = 0 ; i < ob_manager->getmodelCount(); i++)
		{
			
			for (int j = 0; j < 21; j++)
			{
				Transformation* object = new Transformation();
				Ttranslate* move = new Ttranslate();
				float rx = 10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (15 - (-15))));
				float ry = 10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (15 - (-15))));

				move->setTranslation(glm::vec3(rx, 0, ry));
				object->addTransformation(move);
				object->setModalMatrix();

				ob_manager->getModel(i)->addObject(object);
				
			}

		}

		





	}


	scene = new Scene(window, sh_manager);
	scene->setCamera(camera);

}


Application::~Application()
{
	delete(this->camera);
	delete(this->sh_manager);
	delete(this->ob_manager);
	delete(this->scene);
}

void Application::run_scene()
{
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	    
		this->scene->update();
		renderer->draw(this->ob_manager, this->scene);
		
		
		glfwSwapBuffers(window);
		glFlush();

		glBindVertexArray(0);
		glUseProgram(0);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}