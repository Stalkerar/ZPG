#pragma once
#ifndef _LIGHT_MANAGER
#define _LIGHT_MANAGER

#include <stdio.h>
#include <iostream>
//#include "drawobj.h"


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
//Include the standard C++ headers  

#include <stdlib.h>
#include "Light.h"
#include "PointLight.h"
#include "DirectLight.h"
#include "SpotLight.h"

class Light_manager
{
public:
	Light_manager();
	int getLightCount();
	PointLight* getPointLight(int);
	void addPointLight(PointLight*);
	void setDirectLight(DirectLight*);
	DirectLight* getDirectLight();
	void setSpotLight(SpotLight*);
	SpotLight* getSpotLight();


private:
	int LightCount = 0;
	vector<PointLight*> plights;
	DirectLight* dirLight;
	SpotLight* spotLight;



};

#endif