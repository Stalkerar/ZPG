#include "Texture_manager.h"

Texture_manager::Texture_manager()
{

}

GLint Texture_manager::getImage()
{
	return this->image;
}

void Texture_manager::initexture()
{
	
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, 0);
	this->image = SOIL_load_OGL_texture("textures/wooden_fence.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (image == NULL) {
		std::cout << "An error occurred while loading image." << std::endl;
		exit(EXIT_FAILURE);
	}
	//glGenTextures(1, &this->image);
	glActiveTexture(GL_TEXTURE0 + this->image);
	glBindTexture(GL_TEXTURE_2D, this->image);


	

}