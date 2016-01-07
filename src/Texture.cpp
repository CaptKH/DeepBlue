#include <Texture.h>
#include <fstream>
#include <SOIL\SOIL.h>

Texture::Texture(std::string fileName, ImageFileType t)
{
	imageType = t;
		
	std::string filePath = "assets/textures/" + fileName;
	unsigned char* image = SOIL_load_image(filePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture(void)
{
}

GLuint Texture::GetTexture(void)
{
	return texture;
}