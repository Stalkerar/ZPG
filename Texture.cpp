#include "Texture.h"

Texture::Texture(const char* filename)
{
	this->id = SOIL_load_OGL_texture(filename, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (id == NULL) {
		std::cout << "An error occurred while loading image." << std::endl;
		exit(EXIT_FAILURE);
	}
}

GLint Texture::getId()
{
	return this->id;
}

void Texture::bind(const GLint texture_unit)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(GL_TEXTURE_2D, this->id);
}


void Texture::unbind()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}