#include "Renderer.h"

Renderer::Renderer()
{

}



void Renderer::draw(GLuint va,Object* o,unsigned int sm)
{
	o->inicialize(sm);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(sm);
	glBindVertexArray(va);
	glDrawArrays(GL_TRIANGLES, 0, 3);

}
