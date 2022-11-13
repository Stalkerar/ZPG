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
	lh_manager = new Light_manager();
	tx_manager = new Texture_manager();

	Texture* tex2 = new Texture("textures/wooden_fence.png");
	Texture* tex1 = new Texture("textures/grass.png");
	renderer = new Renderer();
	camera = new Camera(glm::vec3(-0.4f, 0.3f, 6.0f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f),nullptr);
	pointLight = new PointLight(glm::vec3(-5.f, 4.f, 6.f), glm::vec3(0.06f, 0.06f, 0.06f), glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(1.f, 1.f, 1.f), 1.0f, 0.09f, 0.032f);
	PointLight* p1 = new PointLight(glm::vec3(5.f, 4.f, 6.f), glm::vec3(0.06f, 0.06f, 1.06f), glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(0.06f, 0.06f, 1.06f), 0.5f, 0.7f, 0.032f);
	PointLight* p2 = new PointLight(glm::vec3(5.f, 4.f, -6.f), glm::vec3(1.6f, 0.06f, 0.06f), glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(1.6f, 0.06f, 0.06f), 1.f, 0.9f, 0.1f);
	DirectLight* d1 = new DirectLight(glm::vec3(1.f,4.f,25.f), glm::vec3(0.05f, 0.05f, 0.08f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.5f, 0.5f, 0.5f));
	SpotLight* s1 = new SpotLight(glm::vec3(-0.4f, 0.3f, 6.0f), glm::vec3(-0.4f, 0.3f, 6.0f), glm::vec3(0.05f, 0.05f, 0.08f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.6f, 1.06f, 0.06f), 1.0f, 0.09f, 0.032f, glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(35.0f)));


	Ttranslate* tmove = new Ttranslate();
	Ttranslate* move = new Ttranslate();
	Tscale* scale = new Tscale();

	
	sh_manager->addShader("shaders/vs.shader", "shaders/fs_wong.shader",false,true);
	sh_manager->addShader("shaders/vs.shader", "shaders/fs_const.shader", true, false);
	sh_manager->addShader("shaders/vs.shader", "shaders/fs_multipleLight.shader", false, true);

	lh_manager->addPointLight(pointLight);
	lh_manager->addPointLight(p1);
	lh_manager->addPointLight(p2);
	lh_manager->setDirectLight(d1);
	lh_manager->setSpotLight(s1);

	camera->Attach(sh_manager->getShaderProgram(2));
	camera->Attach(sh_manager->getShaderProgram(1));

	//Object* object_1 = new Object(sh_manager->getShaderProgram(0));
	Object* floor = new Object(sh_manager->getShaderProgram(2),tex1);
	Object* floor2 = new Object(sh_manager->getShaderProgram(2),tex2);


	ob_manager->addModel(1); // 1 -> model sphere
	ob_manager->addModel(7);

	scale->setScale(glm::vec3(10.0f, 10.0f, 10.0f));
	tmove->setTranslation(glm::vec3(4.f, 1.5f, 4.f));
	move->setTranslation(glm::vec3(1.f, 0.f, 0.f));
	
	//object_1->addTransformation(tmove);


	floor->addTransformation(move);
	floor->addTransformation(scale);
	floor2->addTransformation(tmove);
	floor2->addTransformation(scale);
		
	
	//object_2->addTransformation(scale);
	//object_1->setModalMatrix();
	floor2->setModalMatrix();
	floor->setModalMatrix();






	//ob_manager->getModel(0)->addObject(object_1);
	//ob_manager->getModel(0)->addObject(object_2);
	ob_manager->getModel(1)->addObject(floor);
	ob_manager->getModel(1)->addObject(floor2);
	scene = new Scene(window, sh_manager,lh_manager, tx_manager);
	scene->setCamera(camera);
	scene->setLight(pointLight);




	
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

	this->renderer->init(this->ob_manager, this->scene);
	
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