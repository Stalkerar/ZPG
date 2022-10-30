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
#include "IObserver.h"

class Camera;
class ShaderProgram: public IObserver
{
public:
	ShaderProgram(const std::string& , const std::string&);
	ShaderProgram(const std::string&, const std::string&, Camera*);

	~ShaderProgram();
	void setCamera(Camera*); //PLACEHOLDER
	GLuint loadShaderProgram(const std::string&, const std::string&);
	unsigned int sendModelShader();
	unsigned int sendViewShader();
	unsigned int sendProjectionShader();
	void setVec3f(glm::vec3, const GLchar* );
	void setVec4f(glm::vec4 , const GLchar* );
	void setBool(bool, const GLchar*);
	void use();
	void unuse();
	unsigned int sendScene();
	void setMat4fv(glm::mat4 , const GLchar* );
	void Update(const std::string& );

private:
	GLuint programId , vs, fs;
	Camera* camera;



};

#endif // !_SHADERPROGRAM