#pragma once
#ifndef _Shader_m
#define _Shader_m
#include <cstdlib>

class Shader_Manager
{
public:
	Shader_Manager(const char*);
	~Shader_Manager();
private:
	int id;
	const char* shader;

};

#endif // !1
