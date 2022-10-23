#pragma once
#ifndef _SHADERPROGRAM
#define _SHADERPROGRAM
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include"Shader.h"
#include"Object.h"
#include "Camera.h"


class Camera;
class ShaderProgram
{
public:
	ShaderProgram(const std::string& , const std::string& , Object*);
	ShaderProgram(const std::string&, const std::string&, Camera*);

	~ShaderProgram();
	void setCamera(Camera*); //PLACEHOLDER
	GLuint loadShaderProgram(const std::string&, const std::string&);
	unsigned int sendModelShader();
	unsigned int sendViewShader();
	unsigned int sendProjectionShader();
	void setVec3f(glm::vec3, const GLchar* nme);
	void setVec4f(glm::vec4 , const GLchar* );
	void use();
	void unuse();
	unsigned int sendScene();
	void setMat4fv(glm::mat4 , const GLchar* );
	Object* getObject();
private:
	GLuint programId , vs, fs;
	Object* object;
	Camera* camera;



};

#endif // !_SHADERPROGRAM