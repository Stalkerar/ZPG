#pragma once
#ifndef _LIGHT
#define _LIGHT

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


class Light
{
public:
	Light(glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular) : ambient(_ambient), diffuse(_diffuse), specular(_specular) {};
	glm::vec3 get_ambient();
	glm::vec3 get_diffuse();
	glm::vec3 get_specular();
private:
	
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

};


#endif // !