#ifndef __TEXTURE
#define __TEXTURE

#include <string>
#include <GLEW\glew.h>

enum ImageFileType { PNG = 0, JPG = 1 };

class Texture
{
private:
	GLuint texture;
	int width;
	int height;
	ImageFileType imageType;

public:
	Texture(std::string fileName, ImageFileType t);
	~Texture(void);
	
	GLuint GetTexture(void);
};

#endif