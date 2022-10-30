#include "Renderer.h"

Renderer::Renderer()
{

}








void Renderer::draw(Object_manager* in_ob,Scene* sp)
{
	

	this->modelCount = in_ob->getmodelCount();


	for (int j = 0; j < this->modelCount; j++)
	{
		this->objCount = in_ob->getModel(j)->getCount();
		for (int i = 0; i < this->objCount; i++)
		{

			sp->updateUniforms(in_ob->getModel(j)->getObject(i));
			glBindVertexArray(in_ob->getModel(j)->get_VAO());
			glDrawArrays(GL_TRIANGLES, 0, in_ob->getModel(j)->getDrawCount());

		}

	}



}
