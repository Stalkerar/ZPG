#include "Renderer.h"

Renderer::Renderer()
{

}








void Renderer::draw(GLuint va,Scene* sp)
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	//sp->sendModelShader();
	/*
	sp->sendViewShader();
	sp->sendProjectionShader();
	*/
	this->objCount = sp->getCountObject();

	for (int i = 0; i < this->objCount; i++)
	{
		sp->updateUniforms(i);
		glBindVertexArray(va);
		glDrawArrays(GL_TRIANGLES, 0, 2880);

	}

	
	//glUseProgram(0);

	



}
