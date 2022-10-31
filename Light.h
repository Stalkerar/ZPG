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
	Light(float, glm::vec3);


private:
	float intensity;
	glm::vec3 color;



};


#endif // !